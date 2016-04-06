import QtQuick 2.0
import QtMultimedia 5.0

Rectangle {
    id: global
    width: 1920
    height: 1080
    anchors.fill: parent
    z: 3

    Rectangle {
        objectName:"mainField"
        property int fieldI: 10
        property int fieldJ: 15
        property string typeSkin: "crystal"
        id: mainField
        x: 0
        y: 0
        width: 1920
        height: 1080
        color: "transparent"

        MediaPlayer {
            id: playMusic
            source: "qrc:/music/music/back_2.mp3"
        }
        ParallelAnimation{
            id: closelevel

            NumberAnimation {
                target: mainField
                property: "opacity"
                duration: 500
                from: 1
                to: 0.0
            }
            NumberAnimation {
                target: mainField
                property: "x"
                duration: 500
                from: 0
                to: mainField.width
            }
            NumberAnimation {
                target: playMusic
                property: "volume"
                duration: 2000
                from: 1
                to: 0
            }
            onStopped: playMusic.stop()
        }
        Rectangle {
            anchors.fill: parent
            color: "transparent"
            Image {
                id: back1
                x: 0
                y: 0
                width: mainField.width*0.2343
                height: mainField.height
                source: "qrc:/image/image/background1.jpg"
            }
        }

        Rectangle {
            anchors.fill: parent
            color: "transparent"
            Image {
                id: back2
                x: mainField.width*0.2343
                y: 0
                width: mainField.width*0.7656
                height: mainField.height
                source: "qrc:/image/image/background2.jpg"
            }
        }

        Rectangle{
            x: 0
            y: 25
            width:450
            height: 25
            color: "transparent"
            Text{
                anchors.centerIn: parent
                font.family: "Segoe Print"
                font.pointSize: 20
                text: ""
            }
        }
        Rectangle{
            x: 0
            y: 50
            width:450
            height: 25
            color: "transparent"
            Text{
                anchors.centerIn: parent
                font.family: "Segoe Print"
                font.pointSize: 20
                text: ""
            }
        }
        Rectangle{
            id: hero
            property int typeHero: 0
            property bool isAction: false
            color: "transparent"
            x: 75
            y: 50
            width: 300
            height: 300
            Image {
                anchors.fill: parent
                id: imgHero
                source: ""
            }
            MouseArea {
                anchors.fill: parent
                id: mousearea
                hoverEnabled: true
                onClicked: {
                            windowsField.changeConditionForActivateSkill()
                            }
            }


           function repaint()
           {
               switch (typeHero)
               {
                   case 0:
                       if (isAction)
                       {
                           hero.children[0].source = "qrc:/image/image/powerClickedWarrior.png";
                       }
                       else
                           hero.children[0].source = "qrc:/image/image/heroPowerWarrior.png";
                       break;
                   case 1:
                       if (isAction)
                       {
                           hero.children[0].source = "qrc:/image/image/powerClickedHunter.png";
                       }
                       else
                           hero.children[0].source = "qrc:/image/image/heroPowerHunter.png";
                       break;
                   case 2:
                       if (isAction)
                       {
                           hero.children[0].source = "qrc:/image/image/powerClickedMage.png";
                       }
                       else
                           hero.children[0].source = "qrc:/image/image/heroPowerMage.png";
                       break;
               }
           }
        }
        Image {
            id: imgLevelExit
            source: "qrc:/image/image/button_1.png"
            y: mainField.height - 200

            Text
            {
                     id: textLevelExit
                     anchors.centerIn: parent
                     font.pointSize: 20
                     color: "white"
                     font.family: "Segoe Print"
                     text: "Назад"
            }

            MouseArea {
                anchors.fill: parent
                hoverEnabled: true
                onClicked: {
                    windowsField.closeLevel();
                    mainField.destroyCell();
                    closelevel.running = true;
                }

                onEntered: imgLevelExit.source = "qrc:/image/image/buttonClicked_1.png"
                onExited: imgLevelExit.source = "qrc:/image/image/button_1.png"
            }
        }

       function destroyCell()
       {

           for (var i = 0; i < fieldI; i++)
           {
               for (var j = 0; j < fieldI; j++)
               {
                   mainField.children[6+i*fieldJ+j].destroy();
               }
           }
       }
        function playM()
        {
            playMusic.play();
        }

        function setHero(typeHero)
        {
            hero.typeHero = typeHero;
            hero.repaint();
        }

        function setActiveHero(active)
        {
            hero.isAction = active;
            hero.repaint();
        }
        function setText1(text)
        {
            mainField.children[2].children[0].text = text;
        }
        function setText2(text)
        {
            mainField.children[3].children[0].text = text;
        }
        function createField(maxI, maxJ){
            var component;
            var childRec;
            console.log("dd")
            playM();
            fieldI = maxI;
            fieldJ = maxJ;
            for (var i = 0; i < maxI; i++)
            {
                for (var j = 0; j < maxJ; j++)
                {
                    component = Qt.createComponent("Cell.qml");
                    if (component.status == Component.Ready) {
                        childRec = component.createObject(mainField);
                        childRec.objectName = "cell_" + i + "_" + j;
                        childRec.x = j*96.6+450;
                        childRec.y = i*70;
                        childRec.i = i;
                        childRec.width = 96.6;
                        childRec.height = 70;
                        childRec.j = j;
                        childRec.img = "qrc:/image/image/crystalGreen.png";
                    }
                }
            }
        }
        function swap(i1,j1,i2,j2)
        {
            var tempX;
            var tempY;
            if (i1 < i2)
            {
                tempX = 0;
                tempY = mainField.children[6+i2*fieldJ+j2].y - mainField.children[6+i1*fieldJ+j1].y;
                console.log(tempY)
                mainField.children[6+i1*fieldJ+j1].children[0].y = tempY;
                mainField.children[6+i2*fieldJ+j2].children[0].y = -tempY;

            } else if (i1>i2)
            {
                tempX = 0;
                tempY = -mainField.children[6+i2*fieldJ+j2].y + mainField.children[6+i1*fieldJ+j1].y;
                console.log(tempY)
                mainField.children[6+i1*fieldJ+j1].children[0].y = -tempY;
                mainField.children[6+i2*fieldJ+j2].children[0].y = tempY;
            }

            if (j1 < j2)
            {
                tempX = mainField.children[6+i2*fieldJ+j2].x - mainField.children[6+i1*fieldJ+j1].x;
                tempY = 0;
                console.log(tempX)
                mainField.children[6+i1*fieldJ+j1].children[0].x = tempX;
                mainField.children[6+i2*fieldJ+j2].children[0].x = -tempX;

            } else if (j1>j2)
            {
                tempX = -mainField.children[6+i2*fieldJ+j2].x + mainField.children[6+i1*fieldJ+j1].x;
                tempY = 0;
                console.log(tempX)
                mainField.children[6+i1*fieldJ+j1].children[0].x = -tempX;
                mainField.children[6+i2*fieldJ+j2].children[0].x = tempX;
            }
            mainField.children[6+i1*fieldJ+j1].swap(0, 0);
            mainField.children[6+i2*fieldJ+j2].swap(0, 0);
        }
    }

    Image {
        source: "qrc:/image/image/mainMenu3.png"

    }
    ParallelAnimation{
        id: loadlevel

        NumberAnimation {
            target: mainField
            property: "opacity"
            duration: 500
            from: 0
            to: 1.0
        }
        NumberAnimation {
            target: mainField
            property: "x"
            duration: 500
            from: mainField.x
            to: 0
        }
        NumberAnimation {
            target: playMusic
            property: "volume"
            duration: 2000
            from: 0
            to: 1
        }
    }
    Image {
        id: imgNewGame
        source: "qrc:/image/image/button_1.png"
        x: 1510
        y: 290

        Text
        {
                 id: textNewGame
                 anchors.centerIn: parent
                 font.pointSize: 20
                 color: "white"
                 font.family: "Segoe Print"
                 text: "Новая игра"
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                mainField.playM();
                windowsField.loadLevel();
                mainField.opacity = 0;
                mainField.x = mainField.width;
                mainField.z = 4
                loadlevel.running = true
            }

            onEntered: imgNewGame.source = "qrc:/image/image/buttonClicked_1.png"
            onExited: imgNewGame.source = "qrc:/image/image/button_1.png"
        }
    }

    Image {
        id: imgContinue
        source: "qrc:/image/image/button_1_blocked.png"
        x: 1510
        y: 440
        property bool enable: false
        Text
        {
                 id: textContiniue
                 anchors.centerIn: parent
                 font.pointSize: 20
                 color: "white"
                 font.family: "Segoe Print"
                 text: "Продолжить"
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: false
            onEntered: if (enable)imgContinue.source = "qrc:/image/image/buttonClicked_1.png"
            onExited: if (enable) imgContinue.source = "qrc:/image/image/button_1.png"
        }
    }

    Image {
        id: imgSettings
        source: "qrc:/image/image/button_1.png"
        x: 1510
        y: 590

        Text
        {
                 id: textSettings
                 anchors.centerIn: parent
                 font.pointSize: 20
                 color: "white"
                 font.family: "Segoe Print"
                 text: "Настройки"
        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: {
                openSettings.running = true;
            }

            onEntered: imgSettings.source = "qrc:/image/image/buttonClicked_1.png"
            onExited: imgSettings.source = "qrc:/image/image/button_1.png"
        }
    }

    Image {
        id: imgExit
        source: "qrc:/image/image/button_1.png"
        x: 1510
        y: 745

        Text
        {
                 id: textExit
                 anchors.centerIn: parent
                 font.pointSize: 20
                 color: "white"
                 font.family: "Segoe Print"
                 text: "Выход"

        }

        MouseArea {
            anchors.fill: parent
            hoverEnabled: true
            onClicked: windowsField.on_pushButton_clicked();
            onEntered: imgExit.source = "qrc:/image/image/buttonClicked_1.png"
            onExited: imgExit.source = "qrc:/image/image/button_1.png"
        }
    }
    Rectangle {
        id: settingsWindows
        x: global.width
        y: 100
        width: 800
        height: 556.467
        radius: 10
        color: "transparent"
        Image {
            anchors.fill: parent
            id: imgOptions
            source: "qrc:/settings/image/options_1.PNG"
        }
        Text
        {
                 id: setText
                 x: parent.width/2 - width/2
                 y: 50
                 font.pointSize: 20
                 color: "white"
                 font.family: "Segoe Print"
                 text: "Выберите вид кристаллов"

        }
        MouseArea {
            x: parent.width - 20
            y: 0
            width: 20
            height: 20
            id: mouseareaopt
            hoverEnabled: true
            onClicked: {
                            closeSettings.running = true;
                        }
            onEntered: imgOptions.source = "qrc:/settings/image/options_1_clicked.png";
            onExited: imgOptions.source = "qrc:/settings/image/options_1.PNG";
        }
        Rectangle {
            id: opt1
            x: parent.width/4 - width/2
            y: parent.height/2 - height/2

            width: 300
            height: 200
            radius: 10
            color: "transparent"
            Image {
                scale: 1.2
                anchors.fill: parent
                id: imgOpt1
                source: "qrc:/settings/image/collections_1_hover.png"
            }
            MouseArea {
                anchors.fill: parent
                id: mouseareaopt1
                hoverEnabled: true
                onClicked: {
                            imgOpt1.scale = 1.2;
                            imgOpt1.source = "qrc:/settings/image/collections_1_hover.png";
                            imgOpt2.scale = 1.0;
                            imgOpt2.source = "qrc:/settings/image/collections_2.png";
                            mainField.typeSkin = "crystal";
                            }
                onEntered: if (mainField.typeSkin != "crystal") imgOpt1.source = "qrc:/settings/image/collections_1_hover.png";
                onExited: if (mainField.typeSkin != "crystal") imgOpt1.source = "qrc:/settings/image/collections_1.png";
            }
        }
        Rectangle {
            id: opt2
            x: 3*parent.width/4 - width/2
            y: parent.height/2 - height/2
            width: 300
            height: 200
            radius: 10
            color: "transparent"
            Image {
                anchors.fill: parent
                id: imgOpt2
                source: "qrc:/settings/image/collections_2.png"
            }
            MouseArea {
                anchors.fill: parent
                id: mouseareaopt2
                hoverEnabled: true
                onClicked: {
                            imgOpt1.scale = 1.0;
                            imgOpt1.source = "qrc:/settings/image/collections_1.png";
                            imgOpt2.scale = 1.2;
                            imgOpt2.source = "qrc:/settings/image/collections_2_hover.png";
                            mainField.typeSkin = "skin";
                            }
                onEntered: if (mainField.typeSkin != "skin") imgOpt2.source = "qrc:/settings/image/collections_2_hover.png";
                onExited: if (mainField.typeSkin != "skin") imgOpt2.source = "qrc:/settings/image/collections_2.png";
            }
        }
    }

    ParallelAnimation{
        id: openSettings

        NumberAnimation {
            target: settingsWindows
            property: "opacity"
            duration: 500
            from: 0
            to: 1.0
        }
        NumberAnimation {
            target: settingsWindows
            property: "x"
            duration: 500
            from: imgSettings.x
            to: global.width/2 - settingsWindows.width/2
        }
        NumberAnimation {
            target: settingsWindows
            property: "y"
            duration: 500
            from: imgSettings.y
            to: global.height/2 - settingsWindows.height/2
        }
        NumberAnimation {
            target: settingsWindows
            property: "scale"
            duration: 500
            from: 0
            to: 1
        }
    }
    ParallelAnimation{
        id: closeSettings

        NumberAnimation {
            target: settingsWindows
            property: "opacity"
            duration: 500
            from: 1
            to: 0
        }
        NumberAnimation {
            target: settingsWindows
            property: "x"
            duration: 500
            from: global.width/2 - settingsWindows.width/2
            to: imgSettings.x
        }
        NumberAnimation {
            target: settingsWindows
            property: "y"
            duration: 500
            from: global.height/2 - settingsWindows.height/2
            to: imgSettings.y
        }
        NumberAnimation {
            target: settingsWindows
            property: "scale"
            duration: 500
            from: 1
            to: 0
        }
    }
}
