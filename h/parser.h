#ifndef PARSER_H
#define PARSER_H

#include "control.h"

class Parser
{
    string fileName;

    string getNextLine(fstream *file);
    string getNextWord(string *line);

    int ConvertToInt(string inStr);
public:
    Parser(string fileName);

    vector<Control> Exec();
};

#endif // PARSER_H
