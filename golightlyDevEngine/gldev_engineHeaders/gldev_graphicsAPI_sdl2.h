#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_initialisationFormForProgram.h"
#include "../gldev_engineHeaders/gldev_error.h"

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_SDL2
namespace gldev {
	class GraphicsAPI_sdl2 {
	public:
		~GraphicsAPI_sdl2();
		gldev::Error setup(InitialisationFormForProgram& initialisationFormForProgram);
	private:
		SDL_Window* window;
		SDL_Renderer* renderer;
	};
}
#endif