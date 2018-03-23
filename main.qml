import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: window
    visible: true
    width: 500
    height: 650
    color: "#faf8ef"
    title: qsTr("2048")


    Rectangle {
        id: grand_rectangle
        x: 259
        y: 184
        width: 415
        height: 415
        color: "#bbada0"
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
                Rectangle {
                    function log2(x) {
                        return Math.max(Math.log(x)/Math.log(2),0)
                    }
                    property var valeur: listeNombres.jeuQML //[2,0,16,256,2048,512,8192,4096,2,8,64,32,4,128,128,16]
                    property var couleur: ["","#eee4da"/*2*/,"#ede0c8"/*4*/,"#f2b179"/*8*/,"#f59563"/*16*/,"#f67c5f"/*32*/,"#f65e3b"/*64*/, "#edcf72"/*128*/,"#edcc61"/*256*/,"#edc850"/*512*/,"#edc53f"/*1024*/,"#edc22e"/*2048*/,"#2ea297"/*4096*/,"#17514b"/*8192*/,"#0b2825","#051412"]
                    height: (valeur[index]!=0)*85
                    width: (valeur[index]!=0)*85
                    radius: 5
                    objectName: "tile" + index
                    color: couleur[log2(valeur[index])]
                    anchors.horizontalCenter: parent.horizontalCenter
                    anchors.verticalCenter: parent.verticalCenter
                    focus: true
                    Keys.onPressed: {
                        switch (event.key) {
                        case Qt.Key_Up:
                            listeNombres.haut();
                            break;
                        case Qt.Key_Down:
                            listeNombres.bas();
                            break;
                        case Qt.Key_Right:
                            listeNombres.droite();
                            break;
                        case Qt.Key_Left:
                            listeNombres.gauche();
                            break;
                        }
                    }

                    Text {
                        function couleurNum(x) {
                            if (x<5) {return 0}
                            return 1
                        }

                        property var couleur1: ["#776e65","#f9f6f2"]
                        property var valeur1: listeNombres.jeuQML //[2,0,16,256,2048,512,8192,4096,2,8,64,32,4,128,128,16]
                        color: couleur1[couleurNum(valeur1[index])]
                        text: valeur1[index]
                        font.weight: Font.Black
                        anchors.horizontalCenter: parent.horizontalCenter
                        anchors.verticalCenter: parent.verticalCenter
                        font.pixelSize: (1000<valeur1[index])*30+(valeur1[index]<100)*40+(100<valeur1[index]&&valeur1[index]<1000)*35
                        opacity: (valeur1[index]!=0)*1
                        focus: true
                        Keys.onPressed: {
                            switch (event.key) {
                            case Qt.Key_Up:
                                listeNombres.haut();
                                break;
                            case Qt.Key_Down:
                                listeNombres.bas();
                                break;
                            case Qt.Key_Right:
                                listeNombres.droite();
                                break;
                            case Qt.Key_Left:
                                listeNombres.gauche();
                                break;
                            }
                        }
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
            color: "#776e65"
            text: qsTr("2048")
            font.weight: Font.Black
            font.bold: false
            font.family: "Arial"
            selectionColor: "#020080"
            font.pixelSize: 48
        }

        Rectangle {
            id: score
            x: 315
            y: -157
            width: 100
            height: 50
            color: "#bbada0"
            radius: 5
            border.width: 0

            Text {
                id: titre_score
                x: 43
                width: 28
                height: 18
                color: "#e7e3d8"
                text: qsTr("SCORE")
                anchors.horizontalCenterOffset: 0
                font.pixelSize: 14
                font.bold: false
                font.family: "Arial"
                anchors.horizontalCenter: parent.horizontalCenter
                font.weight: Font.Black
                horizontalAlignment: Text.AlignHCenter
                anchors.top: parent.top
                anchors.topMargin: 3
            }

            Text {
                id: text1
                x: 39
                y: 16
                color: "#faf8ef"
                text: listeNombres.scQML
                anchors.horizontalCenterOffset: 0
                font.weight: Font.ExtraBold
                font.family: "Arial"
                renderType: Text.NativeRendering
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 30
            }
        }

        /*Rectangle {
        id: best
        x: 191
        y: -157
        width: 100
        height: 50
        color: "#bbada0"
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
    }*/

        TextEdit {
            id: consigne
            x: 0
            y: -59
            width: 80
            height: 20
            text: qsTr("Assemble les cases pour arriver à 2048 !")
            font.pixelSize: 15
            color: "#776e65"
        }

        Rectangle {
            id: reset
            x: 292
            y: -71
            width: 123
            height: 44
            color: "#8f7a66"
            radius: 7
            border.width: 0


            Text {
                id: newgame
                x: 50
                y: 15
                color: "#faf8ef"
                text: qsTr("NEW GAME")
                font.weight: Font.Black
                anchors.verticalCenter: parent.verticalCenter
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 16
            }

            MouseArea {
                id: mouseArea
                anchors.fill: parent
                onClicked: {listeNombres.restartGame()}
            }
        }

        Image {
            id: medaille
            x: 0
            y: 0
            width: 267
            height: 358
            opacity: 0.8*listeNombres.medailleQML
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            source: "medaille.png"

            TextEdit {
                id: textmedaille
                x: 94
                y: 95
                width: 180
                height: 59
                text: qsTr("BRAVO")
                font.weight: Font.ExtraBold
                anchors.horizontalCenter: parent.horizontalCenter
                font.pixelSize: 50
            }

            MouseArea {
                id: mouseArea1
                anchors.fill: parent
                onClicked: {listeNombres.supprmedaille()}
            }

            Text {
                id: text2
                x: 28
                y: 398
                color: "#707070"
                text: qsTr("Cliquez sur la médalle pour continuer...")
                font.pixelSize: 13
            }
        }

        Rectangle {
            id: fin
            color: "#ebe4dd"
            anchors.fill: parent
            radius: 10
            opacity: 0.6*listeNombres.finQML
        }
        Text {
            id: textefin
            x: 126
            y: 163
            width: 141
            height: 49
            color: "#776e65"
            text: qsTr("PERDU")
            opacity: listeNombres.finQML
            anchors.verticalCenter: parent.verticalCenter
            anchors.horizontalCenter: parent.horizontalCenter
            font.weight: Font.Black
            font.pixelSize: 40
        }

    }

    StateGroup {
        id: stateGroup
        states: [
            State {
                name: "State1"

                PropertyChanges {
                    target: grand_rectangle.textefin
                    opacity: 0
                }
            },
            State {
                name: "State2"

                PropertyChanges {
                    target: grand_rectangle.textefin
                    opacity: 0.6
                }
            }
        ]

        transitions: [
            Transition {
                from: "State1";
                to: "State2"
                NumberAnimation {
                    easing.type: Easing.Linear
                    properties: "opacity"
                    duration: 1000
                }
            }
        ]
    }

}

