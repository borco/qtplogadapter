#pragma once

#include <QString>

namespace logging
{

void message_handler(QtMsgType type, const QMessageLogContext &context, const QString &msg);

}
