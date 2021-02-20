#include "../gldev_programHeaders/gldev_programCore.h"
#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include <string>

gldev::ProgramCore::ProgramCore() {
	this->language = GLDEV_USE_ENGLISH;
	this->frameDataNum = 0;
}

gldev::ProgramCore::~ProgramCore() {

}

std::string gldev::ProgramCore::getProgramName() {
	if(this->language == GLDEV_USE_ENGLISH)
		return u8"Dungeon Crawler";
}

bool gldev::ProgramCore::getMinimiseOnFullscreenSingleMonitorAltTab() {
	return true;
}

bool gldev::ProgramCore::getWindowHasInputGrabbed() {
	return true;
}