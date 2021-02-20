#pragma once

#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_programHeaders/gldev_programCore.h"
#include "../gldev_engineHeaders/gldev_error.h"
#include "../gldev_engineHeaders/gldev_threadFlag.h"
#include "../gldev_engineHeaders/gldev_frameData.h"
#include <filesystem>
#include <string>

namespace gldev {
	template<class GraphicsAPI>
	class Program {
	public:
		~Program();
		gldev::Error setup();
		void runRenderingThread();
		void runLoadingThread();
		void runProgramCoreThread();
	protected:
		std::filesystem::path getUnicodeFilePath(std::string programName, std::string fileName);
	private:
		GraphicsAPI* graphicsAPI;
		ProgramCore* programCore;
		FrameData* frameData;
		bool* containsValidFrame;
		gldev::Error error;
		gldev::ThreadFlag errorThreadFlag;
		gldev::ThreadFlag* frameDataThreadFlag;
	};
}