#include "../gldev_engineHeaders/gldev_program.h"
#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_initialisationFormForProgram.h"
#include <fstream>
#include <filesystem>
#include <string>
#include <mutex>
#include <condition_variable>

template<>
gldev::Program<GLDEV_GRAPHICS_API>::~Program() {
	delete this->programCore;
	delete this->graphicsAPI;
	delete this->frameData;
}

template<>
gldev::Error gldev::Program<GLDEV_GRAPHICS_API>::setup() {
	this->programCore = new gldev::ProgramCore;
	gldev::InitialisationFormForProgram initialisationFormForProgram;
	initialisationFormForProgram.programName = this->programCore->getProgramName();
	initialisationFormForProgram.windowHasInputGrabbed = this->programCore->getWindowHasInputGrabbed();
	initialisationFormForProgram.minimiseOnFullscreenSingleMonitorAltTab = this->programCore->getMinimiseOnFullscreenSingleMonitorAltTab();
	std::ifstream readFile(this->getUnicodeFilePath(initialisationFormForProgram.programName, u8"initialisationDataForProgram.ini"));
	if (!readFile.is_open()) { this->error.setError(true, "could not open initialisationDataForProgram.ini"); return this->error; }
	std::string input;
	std::getline(readFile, input);
	if (input == "window x") { std::getline(readFile, input); initialisationFormForProgram.windowX = std::stoi(input); }
	std::getline(readFile, input);
	if (input == "window y") { std::getline(readFile, input); initialisationFormForProgram.windowY = std::stoi(input); }
	std::getline(readFile, input);
	if (input == "window width") { std::getline(readFile, input); initialisationFormForProgram.windowWidth = std::stoi(input); }
	std::getline(readFile, input);
	if (input == "window height") { std::getline(readFile, input); initialisationFormForProgram.windowHeight = std::stoi(input); }
	std::getline(readFile, input);
	if (input == "fullscreen window") { std::getline(readFile, input); if(input == "true") initialisationFormForProgram.windowIsFullscreen = true; }
	std::getline(readFile, input);
	if (input == "borderless window") { std::getline(readFile, input); if (input == "true") initialisationFormForProgram.windowIsBorderless = true; }
	std::getline(readFile, input);
	if (input == "resizable window") { std::getline(readFile, input); if (input == "true") initialisationFormForProgram.windowIsResizable = true; }
	std::getline(readFile, input);
	if (input == "vsync enabled") { std::getline(readFile, input); if (input == "true") initialisationFormForProgram.vsyncEnabled = true; }
	std::getline(readFile, input);
	if (input == "frame rate") { std::getline(readFile, input); initialisationFormForProgram.frameRate = std::stoi(input); }
	readFile.close();
	readFile.clear();
	this->containsValidFrame = new bool[this->programCore->frameDataNum];
	this->frameDataThreadFlag = new gldev::ThreadFlag[this->programCore->frameDataNum];
	for (int a = 0; a < this->programCore->frameDataNum; ++a)
		this->containsValidFrame[a] = false;
	this->frameData = new gldev::FrameData[this->programCore->frameDataNum];
	this->graphicsAPI = new GLDEV_GRAPHICS_API;
	return this->graphicsAPI->setup(initialisationFormForProgram);
}

template<>
void gldev::Program<GLDEV_GRAPHICS_API>::runRenderingThread() {
	while (this->useError(this->graphicsAPI->run()) == GLDEV_ERROR_NOT_FOUND) {}
}

template<>
void gldev::Program<GLDEV_GRAPHICS_API>::runLoadingThread() {
	/**/
}

template<>
void gldev::Program<GLDEV_GRAPHICS_API>::runProgramCoreThread() {
	/**/
}

template<>
void gldev::Program<GLDEV_GRAPHICS_API>::writeError() {
	if (error.getErrorDescription() != "normal program shutdown") {
		std::ofstream writeFile(this->getUnicodeFilePath(u8"errorLog.txt", u8"initialisationDataForProgram.ini"));
		writeFile << this->error.getErrorDescription();
		writeFile.close();
		writeFile.clear():
	}
}

template<>
bool gldev::Program<GLDEV_GRAPHICS_API>::useError(int useType) {
	std::unique_lock<std::mutex> lock(this->errorThreadFlag.mutex);
	while (this->errorThreadFlag.currentlyLocked)
		this->errorThreadFlag.conditionVariable.wait(lock);
	this->errorThreadFlag.currentlyLocked = true;
	if (this->error.getErrorFound() == GLDEV_ERROR_FOUND) {
		this->errorThreadFlag.currentlyLocked = false;
		this->errorThreadFlag.conditionVariable.notify_one();
		return GLDEV_ERROR_FOUND;
	}
	switch (useType) {
	case GLDEV_ERROR_TYPE_READING_NO_ERROR_TO_WRITE :
		this->errorThreadFlag.currentlyLocked = false;
		this->errorThreadFlag.conditionVariable.notify_one();
		return GLDEV_ERROR_NOT_FOUND;
		break;
	case GLDEV_ERROR_TYPE_WRITING_RENDERING_ERROR :
		this->error.setError(GLDEV_ERROR_FOUND, this->tempRenderingErrorDescription.c_str());
		break;
	case GLDEV_ERROR_TYPE_WRITING_LOADING_ERROR :
		this->error.setError(GLDEV_ERROR_FOUND, this->tempLoadingErrorDescription.c_str());
		break;
	case GLDEV_ERROR_TYPE_WRITING_PROGRAM_CORE_ERROR :
		this->error.setError(GLDEV_ERROR_FOUND, this->tempProgramCoreErrorDescription.c_str());
		break;
	default:
		break;
	}
	this->errorThreadFlag.currentlyLocked = false;
	this->errorThreadFlag.conditionVariable.notify_one();
	return GLDEV_ERROR_FOUND;
}

template<>
void gldev::Program<GLDEV_GRAPHICS_API>::useFrameData() {
	/**/
}

template<>
std::filesystem::path gldev::Program<GLDEV_GRAPHICS_API>::getUnicodeFilePath(std::string programName, std::string fileName) {
	std::string programPath;
#if GLDEV_USE_OS == GLDEV_USE_WINDOWS
	wchar_t* windowsProgramPath;
	windowsProgramPath = new wchar_t[MAX_PATH];
	GetModuleFileNameW(NULL, windowsProgramPath, MAX_PATH);
	std::wstring windowsWStringPath(windowsProgramPath);
	int programPathSize = WideCharToMultiByte(CP_UTF8, 0, &windowsWStringPath[0], -1, NULL, 0, NULL, NULL);
	programPath = std::string(programPathSize, 0);
	WideCharToMultiByte(CP_UTF8, 0, &windowsWStringPath[0], (int)windowsWStringPath.size(), &programPath[0], programPathSize, NULL, NULL);
	delete[] windowsProgramPath;
	programPath.pop_back(); //removes null byte
#endif
	int directoryPathLength = programPath.length() - programName.length();
	std::string filePath;
	for (int a = 0; a < directoryPathLength; ++a) {
		filePath += programPath[a];
	}
	for (int a = 0; a < fileName.length(); ++a) {
		filePath += fileName[a];
	}
	std::filesystem::path portableUnicodePath = filePath;
	return portableUnicodePath;
}