import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    id: cell
    x: 0
    y: 0

    property int swapX: 0
    property int swapY: 0

    property int i: 0
    property int j: 0
    property string img: ""

    property int type;
    property bool isHover: false;
    property bool isTrap: false;
    property bool isClicked: false;

    width: 69
    height: 50
    color: "transparent"
    Image {
        smooth: true
        id: iconImg
        source: img
        width: cell.width*0.9
        height: cell.height*0.9
    }
    SequentialAnimation{
        id: cellBig

        NumberAnimation {
            target: iconImg
            property: "scale"
            duration: 500
            from: 1.0
            to: 1.2
        }
    }
    SequentialAnimation{
        id: cellSmoll

        NumberAnimation {
            target: iconImg
            property: "scale"
            duration: 500
            from: 1.2
            to: 0.0
        }
    }
    SequentialAnimation{
        id: cellNormal

        NumberAnimation {
            target: iconImg
            property: "scale"
            duration: 1000
            from:  0.0
            to: 1.0
        }
    }

    ParallelAnimation{
        id: cellSwap

        NumberAnimation {
            target: iconImg
            property: "x"
            duration: 500
            from:  iconImg.x
            to: swapX
        }
        NumberAnimation {
            target: iconImg
            property: "y"
            duration: 500
            from:  iconImg.y
            to: swapY
        }
    }
    MouseArea {
        anchors.fill: parent
        id: mousearea
        hoverEnabled: true
        onClicked: {
                    //cell.parent.playMusic();
                    windowsField.eventClick(i, j);
                    repaint();
                    }
        onExited: {if (!isTrap) isHover = false; repaint();}
        onEntered: {
                    isHover = true;
                    if (isClicked) isHover = false;
                    repaint();
                  }
    }

    function updateType(typeCell)
    {
       type = typeCell;
       isHover = false;
       isClicked = false;
       repaint();
    }
    function clickedButton()
    {

        isClicked = true;
        isHover = false;
        if (cell.scale != 1.2)
            cellBig.running = true;
        repaint();
    }
    function decSize()
    {
        isClicked = false;
        isHover = false;
        cellSmoll.running = true;
        repaint();
    }
    function normalSize()
    {
        isClicked = false;
        isHover = false;
        cellNormal.running = true;
        repaint();
    }
    function swap(sx, sy)
    {
        swapX = sx;
        swapY = sy;

        console.log(x + " " +y + " " + swapX + " " + swapY);
        cellSwap.running = true;
    }
    function setTrap(trap)
    {
        isTrap = trap;
        repaint();
    }

    function repaint()
    {
        switch (type)
        {
            case 0:
                if (isTrap)
                {
                     cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "RedBlocked.png";
                }else
                if (isHover)
                {
                   cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "RedHover.png";

                } else if (isClicked)
                {
                    cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Red.png";
                } else cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Red.png";
                break;
            case 1:
                if (isTrap)
                {
                     cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "GreenBlocked.png";
                }else
                if (isHover)
                {
                   cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "GreenHover.png";

                } else if (isClicked)
                {
                    cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Green.png";
                } else cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Green.png";
                break;
            case 2:
                if (isTrap)
                {
                     cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "BlueBlocked.png";
                }else
                if (isHover)
                {
                   cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "BlueHover.png";

                } else if (isClicked)
                {
                    cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Blue.png";
                } else cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Blue.png";
                break;
            case 3:
                if (isTrap)
                {
                     cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "YellowBlocked.png";
                }else
                if (isHover)
                {
                   cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "YellowHover.png";

                } else if (isClicked)
                {
                    cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Yellow.png";
                } else cell.children[0].source = "qrc:/image/image/" + parent.typeSkin + "Yellow.png";
                break;
        }
    }
}
