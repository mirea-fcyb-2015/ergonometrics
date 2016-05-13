#ifndef CREATOR_H
#define CREATOR_H

#include <vector>
#include "concrete_criterion.h"

using namespace std;

class Creator
{
    unsigned int criterions;
public:
    Creator(unsigned int crt);

    vector<Criterion *> Exec();
};

#endif // CREATOR_H
