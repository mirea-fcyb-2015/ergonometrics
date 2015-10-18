#include "m_object.h"
#include <QMessageBox>
#include <sstream>

m_Object::m_Object()
{
    name   = "";
    type   = "";
    top    =  0;
    left   =  0;
    width  =  0;
    height =  0;
}

void m_Object::setInfo(string Name, string Type, string Top, string Left, string Width, string Height)
{
    name   = Name;
    type   = Type;
    top    = atoi( Top.c_str() );
    left   = atoi( Left.c_str() );
    width  = atoi( Width.c_str() );
    height = atoi( Height.c_str() );
}

vector<m_Object> *m_Object::Parse(string fileName)
{
    vector<m_Object> *objects = new vector<m_Object>;
    vector<m_Object *> topObjects;
    m_Object *currentObject;
    fstream file;
    string word;
    string name, type, top, left, width, height;
    char buff[128];
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

            file >> word;

//            QMessageBox b;
//            QString s( word.c_str() );
//            b.setText( s );
//            b.exec();

            if( word == "object" ){
                file >> name;
                name.erase( name.find(":"), 1 );
                file >> type;

                depth++;
                if(depth != 0)
                    topObjects.push_back(currentObject);


                currentObject = new m_Object();
                currentObject->setName(name);
                currentObject->setType(type);

//                QMessageBox b;
//                stringstream st;
//                string str;
//                st << depth << " " << topObjects.size();
//                st >> str;
//                QString s( (str + " " + name + " " + type).c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
            if( word == "end" ){
                if(depth == 0){
                    objects->push_back(*currentObject);

                    continue;
                }

                topObjects[--depth]->addChild(*currentObject);
                currentObject = topObjects[depth];
                topObjects.erase( topObjects.end() - 1 );

//                QMessageBox b;
//                stringstream st;
//                string str;
//                st << depth << " " << topObjects.size() << endl;
//                st >> str;
//                QString s( str.c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
            if( word == "Top" ){
                file >> word;//word += "="
                file >> top;

                currentObject->setTop(top);

//                QMessageBox b;
//                QString s( top.c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
            if( word == "Left" ){
                file >> word;//word += "="
                file >> left;

                currentObject->setLeft(left);

//                QMessageBox b;
//                QString s( left.c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
            if( word == "Width" ){
                file >> word;//word += "="
                file >> width;

                currentObject->setWidth(width);

//                QMessageBox b;
//                QString s( width.c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
            if( word == "Height" ){
                file >> word;//word += "="
                file >> height;

                currentObject->setHeight(height);

//                QMessageBox b;
//                QString s( height.c_str() );
//                b.setText( s );
//                b.exec();

                continue;
            } else
                file.getline(buff, 128);
        }
        file.close();
    }

    return objects;
}

string m_Object::getInfo()
{
    stringstream strm;
    strm << name << " " << type << " " << top << " " << left << " " << width << " " << height << endl;
    return strm.str();
}

void m_Object::setName(string Name)
{
    name = Name;
}

void m_Object::setType(string Type)
{
    type = Type;
}

void m_Object::setTop(string Top)
{
    top = atoi( Top.c_str() );
}

void m_Object::setLeft(string Left)
{
    left = atoi( Left.c_str() );
}

void m_Object::setWidth(string Width)
{
    width = atoi( Width.c_str() );
}

void m_Object::setHeight(string Height)
{
    height = atoi( Height.c_str() );
}
void m_Object::addChild(m_Object child)
{
    this->childObjects.push_back(child);
}

vector<m_Object> m_Object::getChildObjects()
{
    return childObjects;
}
