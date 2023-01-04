/*
    Copyright 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#pragma once

#include <QObject>

#include <plog/Appenders/IAppender.h>

#include "guimessage.h"

namespace qtplogadapter
{

class GuiAppender : public QObject, public plog::IAppender
{
    Q_OBJECT

    Q_PROPERTY(bool writeToBuffer READ writeToBuffer WRITE setWriteToBuffer NOTIFY writeToBufferChanged)

public:
    ~GuiAppender();

    static GuiAppender* get();
    static void cleanup();

    void write(const plog::Record &record) override;

    GuiMessageList buffer() const { return m_buffer; }
    void clearBuffer();

    bool writeToBuffer() const { return m_writeToBuffer; }
    void setWriteToBuffer(bool newWriteToBuffer);

signals:
    void messageAppended(qtplogadapter::GuiMessage guiMessage);
    void writeToBufferChanged();

private:
    explicit GuiAppender(QObject *parent = nullptr);

    inline static GuiAppender* m_singleton {nullptr};

    uint m_index {0};
    GuiMessageList m_buffer;
    bool m_writeToBuffer {true};
};

}
