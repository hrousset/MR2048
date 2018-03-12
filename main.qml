import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: window
    visible: true
    width: 500
    height: 650
    color: "#ffffff"
    //    property alias tileCouleurCase: Tile.couleurCase
    title: qsTr("2048")


    Rectangle {
        id: grand_rectangle
        x: 259
        y: 184
        width: 415
        height: 415
        color: "#908b86"
        radius: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 42
        border.width: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Repeater {
            model: 16
            delegate: Tile {
                objectName: "case" + index
                x: index%4*100+15
                y: (index-index%4)/4*100+15
                Tile {
                    objectName: "tile" + index
                    color: "#eceae5"
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter

                    Text {
                        objectName: "nums%".arg(index)
                        color: "#46423e"
                        text: valeur+index.jeuQML
                        font.weight: Font.Black
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: 40
                    }
                }
            }
        }

    TextEdit {
        id: titre
        x: 0
        y: -142
        width: 80
        height: 20
        color: "#46423e"
        text: qsTr("2048")
        font.weight: Font.Black
        font.bold: false
        font.family: "Arial"
        selectionColor: "#020080"
        font.pixelSize: 48
    }

    Rectangle {
        id: score
        x: 191
        y: -157
        width: 100
        height: 50
        color: "#908b86"
        radius: 5
        border.width: 0

        Text {
            id: titre_score
            x: 43
            width: 28
            height: 18
            color: "#e7e3d8"
            text: qsTr("SCORE")
            font.pixelSize: 14
            font.bold: false
            font.family: "Arial"
            anchors.horizontalCenter: parent.horizontalCenter
            font.weight: Font.Black
            horizontalAlignment: Text.AlignHCenter
            anchors.top: parent.top
            anchors.topMargin: 7
        }
    }

    Rectangle {
        id: best
        x: 315
        y: -157
        width: 100
        height: 50
        color: "#908b86"
        radius: 5

        Text {
            id: titre_best
            x: 43
            width: 28
            height: 18
            color: "#e7e3d8"
            text: qsTr("BEST")
            font.pixelSize: 14
            font.bold: false
            font.family: "Arial"
            anchors.top: parent.top
            anchors.topMargin: 7
            font.weight: Font.Black
            anchors.horizontalCenter: parent.horizontalCenter
            horizontalAlignment: Text.AlignHCenter
        }
        border.width: 0
    }

    TextEdit {
        id: consigne
        x: 0
        y: -59
        width: 80
        height: 20
        text: qsTr("Assemble les cases pour arriver au 2048 !")
        font.pixelSize: 15
    }

    Rectangle {
        id: reset
        x: 292
        y: -71
        width: 123
        height: 44
        color: "#46423e"
        radius: 7
        border.width: 0

        Text {
            id: newgame
            x: 50
            y: 15
            color: "#ffffff"
            text: qsTr("NEW GAME")
            font.weight: Font.Black
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.pixelSize: 16
        }
    }
    }

}

