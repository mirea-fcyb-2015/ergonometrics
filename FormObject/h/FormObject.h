/*____________________________FormObject.h____________________________*/
/**
    \file   FormObject.h
	\brief  Описание класса объекта на форме
	\note   Класс содержит данные о геометрии объекта, список дочерних
	        объектов, а также предоставляет статические методы для 
			разбора формы .dfm
*/
#ifndef FORMOBJECT_H
#define FORMOBJECT_H

#include <string>
#include <vector>

#include <fstream>
#include <sstream>

#include <iomanip>
#include <iostream>

#define BUFF_SIZE 512

using namespace std;

//! Класс FormObject содержит данные о типе объекта на форме,
//! координаты левого верхнего угла, значения высоты и ширины
//! и коллекцию дочерних объектов.
class FormObject
{
private:
    string name;
    string type;
	
    int top;
    int left;
    int width;
    int height;

    vector<FormObject> childObjects;

    static string getNextLine(fstream *file);
    static string getNextWord(string *line);
public:
    FormObject();

	/**
	    \fn      static vector<FormObject> *Parse( string fileName )
		\brief   Функция разбирает входной файл формы .dfm
		\param   fileName - полный путь к форме
		\return  Возвращает указатель на коллекцию объектов верхнего уровня
		\note    В возвращаемой коллекции содержатся объекты верхнего уровня.
		         Как правило, это только объект формы. Дочерние объекты записываются
				 в коллекции childObjects соответствующих объектов.
	*/
    static vector<FormObject> Parse(string fileName);
	
    ///Возвращает данные об объекте в виде строки
    string getInfo();
	
	///Возвращает копию коллекции childObjects
    vector<FormObject> getChildObjects();
	
	///Добавление копии объекта в коллекцию childObjects
    void addChild(FormObject child);
	
	/**
	    \fn       void setName(string Name)
                  void setType(string Type)
                  void setTop(string Top)
                  void setLeft(string Left)
                  void setWidth(string Width)
                  void setHeight(string Height)
	    \brief    Set-методы
        \note     Все функции получают на вход строковые данные(тип std::string) 		          
	*/
    void setName(string Name);
    void setType(string Type);
    void setTop(string Top);
    void setLeft(string Left);
    void setWidth(string Width);
    void setHeight(string Height);
};

#endif // FormObject_H
