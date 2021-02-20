#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_initialisationFormForProgram.h"
#include "../gldev_engineHeaders/gldev_error.h"

#if GLDEV_USE_GRAPHICS_API == GLDEV_USE_DIRECTX12
namespace gldev {
	class GraphicsAPI_directx12 {
	public:
		~GraphicsAPI_directx12();
		gldev::Error setup(InitialisationFormForProgram& initialisationFormForProgram);
	private:
	};
}
#endif
