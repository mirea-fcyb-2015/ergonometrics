#ifndef CONCRETE_CRITERION_H
#define CONCRETE_CRITERION_H

#include "criterion.h"
#include "control.h"

class ControlsCount : public Criterion
{

public:
    virtual void Calculate()
    {
        int count = objects.size();

        for(int i = 0; i < objects.size(); i++)
            count += getChildCount(objects[i]);

        value = float(count);
    }

    int getChildCount(Control parent)
    {
        vector<Control> child = parent.getChildControls();
        int count = child.size();

        if(child.size() == 0)
            return 0;

        for(int i = 0; i < child.size(); i++)
            count += getChildCount(child[i]);

        return count;
    }


};
/*
class Shortcuts : public Criterion
{

public:
    virtual void Calculate();
};

class DefaultValues : public Criterion
{

public:
    virtual void Calculate();
};

class Icons : public Criterion
{

public:
    virtual void Calculate();
};

class RatioTextToControl : public Criterion
{

public:
    virtual void Calculate();
};

class TabOrder : public Criterion
{

public:
    virtual void Calculate();
};

class SmallFont : public Criterion
{

public:
    virtual void Calculate();
};

class UniformityOfLayout : public Criterion
{

public:
    virtual void Calculate();
};

class DiffrentControlsTypeCount : public Criterion
{

public:
    virtual void Calculate();
};

class Contrast : public Criterion
{

public:
    virtual void Calculate();
};

*/


#endif // CONCRETE_CRITERION_H
