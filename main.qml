import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: window
    visible: true
    width: 500
    height: 650
    title: qsTr("2048")


    Rectangle {
        id: grand_rectangle
        x: 259
        y: 184
        width: 415
        height: 415
        color: "#b6b1a4"
        radius: 10
        anchors.bottom: parent.bottom
        anchors.bottomMargin: 42
        border.width: 0
        anchors.horizontalCenter: parent.horizontalCenter

        Tile {id: c11; x: 15; y: 15}
        Tile {id: c12; x: 115; y: 15}
        Tile {id: c13; x: 215; y: 15}
        Tile {id: c14; x: 315; y: 15}
        Tile {id: c21; x: 15; y: 115}
        Tile {id: c22; x: 115; y: 115}
        Tile {id: c23; x: 215; y: 115}
        Tile {id: c24; x: 315; y: 115}
        Tile {id: c31; x: 15; y: 215}
        Tile {id: c32; x: 115; y: 215}
        Tile {id: c33; x: 215; y: 215}
        Tile {id: c34; x: 315; y: 215}
        Tile {id: c41; x: 15; y: 315}
        Tile {id: c42; x: 115; y: 315}
        Tile {id: c43; x: 215; y: 315}
        Tile {id: c44; x: 315; y: 315}


    }

    TextEdit {
        id: titre
        x: 42
        y: 40
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
        x: 245
        y: 40
        width: 100
        height: 50
        color: "#b6b1a4"
        radius: 1
        border.width: 0

        Text {
            id: titre_score
            x: 43
            width: 28
            height: 18
            color: "#ffffff"
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
        x: 357
        y: 40
        width: 100
        height: 50
        color: "#b6b1a4"
        radius: 1

        Text {
            id: titre_best
            x: 43
            width: 28
            height: 18
            color: "#ffffff"
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
        x: 42
        y: 125
        width: 80
        height: 20
        text: qsTr("Assemble les cases pour arriver au 2048 !")
        font.pixelSize: 15
    }

    Rectangle {
        id: rectangle
        x: 334
        y: 113
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
