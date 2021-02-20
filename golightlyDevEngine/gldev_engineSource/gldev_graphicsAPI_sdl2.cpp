#include "../gldev_engineHeaders/gldev_graphicsAPI_sdl2.h"
#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_initialisationFormForProgram.h"
#include "../gldev_engineHeaders/gldev_error.h"

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_SDL2
gldev::GraphicsAPI_sdl2::~GraphicsAPI_sdl2() {
	SDL_DestroyRenderer(this->renderer);
	SDL_DestroyWindow(this->window);
	IMG_Quit();
	SDL_Quit();
}

gldev::Error gldev::GraphicsAPI_sdl2::setup(InitialisationFormForProgram& initialisationFormForProgram) {
	if (SDL_Init(SDL_INIT_VIDEO) < 0) return gldev::Error("couldn't initialize SDL2");
	if (!SDL_SetHint(SDL_HINT_RENDER_SCALE_QUALITY, "1")) return gldev::Error("sdl couldn't enable linear filtering");
	int numDisplays = SDL_GetNumVideoDisplays();
	if (initialisationFormForProgram.minimiseOnFullscreenSingleMonitorAltTab == false || numDisplays > 1)
		SDL_SetHint("SDL_VIDEO_MINIMIZE_ON_FOCUS_LOSS", "0");
	if (initialisationFormForProgram.windowIsFullscreen && initialisationFormForProgram.monitorToFullscreenDisplayTo > 0) {
		SDL_Rect bounds;
		SDL_GetDisplayBounds(initialisationFormForProgram.monitorToFullscreenDisplayTo, &bounds);
		initialisationFormForProgram.windowX = bounds.x;
	}
	Uint32 windowFlags = 0;
	if (initialisationFormForProgram.windowIsFullscreen && initialisationFormForProgram.windowHasInputGrabbed)
		windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP | SDL_WINDOW_INPUT_GRABBED;
	else if (initialisationFormForProgram.windowIsFullscreen)
		windowFlags = SDL_WINDOW_FULLSCREEN_DESKTOP;
	else if (initialisationFormForProgram.windowIsBorderless && initialisationFormForProgram.windowHasInputGrabbed)
		windowFlags = SDL_WINDOW_BORDERLESS | SDL_WINDOW_INPUT_GRABBED;
	else if (initialisationFormForProgram.windowIsBorderless)
		windowFlags = SDL_WINDOW_BORDERLESS;
	else if (initialisationFormForProgram.windowIsResizable && initialisationFormForProgram.windowHasInputGrabbed)
		windowFlags = SDL_WINDOW_RESIZABLE | SDL_WINDOW_INPUT_GRABBED;
	else if (initialisationFormForProgram.windowIsResizable)
		windowFlags = SDL_WINDOW_RESIZABLE;
	else if (initialisationFormForProgram.windowHasInputGrabbed)
		windowFlags = SDL_WINDOW_INPUT_GRABBED;
	else
		windowFlags = SDL_WINDOW_SHOWN;
	this->window = SDL_CreateWindow(initialisationFormForProgram.programName.c_str(), initialisationFormForProgram.windowX, initialisationFormForProgram.windowY, initialisationFormForProgram.windowWidth, initialisationFormForProgram.windowHeight, windowFlags);
	if (this->window == NULL) return gldev::Error("couldn't create sdl2 window");
	Uint32 renderFlags;
	if (initialisationFormForProgram.vsyncEnabled)
		renderFlags = SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC;
	else
		renderFlags = SDL_RENDERER_ACCELERATED;
	this->renderer = SDL_CreateRenderer(this->window, -1, renderFlags);
	if (this->renderer == NULL) return gldev::Error("couldn't create sdl2 renderer");
	SDL_SetRenderDrawColor(this->renderer, 0, 0, 0, 0);
	int imgFlags = IMG_INIT_PNG;
	if (!(IMG_Init(imgFlags) & imgFlags)) return gldev::Error("couldn't initialise sdl_image");
	return gldev::Error();
}
#endif