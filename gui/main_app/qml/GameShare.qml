import QtQuick 2.15
import QtQuick.Controls 2.15

Item {
    width: 1280
    height: 720
    Rectangle {
        anchors.fill: parent
        color: "brown"

        Dialog {
            id: addGameDialog
            modal: true
            title: "Add Game"

            function checkInput() {
                buttons.standardButton(Dialog.Ok).enabled = code.acceptableInput && name.acceptableInput && description.acceptableInput
            }

            contentItem: Column {
                TextField {
                    id: code
                    placeholderText: qsTr("Enter code")
                    validator: RegularExpressionValidator { regularExpression: /[0-9A-Z]+/ }
                    onEditingFinished: addGameDialog.checkInput()
                }

                TextField {
                    id: name
                    placeholderText: qsTr("Enter name")
                    validator: RegularExpressionValidator { regularExpression: /[0-9A-Z]+/ }
                    onEditingFinished: addGameDialog.checkInput()
                }

                TextField {
                    id: description
                    placeholderText: qsTr("Enter description*")
                    validator: RegularExpressionValidator { regularExpression: /[0-9A-Z]+/ }
                    onEditingFinished: addGameDialog.checkInput()
                }
            }

            footer: DialogButtonBox {
                 id: buttons
                 standardButtons: Dialog.Ok | Dialog.Cancel
            }
            onOpened: addGameDialog.checkInput()
            onAccepted: backend_interface.add_game(code.text, name.text, description.text)
            onRejected: {}
        }

        Dialog {
            id: addUserDialog
            modal: true
            title: "Add User"

            function checkInput2() {
                buttonsu.standardButton(Dialog.Ok).enabled = nameu.acceptableInput && age.acceptableInput
            }

            contentItem: Column {
                TextField {
                    id: nameu
                    placeholderText: qsTr("Enter name")
                    validator: RegularExpressionValidator { regularExpression: /[0-9A-Z]+/ }
                    onEditingFinished: addUserDialog.checkInput2()
                }

                TextField {
                    id: age
                    placeholderText: qsTr("Enter age")
                    validator: IntValidator{bottom: 0; top: 120;}
                    onEditingFinished: addUserDialog.checkInput2()
                }
            }

            footer: DialogButtonBox {
                 id: buttonsu
                 standardButtons: Dialog.Ok | Dialog.Cancel
             }

            onOpened: checkInput2()
            onAccepted: backend_interface.add_user(nameu.text, parseInt(age.text))
            onRejected: {}
        }

        Row {
            width: 800
            anchors.centerIn: parent
            Column {
                width: 200
                height: 400
                Button {
                    text: "Add Game"
                    onClicked: addGameDialog.open()
                }

                Button {
                    text: "Add User"
                    onClicked: addUserDialog.open()
                }

                Button {
                    text: "Delete Game"
                }

                Button {
                    text: "Change Game Name"
                }
            }
            ListView {
                id: usersList
                model: backend_interface.get_users()
                width: 200
                height: 400
                header: Text {
                    text: "Users"
                }
                delegate: Text {
                    text: modelData
                }
            }
            ListView {
                id: gamesList
                model: backend_interface.get_games()
                width: 200
                height: 400
                header: Text {
                    text: "Games"
                }
                delegate: Text {
                    text: modelData
                }
            }
        }
    }

}
