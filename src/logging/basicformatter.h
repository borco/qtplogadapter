#pragma once

#include <plog/Log.h>

namespace logging
{

class BasicFormatter
{
public:
    static plog::util::nstring header();
    static plog::util::nstring format(const plog::Record& record);
};

}
