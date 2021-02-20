#pragma once

#define GLDEV_USE_SDL2 0
#define GLDEV_USE_VULKAN 1
#define GLDEV_USE_DIRECTX12 2
#define GLDEV_USE_OPENGL 3

#define GLDEV_USE_WINDOWS 0

#define GLDEV_USE_ENGLISH 0

#define GLDEV_RESOURCE_TYPE_TEXTURE 0

#include "../gldev_programHeaders/gldev_programConditional.h"

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_SDL2
#include <SDL.h>
#include <SDL_image.h>
#include "../gldev_engineHeaders/gldev_graphicsAPI_sdl2.h"
#define GLDEV_GRAPHICS_API gldev::GraphicsAPI_sdl2
#endif

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_VULKAN
#include "../gldev_engineHeaders/gldev_graphicsAPI_vulkan.h"
#define GLDEV_GRAPHICS_API gldev::GraphicsAPI_vulkan
#endif

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_DIRECTX12
#include "../gldev_engineHeaders/gldev_graphicsAPI_directx12.h"
#define GLDEV_GRAPHICS_API gldev::GraphicsAPI_directx12
#endif

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_OPENGL
#include "../gldev_engineHeaders/gldev_graphicsAPI_opengl.h"
#define GLDEV_GRAPHICS_API gldev::GraphicsAPI_opengl
#endif

#if GLDEV_USE_OS == GLDEV_USE_WINDOWS
#include <windows.h>
#endif