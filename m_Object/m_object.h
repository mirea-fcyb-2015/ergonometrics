#ifndef M_OBJECT_H
#define M_OBJECT_H

#include <string>
#include <vector>
#include <fstream>
#include <iomanip>
#include <iostream>

#define BUFF_SIZE 128

using namespace std;

//Класс m_Object содержит данные о типе объекта на форме,
//координаты левого верхнего угла, значения высоты и ширины
//и коллекцию дочерних объектов.
class m_Object
{
public:
    m_Object();


    static vector<m_Object> *Parse(string fileName);//возвращает коллекцию объектов m_Odject, прочитанную из файла(с учетом иерархии)

    string getInfo();//Получаем данные об объекте в виде строки
    vector<m_Object> getChildObjects();//Возвращает копию коллекции childObjects
    void addChild(m_Object child);//Добавление объекта в коллекцию childObjects
    void setInfo(string Name, string Type, string Top, string Left, string Width, string Height);
    void setName(string Name);
    void setType(string Type);
    void setTop(string Top);
    void setLeft(string Left);
    void setWidth(string Width);
    void setHeight(string Height);
private:
    string name;
    string type;
    int top;
    int left;
    int width;
    int height;

    vector<m_Object> childObjects;
};

#endif // M_OBJECT_H
