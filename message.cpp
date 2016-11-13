#include "message.h"


Message::Message(){ }

void Message::showErrorMessage(const char *text)
{
    QMessageBox::warning(this,"Ошибка!", QString(text), QMessageBox::Ok);
}

void Message::showMessage(const char *text)
{
    QMessageBox helpMessage;

    helpMessage.setText(text);

    helpMessage.exec();
}

const char* Message::getFileName()
{
    const QString fileName(QFileDialog::getOpenFileName(0, "Выберите файл", "", "*.txt"));

    if(fileName.isEmpty())
        return NULL;

    return fileName.toStdString().c_str();
}
