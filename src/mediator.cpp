#include "mediator.h"


void Mediator::loadDocumentSlot(string fileName)
{
    emit loadDocumentSignal(fileName);
}

void Mediator::CalculateCriterionsSlot(uint crt)
{
    emit CalculateCriterionsSignal(crt);
}

void Mediator::getControlDetailsSlot()
{
    emit getControlDetailsSignal();
}

void Mediator::ControlDetailsSlot(vector<Control> cntrls)
{
    emit ControlDetailsSignal(cntrls);
}
