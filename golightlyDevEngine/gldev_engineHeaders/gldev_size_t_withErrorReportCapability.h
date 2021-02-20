#pragma once
#include <cstddef>

namespace gldev {
	struct Size_t_withErrorReportCapability {
		Size_t_withErrorReportCapability(size_t data, bool error) : data{ data }, error{ error } {}
		size_t data;
		bool error;
	};
}