#ifndef CRITERION_H
#define CRITERION_H

class Criterion
{
    int value = 0;
public:
    virtual void Calculate() = 0;
};

#endif // CRITERION_H
