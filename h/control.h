#ifndef CONTROL_H
#define CONTROL_H

#include <string>
#include <vector>

#include <fstream>
#include <sstream>

#include <iomanip>
#include <iostream>

#define BUFF_SIZE 512

using namespace std;

class Control
{
    string name;
    string type;

    int top;
    int left;
    int width;
    int height;

    bool defaultValue = false;
    bool shortcut = false;

    vector<Control> childControls;
public:
    vector<Control> getChildControls();

    void setTop(int val);
    void setLeft(int val);
    void setWidth(int val);
    void setHeight(int val);
    void setName(string val);
    void setType(string val);

    void addChild(Control child);
};

#endif // CONTROL_H
