#ifndef MENU_H
#define MENU_H

#include <SDL.h>
#include <SDL_ttf.h>
#include <vector>
#include <string>
#include <functional>
#include <string>

#include "../texture/Texture.h"

using namespace std;
using namespace txt;

namespace menu
{
  class Menu
  {
  private:
    struct MenuItem
    {
      string text;
      function<void()> action;
    };

    string menuName;

    int selectedOption;
    bool active;

    vector<MenuItem> options;

  public:
    Menu(string name);

    // getters
    bool isActive() const;

    // modifiers
    void setActive(bool active);
    void addOption(const std::string &text, std::function<void()> action);

    // functions
    void eventHandler(SDL_Event &e);
    void render(SDL_Renderer *renderer, TTF_Font *font);
  };
}

#endif