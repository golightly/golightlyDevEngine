#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_loadTextureRequestForm.h"
#include "../gldev_engineHeaders/gldev_threadFlag.h"
#include <string>
#include <cstddef>

namespace gldev {
	struct LoadResourceRequestForm {
		LoadResourceRequestForm() : containsValidLoadResourceRequest{ false }, resourceID{ 0 }, resourceType{ 0 }, loadTextureRequestForm{ nullptr }, threadFlag{} {}
		void clear() {
			if (this->resourceType == GLDEV_RESOURCE_TYPE_TEXTURE) {
				delete this->loadTextureRequestForm;
				this->loadTextureRequestForm = nullptr;
			}
		}
		bool containsValidLoadResourceRequest;
		size_t resourceID;
		int resourceType;
		LoadTextureRequestForm* loadTextureRequestForm; //not an array, single object
		gldev::ThreadFlag threadFlag;
	};
}