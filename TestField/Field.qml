import QtQuick 1.1

Rectangle {
    property int i: 10
    property int j: 15
    id: mainField
    width: 1920
    height: 1080
    anchors.fill: parent
    //Кнопка
    Connections{
        target: windowsField
        onCreateField: mainField.createField(maxI,maxJ)
    }
    Connections{
        target: windowsField
        onUpdateType: mainField.c
    }

    function createField(maxI, maxJ){
        var component;
        var childRec
        for (var i = 0; i < maxI; i++)
        {
            for (var j = 0; j < maxJ; j++)
            {
                component = Qt.createComponent("Cell.qml");
                if (component.status == Component.Ready) {
                    childRec = component.createObject(mainField);
                    childRec.objectName = "cell_" + i + "_" + j;
                    childRec.x = j*69;
                    childRec.y = i*50;
                    childRec.i = i;
                    childRec.j = j;
                    childRec.img = "qrc:/image/image/crystalGreen.png";
                }
            }
        }
    }

}

