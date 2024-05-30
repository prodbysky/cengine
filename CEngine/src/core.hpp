#pragma once
#include <cstdlib>
#include <log.hpp>

#define CE_ASSERT(condition, ...)                                              \
    if (!(condition)) {                                                        \
        CE_ERROR << "Assert failed: " << __VA_ARGS__;                          \
        std::exit(1);                                                          \
    }
