#include "log.hpp"

#include <plog/Init.h>
#include <plog/Initializers/ConsoleInitializer.h>

#define CE_

namespace CEngine::Log {
    void Init() {
        appender = StdErrAppender();
        plog::init(plog::debug, &appender);
    }
} // namespace CEngine::Log
