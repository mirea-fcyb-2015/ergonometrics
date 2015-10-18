#include "m_object.h"


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
    char buff[BUFF_SIZE];
    int depth = -1;

    file.open(fileName.c_str(), std::fstream::in | std::fstream::out);
//    static int k = 0, OBJcount = 0, ENDcount = 0;
    if(file.is_open()){
        while(!file.eof())
        {
//            k++;
            word.clear();
            name.clear();
            type.clear();
            top.clear();
            left.clear();
            width.clear();
            height.clear();

            file >> word;

            if( word == "object" ){
//                OBJcount++;
                file >> name;
                name.erase( name.find(":"), 1 );
                file >> type;

                if(++depth != 0)
                    topObjects.push_back(currentObject);

                currentObject = new m_Object();
                currentObject->setName(name);
                currentObject->setType(type);
            } else
            if( word == "end" ){
//                ENDcount++;
                if(depth == 0){
                    objects->push_back(*currentObject);

                    continue;
                }

                topObjects[--depth]->addChild(*currentObject);
                currentObject = topObjects[depth];
                topObjects.erase( topObjects.end() - 1 );
            } else
            if( word == "Top" ){
                file >> word;//word += "="
                file >> top;

                currentObject->setTop(top);
            } else
            if( word == "Left" ){
                file >> word;//word += "="
                file >> left;

                currentObject->setLeft(left);
            } else
            if( word == "Width" ){
                file >> word;//word += "="
                file >> width;

                currentObject->setWidth(width);
            } else
            if( word == "Height" ){
                file >> word;//word += "="
                file >> height;

                currentObject->setHeight(height);
            } else
                file.getline(buff, BUFF_SIZE);

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
