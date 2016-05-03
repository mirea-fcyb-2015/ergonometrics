#ifndef CONCRETE_CRITERION_H
#define CONCRETE_CRITERION_H

#include "criterion.h"

class ControlsCount : public Criterion
{

public:
    virtual void Calculate();
};

class Shortcuts : public Criterion
{

public:
    virtual void Calculate();
};

class DefaultValues : public Criterion
{

public:
    virtual void Calculate();
};

class Icons : public Criterion
{

public:
    virtual void Calculate();
};

class RatioTextToControl : public Criterion
{

public:
    virtual void Calculate();
};

class TabOrder : public Criterion
{

public:
    virtual void Calculate();
};

class SmallFont : public Criterion
{

public:
    virtual void Calculate();
};

class SmallFont : public Criterion
{

public:
    virtual void Calculate();
};

class UniformityOfLayout : public Criterion
{

public:
    virtual void Calculate();
};

class DiffrentControlsTypeCount : public Criterion
{

public:
    virtual void Calculate();
};

class Contrast : public Criterion
{

public:
    virtual void Calculate();
};




#endif // CONCRETE_CRITERION_H
