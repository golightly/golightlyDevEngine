#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_programHeaders/gldev_resourceDataContainer.h"
#include "../gldev_engineHeaders/gldev_size_t_withErrorReportCapability.h"
#include <cstdlib>
#include <string>

int gldev::ResourceDataContainer::getRunningData(int resourceType, size_t resourceID, int subTextureID, std::string field) {
	switch (resourceType) {
	case GLDEV_RESOURCE_TYPE_TEXTURE:
		switch (resourceID) {
		case 0 : //texture file name here
			switch (subTextureID) {
			case 0 : //subtexture name here
				if (field == "subTextureStartX")
					return 0;
				else if (field == "subTextureStartY")
					return 0;
				else if (field == "subTextureWidth")
					return 100;
				else if (field == "subTextureHeight")
					return 100;
				break;
			default:
				return -1;
				break;
			}
			break;
		default:
			return -1;
			break;
		}
		break;
	default:
		return -1;
		break;
	}
}

gldev::Size_t_withErrorReportCapability gldev::ResourceDataContainer::getLoadingData(int resourceType, size_t resourceID, std::string field) {
	switch (resourceType) {
	case GLDEV_RESOURCE_TYPE_TEXTURE :
		switch (resourceID) {
		case 0 : //texture file name here
			if (field == "resourceDataStart")
				return gldev::Size_t_withErrorReportCapability(0, false);
			else if (field == "resourceDataSize")
				return gldev::Size_t_withErrorReportCapability(5432, false);
			break;
		default:
			return gldev::Size_t_withErrorReportCapability(0, true);
			break;
		}
		break;
	default:
		return gldev::Size_t_withErrorReportCapability(0, true);
		break;
	}
}