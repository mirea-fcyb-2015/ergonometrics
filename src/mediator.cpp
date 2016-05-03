#include "mediator.h"


void Mediator::loadDocumentSlot(string fileName)
{
    emit loadDocumentSignal(fileName);
}
