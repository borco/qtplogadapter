/*
    Copyright 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#include "guiappender.h"

#include <QDebug>

using namespace qtplogadapter;

GuiAppender::GuiAppender(QObject *parent)
    : QObject{parent}
{
//    qDebug() << this;
}

GuiAppender::~GuiAppender()
{
//    qDebug().nospace() << "~" << this;
}

GuiAppender *GuiAppender::get()
{
    if (!m_singleton) {
        m_singleton = new GuiAppender();
    }
    return m_singleton;
}

void GuiAppender::cleanup()
{
    delete m_singleton;
    m_singleton = nullptr;
}

void GuiAppender::write(const plog::Record &record)
{
    auto severity = QString(severityToString(record.getSeverity()));
    auto message = QString(record.getMessage());

    // skip some messages
    if (message.startsWith("qrc:/qt-project.org/imports/QtQuick/Controls/macOS/Button.qml:11")) {
        return;
    }

    // remove file location
    auto pos = message.indexOf(" (file://");
    if (pos >= 0) {
        message = message.left(pos);
    }

    GuiMessage gui_message {++m_index, severity, message};
    if (m_writeToBuffer) {
        m_buffer << gui_message;
    } else {
        emit messageAppended(gui_message);
    }
}

void GuiAppender::clearBuffer()
{
    m_buffer.clear();
}

void GuiAppender::setWriteToBuffer(bool newWriteToBuffer)
{
    if (m_writeToBuffer == newWriteToBuffer)
        return;
    m_writeToBuffer = newWriteToBuffer;
    emit writeToBufferChanged();
}
