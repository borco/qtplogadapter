import QtQuick
import QtQuick.Controls

import QtPlogAdapter

ListView {
    model: PlogMessageModel
    delegate: Label {
        text: message
    }
}
