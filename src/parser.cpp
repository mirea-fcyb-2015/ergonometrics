#include "parser.h"

Parser::Parser(string fileName)
{
    this->fileName = fileName;
}

vector<Control> Parser::Exec()
{
    vector<Control> controls;
    vector<Control*> topLevelControls;
    Control *currentControl = NULL;

    string word, line;
    string name, type, top, left, width, height;
    int depth = -1;

    fstream file;
    file.open(fileName.c_str(), fstream::in | fstream::out);
    if(!file.is_open())
    {
        controls.clear();
        return controls;
    }

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
                    topLevelControls.push_back(currentControl);//!< Объект верхнего уровня на стек, работаем с дочерним

                currentControl = new Control();
                currentControl->setName(name);
                currentControl->setType(type);
        } else if( word == "item" ){
                if(++depth != 0)
                    topLevelControls.push_back(currentControl);

                currentControl = new Control();
                currentControl->setName("item");
        } else if( word == "end" || word == "end>" ){
                if(depth == 0){
                    /// Добавляем объект верхнего уровня
                    controls.push_back(*currentControl);

                    continue;
                }

                /// Добавляем дочерний объект
                topLevelControls[--depth]->addChild(*currentControl);

                /// Снимаем верхний объект со стека
                currentControl = topLevelControls[depth];
                topLevelControls.erase( topLevelControls.end() - 1 );
        } else if( word == "Top" ){
                word = getNextWord(&line);
                top = getNextWord(&line);

                currentControl->setTop(ConvertToInt(top));
        } else if( word == "Left" ){
                word = getNextWord(&line);
                left = getNextWord(&line);

                currentControl->setLeft(ConvertToInt(left));
        } else if( word == "Width" ){
                word = getNextWord(&line);
                width = getNextWord(&line);

                currentControl->setWidth(ConvertToInt(width));
        } else if( word == "Height" ){
                word = getNextWord(&line);
                height = getNextWord(&line);

                currentControl->setHeight(ConvertToInt(height));
        }
    }

    return controls;
}

string Parser::getNextLine(fstream *file)
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

string Parser::getNextWord(string *Line)
{
    if(Line->empty())
        return *Line;

    string line = *Line;
    char buff[BUFF_SIZE];
    memset(buff, 0, sizeof(char)*BUFF_SIZE);

    line.copy(buff, line.find_first_of(" "));
    if( line.find_first_of(" ") != -1 )
        line.erase( line.begin(), line.begin() + line.find_first_of(" ") );
   // else
        //line.clear();

    /// Удаление ведущх пробелов
    while (line[0] == ' ') {
        line.erase( line.begin() );
    }

    *Line = line;
    string word(buff);
    return word;
}

int Parser::ConvertToInt(string inStr)
{
    std::stringstream stream;
    int out = 0;

    stream << inStr;
    stream >> out;

    return out;
}
