#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_size_t_withErrorReportCapability.h"
#include <cstdlib>
#include <string>

namespace gldev {
	class ResourceDataContainer {
	public:
		int getRunningData(int resourceType, size_t resourceID, int subTextureID, std::string field);
		gldev::Size_t_withErrorReportCapability getLoadingData(int resourceType, size_t resourceID, std::string field);
	};
}