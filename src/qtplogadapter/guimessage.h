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
