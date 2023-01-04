/*
    Copyright 2023 by Ioan Calin Borcoman <iborco@gmail.com>
*/

#pragma once

#include <QAbstractTableModel>
#include <QQmlEngine>

#include "guimessage.h"

namespace qtplogadapter {

class PlogMessageModel : public QAbstractTableModel
{
    Q_OBJECT
    QML_ELEMENT
    QML_SINGLETON

public:
    explicit PlogMessageModel(QObject *parent = nullptr);
    ~PlogMessageModel();

    int rowCount(const QModelIndex &parent) const override;
    int columnCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;

    QHash<int, QByteArray> roleNames() const override;

private:
    enum ColumnNames {
        Index = Qt::UserRole + 1,
        Severity,
        Message,
    };

    void onMessageAppended(qtplogadapter::GuiMessage guiMessage);

    GuiMessageList m_buffer;
};

}
