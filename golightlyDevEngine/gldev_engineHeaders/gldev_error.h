#pragma once

#include <string>
#include <fstream>

namespace gldev {
	class Error {
	public:
		Error() : errorFound{ GLDEV_ERROR_NOT_FOUND }, errorDescription{ "" } {}
		Error(const char* errorDescription) : errorFound{ GLDEV_ERROR_FOUND }, errorDescription{ errorDescription } {}
		~Error() {}
		void setError(bool errorFound, const char* errorDescription) { this->errorFound = errorFound; this->errorDescription = errorDescription; }
		void setErrorFound(bool errorFound) { this->errorFound = errorFound; }
		bool getErrorFound() { return this->errorFound; }
		void setErrorDescription(const char* errorDescription) { this->errorDescription = errorDescription; }
		const char* getErrorDescription() { return this->errorDescription.c_str(); }
		void outputErrorToFile() { std::ofstream writeFile("errorLog.txt"); writeFile << this->errorDescription; }
	private:
		bool errorFound;
		std::string errorDescription;
	};
}