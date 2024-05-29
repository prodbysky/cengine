#pragma once

#include "plog/Formatters/TxtFormatter.h"

#include <iostream>
#include <plog/Appenders/IAppender.h>

#define CE_FATAL PLOGF
#define CE_ERROR PLOGE
#define CE_WARNING PLOGW
#define CE_INFO PLOGF
#define CE_DEBUG PLOGD
#define CE_VERBOSE PLOGS

namespace CEngine::Log {
    class StdErrAppender : public plog::IAppender {
    public:
        virtual void write(const plog::Record& record) override {
            std::cerr << plog::TxtFormatter::format(record);
        }
    };
    inline static StdErrAppender appender;
    void Init();
} // namespace CEngine::Log
