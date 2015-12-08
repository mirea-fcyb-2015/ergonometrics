/*____________________________FormObject_add.cpp____________________________*/
/**
    Файл содержащий дополнительные функции.
*/
#ifndef __FORMOBJECT_ADD_INCLUDED_
#define __FORMOBJECT_ADD_INCLUDED_


#include "FormObject.h"
#include "FormObject.cpp"

int FormObject::getCountElements()
{
    int cntElements = 0;
    if(this->childObjects.size() > 0)
        for(int i = 0; i < childObjects.size(); i++)
            cntElements += childObjects[i].getCountElements;
    else
        cntElements = 1;

    return cntElements;
}

void FormObject::setCountElements()
{
     countElements = getCountElements();
}


#endif