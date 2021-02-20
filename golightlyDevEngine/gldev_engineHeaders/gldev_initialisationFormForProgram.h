#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_loadResourceRequestForm.h"
#include <string>

namespace gldev {
	struct InitialisationFormForProgram {
		InitialisationFormForProgram() : programName{ "" }, windowWidth{ 0 }, windowHeight{ 0 }, windowIsFullscreen{ false }, windowIsBorderless{ false }, windowIsResizable{ false }, vsyncEnabled{ false }, frameRate{ 0 } {};
		std::string programName;
		int windowX;
		int windowY;
		int windowWidth;
		int windowHeight;
		bool windowIsFullscreen;
		bool windowIsBorderless;
		bool windowIsResizable;
		bool windowHasInputGrabbed;
		bool minimiseOnFullscreenSingleMonitorAltTab;
		bool vsyncEnabled;
		int frameRate;
		int monitorToFullscreenDisplayTo;
		gldev::LoadResourceRequestForm** loadResourceRequestForm; //pointer to array of loadResourceRequestForm
	};
}