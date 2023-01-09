/*
    Copyright (C) 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#include "messagehandler.h"

#include <plog/Log.h>

void qtplogadapter::message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg)
{
    QByteArray localMsg = msg.toLocal8Bit();
    const char *file = context.file ? context.file : "";
    //    const char *function = context.function ? context.function : "";

    switch (type) {
    case QtDebugMsg:
        PLOG_DEBUG << localMsg.constData() << " (file://" << file << ":" << context.line << /*", " << function <<*/ ")";
        break;
    case QtInfoMsg:
        PLOG_INFO << localMsg.constData() << " (file://" << file << ":" << context.line << /*", " << function <<*/ ")";
        break;
    case QtWarningMsg:
        PLOG_WARNING << localMsg.constData() << " (file://" << file << ":" << context.line << /*", " << function <<*/ ")";
        break;
    case QtCriticalMsg:
        PLOG_ERROR << localMsg.constData() << " (file://" << file << ":" << context.line << /*", " << function <<*/ ")";
        break;
    case QtFatalMsg:
        PLOG_FATAL << localMsg.constData() << " (file://" << file << ":" << context.line << /*", " << function <<*/ ")";
        break;
    }
}
