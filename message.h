#ifndef MESSAGE_H
#define MESSAGE_H


#include <QFileDialog>
#include <QMessageBox>

class Message : public QFileDialog
{
    Q_OBJECT

public:
    Message();
    virtual void showErrorMessage(const char*);
    virtual void showMessage(const char*);
    virtual const char* getFileName();

};

#endif // MESSAGE_H
