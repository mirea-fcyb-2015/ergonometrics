#include "control.h"

void Control::setTop(int val)
{
    top = val;
}

void Control::setLeft(int val)
{
    left = val;
}

void Control::setWidth(int val)
{
    width = val;
}

void Control::setHeight(int val)
{
    height = val;
}

void Control::setName(string val)
{
    name = val;
}

void Control::setType(string val)
{
    type = val;
}

void Control::addChild(Control child)
{
    childControls.push_back(child);
}

vector<Control> Control::getChildControls()
{
    return childControls;
}
