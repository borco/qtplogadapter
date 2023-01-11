import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QtPlogAdapter

Item {
    id: root

    property bool wrapMessages: false
    property int severityRadius: 0
    property int severityPadding: 2
    property int severityWidth: 80

    component Severity: Rectangle {
        property alias text: severityText.text

        height: severityText.height + 2 * root.severityPadding
        width: root.severityWidth
        radius: root.severityRadius
        border.width: 1
        border.color: Qt.darker(color, 1.1)

        color: {
            switch(severity) {
            case "DEBUG":
                return "transparent"
            case "INFO":
                return "#caffbf"
            case "WARN":
                return "#fdffb6"
            default:
                return "#ffc6ff"
            }
        }

        Label {
            id: severityText
            anchors.centerIn: parent
        }
    }

    ListView {
        id: listView

        clip: true
        anchors.fill: parent
        model: PlogMessageModel
        spacing: 2

        delegate: RowLayout {
            width: ListView.view.width
            Severity {
                text: severity
                Layout.alignment: root.wrapMessages
                                  ? Qt.AlignTop
                                  : Qt.AlignVCenter
            }

            Label {
                text: message
                elide: Text.ElideRight
                wrapMode: root.wrapMessages
                          ? Text.WrapAtWordBoundaryOrAnywhere
                          : Text.NoWrap
                Layout.fillWidth: true
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
    }
}
