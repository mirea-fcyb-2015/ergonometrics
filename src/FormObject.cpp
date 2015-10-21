/*____________________________FormObject.cpp____________________________*/
/**
    \file   FormObject.cpp
	\brief  Реализация класса объекта на форме
	\note   Класс содержит данные о геометрии объекта, список дочерних
	        объектов, а также предоставляет статические методы для 
			разбора формы .dfm
*/
#include "FormObject.h"

FormObject::FormObject()
{
    name   = "";
    type   = "";
    top    =  0;
    left   =  0;
    width  =  0;
    height =  0;
	childObjects.clear();
}

vector<FormObject> FormObject::Parse(string fileName)
{
    vector<FormObject> objects;
    vector<FormObject *> topObjects;//!< Стек объектов верхнего уровня
    FormObject *currentObject;
    fstream file;
    string word, line;
    string name, type, top, left, width, height;
    int depth = -1;

    file.open(fileName.c_str(), std::fstream::in | std::fstream::out);
    if(file.is_open()){
        while(!file.eof())
        {
            word.clear();
            name.clear();
            type.clear();
            top.clear();
            left.clear();
            width.clear();
            height.clear();

            line = getNextLine(&file);
            word = getNextWord(&line);

            static int k =0;
            std::cout << k++ << endl;

            if( word == "object" ){
                name = getNextWord(&line);
                name.erase( name.find(":"), 1 );//!< Строка объявления объекта всегда имеет формат "object Name: Type"
                type = getNextWord(&line);

                if(++depth != 0)
                    topObjects.push_back(currentObject);//!< Объект верхнего уровня на стек, работаем с дочерним

                currentObject = new FormObject();
                currentObject->setName(name);
                currentObject->setType(type);
            } else
            if( word == "item" ){
                if(++depth != 0)
                    topObjects.push_back(currentObject);

                currentObject = new FormObject();
                currentObject->setName("item");
            } else
            if( word == "end" || word == "end>" ){
                if(depth == 0){
					/// Добавляем объект верхнего уровня
                    objects.push_back(*currentObject);

                    continue;
                }

				/// Добавляем дочерний объект 
                topObjects[--depth]->addChild(*currentObject);
				
				/// Снимаем верхний объект со стека
                currentObject = topObjects[depth];
                topObjects.erase( topObjects.end() - 1 );
            } else
            if( word == "Top" ){
                word = getNextWord(&line);
                top = getNextWord(&line);

                currentObject->setTop(top);
            } else
            if( word == "Left" ){
                word = getNextWord(&line);
                left = getNextWord(&line);

                currentObject->setLeft(left);
            } else
            if( word == "Width" ){
                word = getNextWord(&line);
                width = getNextWord(&line);

                currentObject->setWidth(width);
            } else
            if( word == "Height" ){
                word = getNextWord(&line);
                height = getNextWord(&line);

                currentObject->setHeight(height);
            }
        }
        file.close();
    }

    return objects;
}

string FormObject::getNextLine(fstream *file)
{
    char buff[BUFF_SIZE];
    file->getline(buff, BUFF_SIZE);

    /// Удаление ведущх табуляций
    for(int i = 0; i < BUFF_SIZE; i++)
    {
        if( buff[i] == '\t' || buff[i] == ' ' ){
            buff[i] = ' ';
        } else
            break;
    }

    string line(buff);

    /// Удаление ведущх пробелов
    while (line[0] == ' ') {
        line.erase( line.begin() );
    }

    return line;
}

string FormObject::getNextWord(string *Line)
{
    if(Line->empty())
        return *Line;

    string line = *Line;
    char buff[BUFF_SIZE];

    line.copy(buff, line.find_first_of(" "));
    if( line.find_first_of(" ") != -1 )
        line.erase( line.begin(), line.begin() + line.find_first_of(" ") );
    else
        line.clear();

    /// Удаление ведущх пробелов
    while (line[0] == ' ') {
        line.erase( line.begin() );
    }

    *Line = line;
    string word(buff);
    return word;
}

string FormObject::getInfo()
{
    stringstream strm;
    strm << name << " " << type << " " << top << " " << left << " " << width << " " << height << endl;
    return strm.str();
}

void FormObject::setName(string Name)
{
    name = Name;
}

void FormObject::setType(string Type)
{
    type = Type;
}

void FormObject::setTop(string Top)
{
    top = atoi( Top.c_str() );
}

void FormObject::setLeft(string Left)
{
    left = atoi( Left.c_str() );
}

void FormObject::setWidth(string Width)
{
    width = atoi( Width.c_str() );
}

void FormObject::setHeight(string Height)
{
    height = atoi( Height.c_str() );
}

void FormObject::addChild(FormObject child)
{
    this->childObjects.push_back(child);
}

vector<FormObject> FormObject::getChildObjects()
{
    return childObjects;
}
