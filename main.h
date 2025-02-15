#include <SDL.h>
#include <SDL_ttf.h>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <functional>
#include <vector>

// headers
#include "ext/window/Window.h"
#include "ext/texture/Texture.h"
#include "ext/menu/Menu.h"

using namespace std;
using namespace wdw;
using namespace txt;
using namespace menu;

const int SCREEN_WIDTH = 1080;
const int SCREEN_HEIGHT = 768;

TTF_Font *gFont = NULL;

void closeApp();