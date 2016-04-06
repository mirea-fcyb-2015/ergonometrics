/*____________________________FormObject_add.cpp____________________________*/
/*
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

bool isIntersection(int x11, int x12, int y11, int y12, int x21, int x22, int y21, int y22)
{
    float line1_tg, line1_b, line2_tg, line2_b;
    float cross_point_x, cross_point_y;
    // y = ax + b;
    line1_tg = (y12 - y11) / (x12 - x11);
    line2_tg = (y22 - y21) / (x22 - x21);
    line1_b  = y12 - line1_tg * x12;
    line2_b  = y22 - line2_tg * x22;

    if(line1_tg == line2_tg)
        return false;

    cross_point_x = (line2_b - line1_b) / (line1_tg - line2_tg);
    cross_point_y = line1_tg * cross_point_x + line1_b;

    if( ( ((x11 < cross_point_x) && (cross_point_x < x12)) || ((x12 < cross_point_x) && (cross_point_x < x11)) ) )
        if( ( ((x21 < cross_point_x) && (cross_point_x < x22)) || ((x22 < cross_point_x) && (cross_point_x < x21)) ) )
            if( ( ((y11 < cross_point_y) && (cross_point_y < y12)) || ((y12 < cross_point_y) && (cross_point_y < y11)) ) )
                if( ( ((y21 < cross_point_y) && (cross_point_y < y22)) || ((y22 < cross_point_y) && (cross_point_y < y21)) ) )
                    return true;
    return false;

}
#endif //FormObject_add.cpp
