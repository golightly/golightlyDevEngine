#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_initialisationFormForProgram.h"
#include "../gldev_engineHeaders/gldev_error.h"

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_VULKAN
namespace gldev {
	class GraphicsAPI_vulkan {
	public:
		~GraphicsAPI_vulkan();
		gldev::Error setup(InitialisationFormForProgram& initialisationFormForProgram);
	private:
	};
}
#endif