#ifndef MESSAGE_H
#define MESSAGE_H

#include "b_message.h"

#include <QFileDialog>
#include <QMessageBox>

class Message : public QFileDialog, public B_Message
{
    Q_OBJECT

public:
    Message();
    virtual void showErrorMessage(const char*);
    virtual void showMessage(const char*);
    virtual const char* getFileName();

};

#endif // MESSAGE_H
