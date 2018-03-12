import QtQuick 2.9
import QtQuick.Window 2.2


Window {
    id: window
    visible: true
    width: 700
    height: 500
    title: qsTr("2048")


    Rectangle {
        id: grand_rectangle
        x: 259
        y: 184
        width: 415
        height: 415
        color: "#b6b1a4"
        radius: 10
        border.width: 0
        anchors.verticalCenter: parent.verticalCenter
        anchors.horizontalCenter: parent.horizontalCenter

        Case {id: c11; x: 15; y: 15}
        Case {id: c12; x: 115; y: 15}
        Case {id: c13; x: 215; y: 15}
        Case {id: c14; x: 315; y: 15}
        Case {id: c21; x: 15; y: 115}
        Case {id: c22; x: 115; y: 115}
        Case {id: c23; x: 215; y: 115}
        Case {id: c24; x: 315; y: 115}
        Case {id: c31; x: 15; y: 215}
        Case {id: c32; x: 115; y: 215}
        Case {id: c33; x: 215; y: 215}
        Case {id: c34; x: 315; y: 215}
        Case {id: c41; x: 15; y: 315}
        Case {id: c42; x: 115; y: 315}
        Case {id: c43; x: 215; y: 315}
        Case {id: c44; x: 315; y: 315}


    }

}
