#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include <string>
#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_SDL2
namespace gldev {
	struct LoadTextureRequestForm {
		LoadTextureRequestForm(int subTextureNum) {
			this->subTextureNum = subTextureNum;
			this->subTextureID = new int[subTextureNum];
			this->surface = nullptr;
		}
		void clear() {
			if (this->subTextureNum == 0)
				return;
			delete[] this->subTextureID;
			SDL_FreeSurface(surface);
			surface = nullptr;
		}
		int subTextureNum;
		int* subTextureID;
		SDL_Surface* surface;
	};
}
#endif