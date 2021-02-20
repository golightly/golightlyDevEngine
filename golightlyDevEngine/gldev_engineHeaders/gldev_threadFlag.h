#pragma once

#include <mutex>
#include <condition_variable>

namespace gldev {
	struct ThreadFlag {
		ThreadFlag() : currentlyLocked{ false }, mutex{}, conditionVariable{} {}
		bool currentlyLocked;
		std::mutex mutex;
		std::condition_variable conditionVariable;
	};
}