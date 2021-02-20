#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_loadResourceRequestForm.h"
#include <string>

namespace gldev {
	struct InitialisationFormForProgram {
		InitialisationFormForProgram() : programName{ "" }, windowX{ 0 }, windowY{ 0 }, windowWidth{ 0 }, windowHeight{ 0 }, windowIsFullscreen{ false }, windowIsBorderless{ false }, windowIsResizable{ false }, windowHasInputGrabbed{ false }, minimiseOnFullscreenSingleMonitorAltTab{ false }, vsyncEnabled{ false }, frameRate{ 0 }, monitorToFullscreenDisplayTo{ 0 }, loadResourceRequestForm{ nullptr } {}
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