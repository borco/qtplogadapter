/*
    Copyright (C) 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#include "setup.h"

#include "basicformatter.h"
#include "guiappender.h"
#include "messagehandler.h"

#include <plog/Appenders/ConsoleAppender.h>
#include <plog/Appenders/RollingFileAppender.h>
#include <plog/Formatters/TxtFormatter.h>
#include <plog/Init.h>

#include <QDebug>

void qtplogadapter::init(const char* log_file)
{
    auto log_size = 1024 * 64; // in bytes
    auto log_count = 3;

    static plog::RollingFileAppender<BasicFormatter> fileAppender(log_file, log_size, log_count); // Create the 1st appender.
    static plog::ConsoleAppender<BasicFormatter> consoleAppender; // Create the 2nd appender.

    plog::init(plog::debug, &fileAppender).addAppender(&consoleAppender).addAppender(GuiAppender::get());

    qInstallMessageHandler(qtplogadapter::message_handler);
}

void qtplogadapter::cleanup()
{
    qInstallMessageHandler(0);
    GuiAppender::cleanup();
    qDebug() << "Restored default qt message handler";
}
