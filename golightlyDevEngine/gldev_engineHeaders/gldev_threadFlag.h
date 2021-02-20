#pragma once

#include <mutex>
#include <condition_variable>

namespace gldev {
	struct ThreadFlag {
		ThreadFlag() { this->currentlyLocked = false; }
		bool currentlyLocked;
		std::mutex mutex;
		std::condition_variable conditionVariable;
	};
}