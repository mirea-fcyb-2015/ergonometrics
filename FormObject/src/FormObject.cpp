#include "FormObject.h"

FormObject::FormObject()
{
    name   = "";
    type   = "";
    top    =  0;
    left   =  0;
    width  =  0;
    height =  0;
}

void FormObject::setInfo(string Name, string Type, string Top, string Left, string Width, string Height)
{
    name   = Name;
    type   = Type;
    top    = atoi( Top.c_str() );
    left   = atoi( Left.c_str() );
    width  = atoi( Width.c_str() );
    height = atoi( Height.c_str() );
}

vector<FormObject> *FormObject::Parse(string fileName)
{
    vector<FormObject> *objects = new vector<FormObject>;
    vector<FormObject *> topObjects;
    FormObject *currentObject;
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

                currentObject = new FormObject();
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
