#include "creator.h"

using namespace std;

Creator::Creator(unsigned int crt)
{
    this->criterions = crt;
}

vector<Criterion *> Creator::Exec()
{
    vector<Criterion *> out;

    if(criterions & 1)
        out.push_back(new ControlsCount);
/*
    if(criterions & (1 << 1))
        out.push_back(new Shortcuts);

    if(criterions & (1 << 2))
        out.push_back(new DefaultValues);

    if(criterions & (1 << 3))
        out.push_back(new Icons);

    if(criterions & (1 << 4))
        out.push_back(new RatioTextToControl);

    if(criterions & (1 << 5))
        out.push_back(new TabOrder);

    if(criterions & (1 << 6))
        out.push_back(new SmallFont);

    if(criterions & (1 << 7))
        out.push_back(new UniformityOfLayout);

    if(criterions & (1 << 8))
        out.push_back(new DiffrentControlsTypeCount);

    if(criterions & (1 << 9))
        out.push_back(new Contrast);*/

  //  if(criterions & (1 << 10))
  //      out.push_back(new );
    return out;
}
