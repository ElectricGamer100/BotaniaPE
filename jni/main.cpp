#include <jni.h>
#include <dlfcn.h>
#include <android/log.h>
#include <stdlib.h>
#include <string>
#include <sstream>
#include <array>

#include "Substrate.h"

#include "minecraftpe/client/MinecraftClient.h"
#include "minecraftpe/client/gui/Gui.h"
#include "minecraftpe/client/renderer/TileTessellator.h"
#include "minecraftpe/item/Item.h"
#include "minecraftpe/item/Recipes.h"
#include "minecraftpe/item/TileItem.h"
#include "minecraftpe/entity/player/Player.h"
#include "minecraftpe/gamemode/GameMode.h"
#include "minecraftpe/tile/Tile.h"
#include "minecraftpe/tile/material/Material.h"
#include "minecraftpe/util/Util.h"

#include "botaniape/RenderLoader.h"
#include "botaniape/renderers/PetalApothecaryRender.h"

#include "botaniape/tile/Puredaisy.h"
#include "botaniape/tile/Livingrock.h"
#include "botaniape/tile/PetalApothecary.h"

#include "botaniape/item/tools/ManasteelPick.h"

using namespace std;

#define LOG_TAG "botaniape"
#define LOGI(...) ((void)__android_log_print(ANDROID_LOG_INFO, LOG_TAG, __VA_ARGS__))

MinecraftClient* client;
Player* player;
bool registered = false;
bool debugMode = !true;

static void (*TileTessellator_tessellateInWorld_real)(TileTessellator*, Tile*, const TilePos&, bool);
static void (*Tile_initTiles_real)();
static void (*GameMode_tick_real)();
static void (*MinecraftClient_onPlayerLoaded_real)(MinecraftClient*, Player*);
static void (*Gui_render_real)(Gui*, float, bool, int, int);
static void (*Item_initItems_real)();

void dm(string const& msg){
	if(debugMode){
		client->getGui()->addMessage("Debug",msg,0);
	}
}

void addMessage(const string& sender, const string& msg, int fadeTicks){
	dm("addMessage");
	client->getGui()->addMessage(sender,msg,fadeTicks);
}

void clientMessage(string const& msg) {
	dm("clientMessage");
	client->getGui()->displayClientMessage(msg);
}

void showPopupMessage(string const& msg) {
	dm("showPopupMessage");
	client->getGui()->showPopupNotice(msg);
}
	
void showTipMessage(string const& msg) {
	dm("showTipMessage");
	client->getGui()->showTipMessage(msg);
}
	
void chatMessage(const string & sender, const std::string & msg) {
	dm("chatMessage");
	client->getGui()->displayChatMessage(sender, msg);
}

static void TileTessellator_tessellateInWorld_hook(TileTessellator* tessellator, Tile* tile, const TilePos& pos, bool b) {
	if(!RenderLoader::load(tile->id, pos, tile, tessellator))
		TileTessellator_tessellateInWorld_real(tessellator, tile, pos, b);
}

void initBotaniaRenders(){
	//I need to make it so the id is linked through a var in my class.
	RenderLoader::loadRender(202, new PetalApothecaryRender());
}

static void Tile_initTiles_hook(){
	Tile_initTiles_real();
	FlowerTile::puredaisy = new Puredaisy(200, "puredaisy", Material::replaceable_plant);
	Livingrock::livingrock = new Livingrock(201, "livingrock", Material::stone);
	PetalApothecary::petalApothecary = new PetalApothecary(202, Material::stone);
	initBotaniaRenders();
}

static void Item_initItems_hook(){
	PickaxeItem::manasteelPick = new ManasteelPick(501);
	Item_initItems_real();
}

static void GameMode_tick_hook(){
	GameMode_tick_real();
	if(player != NULL){
		dm("tick");
	}
}

static void MinecraftClient_onPlayerLoaded_hook(MinecraftClient * mc, Player * p){
	player = p;
	client = mc;
	MinecraftClient_onPlayerLoaded_real(mc, p);
	if(player != NULL){
		dm("player loaded");
		addMessage("§2Botania PE§f","v0.1.0 §4Beta 1",1200);
		addMessage("toString",Util::toString(3) + " Hello world :3",0);
	}
}

static void SurvivalScreen_updateCraftingItem(void* screen, bool idk){
	if(registered){
		return;
	}
	vector<Recipes::Type> ingredients;
	Recipes::Type cobble;
	cobble.c = 'c';
	cobble.item = NULL;
	cobble.tile = Tile::tiles[4];
	ingredients.push_back(cobble);
	
	Recipes::getInstance()->addShapedRecipe(ItemInstance(202, 1, 0), "c c", " c ", "ccc", ingredients);
	//gonna do petals soon
	//Recipes::getInstance()->addShapedRecipe(ItemInstance(202, 1, 0), "cpc", " c ", "ccc", ingredients);
	
	registered = true;
}

static void Gui_render_hook(Gui* gui, float f1, bool b1, int i1, int i2){
	Gui_render_real(gui, f1, b1, i1, i2);
}

string getGameVersionString(void* p){
		return "v0.11.1 alpha"; //soon to be v0.12.1 alpha
}

JNIEXPORT jint JNI_OnLoad(JavaVM* vm, void* reserved) {
	LOGI("Start of JNI");
	dlerror();
	
	void* handle = dlopen("libminecraftpe.so",RTLD_LAZY);
	MSHookFunction(dlsym(handle,"_ZN6Common20getGameVersionStringEv"), (void*)&getGameVersionString);
	MSHookFunction(dlsym(handle,"_ZN23SurvivalInventoryScreen20updateCraftableItemsEb"), (void*)&SurvivalScreen_updateCraftingItem);
	MSHookFunction((void*)&Tile::initTiles, (void*)&Tile_initTiles_hook, (void**)&Tile_initTiles_real);
	MSHookFunction((void*)&GameMode::tick, (void*)&GameMode_tick_hook, (void**)&GameMode_tick_real);
	MSHookFunction((void*)&Gui::render, (void*)&Gui_render_hook, (void**)&Gui_render_real);
	MSHookFunction((void*)&MinecraftClient::onPlayerLoaded, (void*)&MinecraftClient_onPlayerLoaded_hook, (void**)&MinecraftClient_onPlayerLoaded_real);
	MSHookFunction((void*)&Item::initItems, (void*)&Item_initItems_hook, (void**)&Item_initItems_real);
	MSHookFunction((void*)&TileTessellator::tessellateInWorld, (void*)&TileTessellator_tessellateInWorld_hook, (void**)&TileTessellator_tessellateInWorld_real);
	
	const char* error = dlerror();
	if(error) LOGI(error);
	LOGI("End of JNI");
	return JNI_VERSION_1_2;
}
