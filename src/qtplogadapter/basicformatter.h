/*
    Copyright 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#pragma once

#include <plog/Log.h>

namespace qtplogadapter
{

class BasicFormatter
{
public:
    static plog::util::nstring header();
    static plog::util::nstring format(const plog::Record& record);
};

}
