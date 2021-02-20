#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_programHeaders/gldev_resourceDataContainer.h"
#include <string>

namespace gldev {
	struct ProgramCore {
		ProgramCore();
		~ProgramCore();
		std::string getProgramName();
		bool getMinimiseOnFullscreenSingleMonitorAltTab();
		bool getWindowHasInputGrabbed();

		int language;
		int frameDataNum;
		gldev::ResourceDataContainer resourceDataContainer;
	};
}