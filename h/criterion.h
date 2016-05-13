#ifndef CRITERION_H
#define CRITERION_H

#include <vector>
#include "control.h"

class Criterion
{
public:
    std::vector<Control> objects;
    float value = 0;

    void setObjects(std::vector<Control> obj)
    {
        objects = obj;
    }

    virtual void Calculate() = 0;

};

#endif // CRITERION_H
