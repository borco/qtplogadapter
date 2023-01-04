import QtQuick
import QtQuick.Controls
import QtQuick.Layouts

import QtPlogAdapter

Item {
    id: control

    component Severity: Rectangle {
        property alias text: severityText.text
        property int padding: 2

        height: severityText.height + 2 * padding
        width: 100
        radius: 6
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
            }

            Label {
                text: message
                elide: Text.ElideRight
                //                wrapMode: Text.WrapAtWordBoundaryOrAnywhere
                Layout.fillWidth: true
            }
        }

        ScrollIndicator.vertical: ScrollIndicator {}
    }
}
