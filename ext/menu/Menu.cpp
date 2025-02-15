#include "Menu.h"

namespace menu
{
  Menu::Menu(string name)
  {
    menuName = name;
    selectedOption = 0;
    active = true;
  }

  bool Menu::isActive() const
  {
    return active;
  }

  void Menu::setActive(bool active)
  {
    this->active = active;
  }

  void Menu::addOption(const string &text, function<void()> action)
  {
    options.push_back({text, action});
  }

  void Menu::eventHandler(SDL_Event &e)
  {
    if (!active)
      return;

    if (e.type == SDL_KEYDOWN)
    {
      switch (e.key.keysym.sym)
      {
      case SDLK_UP:
        selectedOption = (selectedOption - 1 + options.size()) % options.size();
        break;
      case SDLK_DOWN:
        selectedOption = (selectedOption + 1) % options.size();
        break;
      case SDLK_RETURN:
        if (!options.empty())
        {
          options[selectedOption].action();
        }
        break;
      }
    }
  }

  void Menu::render(SDL_Renderer *renderer, TTF_Font *font)
  {
    if (!active)
      return;

    SDL_Rect rect = {100, 100, 300, 50};
    SDL_Color normalColor = {255, 255, 255};
    SDL_Color selectedColor = {0, 0, 0};

    for (size_t i = 0; i < options.size(); ++i)
    {
      SDL_Color bgColor = (i == selectedOption) ? SDL_Color{0, 0, 0} : SDL_Color{255, 255, 255};
      SDL_Color textColor = (i == selectedOption) ? normalColor : selectedColor;

      SDL_SetRenderDrawColor(renderer, bgColor.r, bgColor.g, bgColor.b, 255);
      SDL_RenderFillRect(renderer, &rect);

      Texture textTexture;
      textTexture.loadFromRenderedText(options[i].text, renderer, font, textColor);
      textTexture.render(rect.x + 10, rect.y + 10, renderer);

      rect.y += 60;
    }
  }
}