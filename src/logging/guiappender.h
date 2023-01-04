#pragma once

#include <QObject>

#include <plog/Appenders/IAppender.h>

namespace logging
{

struct GuiMessage {
    uint index {0};
    QString severity;
    QString message;
};

typedef QList<GuiMessage> GuiMessageList;

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
    void messageAppended(logging::GuiMessage guiMessage);
    void writeToBufferChanged();

private:
    explicit GuiAppender(QObject *parent = nullptr);

    static bool m_singletonCreatedOnce;
    static GuiAppender* m_singleton;

    uint m_index {0};
    GuiMessageList m_buffer;
    bool m_writeToBuffer {true};
};

}
