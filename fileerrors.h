#ifndef FILEERRORS_H
#define FILEERRORS_H

#include "b_error.h"

class E_OpenFile : public B_Error
{
public:
    virtual const char* info()
    {
        return "Can't open file!";
    }
};

class E_ReadFile : public B_Error
{
public:
    virtual const char* info()
    {
        return "File is incorrect!";
    }
};

#endif // FILEERRORS_H
