import QtQuick 2.0


Rectangle {
    property var visuel: listeNombres.visuQML
    property var couleur: ["#cdc0b4","#38393a"]
    width: 85
    height: 85
    color: couleur[visuel]
    radius: 5
    border.width: 0


}
