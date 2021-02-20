#include "../gldev_engineHeaders/gldev_engineConditional.h"
#include "../gldev_engineHeaders/gldev_program.h"
#include "../gldev_engineHeaders/gldev_error.h"
#include <thread>

void initialiseLoadingThread(gldev::Program<GLDEV_GRAPHICS_API>* program) {
	program->runLoadingThread();
}

void initialiseProgramCoreThread(gldev::Program<GLDEV_GRAPHICS_API>* program) {
	program->runProgramCoreThread();
}

#if GLDEV_USE_OS == GLDEV_USE_WINDOWS && GLDEV_USE_GRAPHICS_API != GLDEV_USE_SDL2
	int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd) {
		
		return 0;
	}
#else
	int main(int argc, char** argv) {
		gldev::Program<GLDEV_GRAPHICS_API> program;
		gldev::Error error = program.setup();
		if (error.getErrorFound()) {
			error.outputErrorToFile();
			return 0;
		}
		std::thread loadingThread(initialiseLoadingThread, &program);
		std::thread programCoreThread(initialiseProgramCoreThread, &program);
		program.runRenderingThread();
		loadingThread.join();
		programCoreThread.join();
		program.writeError();
		return 0;
	}
#endif