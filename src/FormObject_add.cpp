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
        for(int i = 0; i < this->childObjects.size(); i++)
            cntElements += this->childObjects[i].getCountElements();
    else
        cntElements = 1;

    return cntElements;
}

float FormObject::getNegativeSpace()
{
    int sizeThisElement = width * height;
    int sizeElements    = 0;
    for(int i = 0; i < this->childObjects.size(); i++)
        sizeElements += (this->childObjects[i].width * this->childObjects[i].height);
    return (float)(100 * sizeElements / sizeThisElement); //возвращаемое значение в процентах
}

void FormObject::setCountElements()
{
     countElements = getCountElements();
}


#endif //FormObject_add.cpp
