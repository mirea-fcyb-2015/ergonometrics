#include "configuration.h"

Configuration::Configuration(QObject *parent) : QObject(parent)
{

}

void Configuration::CalculateCriterionsSlot(uint criterion)
{
    Creator factory(criterion);

    criterions = factory.Exec();

    emit getControlsDetail();
    while(!ControlsDetailSet)
    {}

    for(int i = 0; i < criterions.size(); i++)
    {

        criterions[i]->Calculate();
    }
}

void Configuration::ControlDetails(vector<Control> cntrls)
{
    for(int i = 0; i < criterions.size(); i++)
        criterions[i]->setObjects(cntrls);

    ControlsDetailSet = true;
}

