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

    property bool inDarkMode: palette.text > palette.base

    property color backgroundColor: palette.base
    property color baseColor: inDarkMode
                              ? Qt.lighter(backgroundColor, 1.2)
                              : Qt.darker(backgroundColor, 1.05)
    property color alternateColor: inDarkMode
                                   ? Qt.lighter(backgroundColor, 1.4)
                                   : Qt.darker(backgroundColor, 1.1)

    component Severity: Rectangle {
        property alias text: severityText.text
        property int index

        height: severityText.height + 2 * root.severityPadding
        width: root.severityWidth
        radius: root.severityRadius

        color: {
            switch(severity) {
            case "DEBUG":
                return inDarkMode ? "#10FFFFFF" : "#10000000"
            case "INFO":
                return "#8030DB5B"
            case "WARN":
                return "#80FFD426"
            default:
                return "#80FF6961"
            }
        }

        Label {
            id: severityText
            color: palette.text
            anchors.centerIn: parent
        }
    }

    Rectangle {
        anchors.fill: parent
        color: backgroundColor
    }

    ListView {
        id: listView

        clip: true
        anchors.fill: parent
        model: PlogMessageModel
        spacing: 0

        delegate: Rectangle {
            width: ListView.view.width
            implicitHeight: delegateLayout.implicitHeight

            color: index % 2 ? root.baseColor : root.alternateColor

            RowLayout {
                id: delegateLayout
                width: parent.width

                Severity {
                    text: severity
                    Layout.fillHeight: true
                }

                Label {
                    text: message
                    color: palette.text
                    elide: Text.ElideRight
                    wrapMode: root.wrapMessages
                              ? Text.WrapAtWordBoundaryOrAnywhere
                              : Text.NoWrap
                    Layout.fillWidth: true
                }
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
    }
}
