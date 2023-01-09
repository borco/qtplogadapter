/*
    Copyright (C) 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#pragma once

#include <QList>

namespace qtplogadapter
{

struct GuiMessage {
    uint index {0};
    QString severity;
    QString message;
};

typedef QList<GuiMessage> GuiMessageList;

}
