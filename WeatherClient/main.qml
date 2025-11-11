import QtQuick
import QtQuick.Controls

Window {
    visible: true
    width: 400
    height: 200
    title: "Thrift + Qt Example"

    Column {
        anchors.centerIn: parent
        spacing: 10

        TextField {
            id: cityField
            placeholderText: "Enter city name"
        }

        Button {
            text: "Get Temperature"
            onClicked: {
                const temp = weatherManager.getTemperature(cityField.text)
                resultLabel.text = `Temperature: ${temp.toFixed(1)}°C`
            }
        }

        Label {
            id: resultLabel
            color: "black"
        }
    }
}
