/*
    Copyright 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#include "plogmessagemodel.h"

#include "guiappender.h"

using namespace qtplogadapter;

PlogMessageModel::PlogMessageModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    qDebug() << this;

    auto gui_appender = GuiAppender::get();
    gui_appender->setWriteToBuffer(false);

    for (const auto& message: gui_appender->buffer()) {
        m_buffer.prepend(message);
    }

    connect(gui_appender, &GuiAppender::messageAppended, this, &PlogMessageModel::onMessageAppended);
}

PlogMessageModel::~PlogMessageModel()
{
    qDebug().nospace() << "~" << this;
}

int PlogMessageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return m_buffer.size();
}

int PlogMessageModel::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return 3;
}

QVariant PlogMessageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    switch (role) {
    case ColumnNames::Index:
        return m_buffer[index.row()].index;
    case ColumnNames::Severity:
        return m_buffer[index.row()].severity;
    default:
        return m_buffer[index.row()].message;
    }

    return QVariant();
}

QHash<int, QByteArray> PlogMessageModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Index] = "index";
    roles[Severity] = "severity";
    roles[Message] = "message";
    return roles;
}

void PlogMessageModel::clear()
{
    beginResetModel();
    m_buffer.clear();
    endResetModel();
}

void PlogMessageModel::onMessageAppended(GuiMessage guiMessage)
{
    beginInsertRows(QModelIndex(), 0, 0);
    m_buffer.prepend(guiMessage);
    endInsertRows();
}
