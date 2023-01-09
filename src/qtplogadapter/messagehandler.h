/*
    Copyright (C) 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#pragma once

#include <QString>

namespace qtplogadapter
{

void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

}
