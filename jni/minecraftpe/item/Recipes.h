#pragma once
 
#include <vector>
#include <string>
 
#include "ItemInstance.h"
 
class Recipe;
class Tile;
 
class Recipes {
 
public:
  std::vector<Recipe*> recipes;
  
  class Type {
  public:
    Item* item;
    Tile* tile;
    ItemInstance itemInstance; // note that ItemInstance is a 16-byte structure
    char c;
  };
 
  static Recipes* getInstance();
  void addShapedRecipe(ItemInstance const&, std::string const&, std::vector<Recipes::Type> const&);
  void addShapedRecipe(ItemInstance const&, std::string const&, std::string const&, std::vector<Recipes::Type> const&);
  void addShapedRecipe(ItemInstance const&, std::string const&, std::string const&, std::string const&, std::vector<Recipes::Type> const&);
  void addShapedRecipe(ItemInstance const&, std::vector<std::string> const&, std::vector<Recipes::Type> const&);
  
  void addSingleIngredientRecipeItem(ItemInstance const&, ItemInstance const&);
 
};