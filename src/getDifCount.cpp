#include "FormObject.h"

static int FormObject::getDifferentTypesCount(FormObject *form)
{
	int count = 0;
	FormObject current = *form;
	std::vector<FormObject> allObjects;

	do{
		allObjects.push_back(current);
		std::vector<FormObject> currentChild = current.getChildObjects();
		for(int i = 0; i < currentChild.size(); i++){
			allObjects.push_back(currentChild.at(i));

			current = currentChild.at(i);
		}

	} while( current.getChildObjects().size() != 0 );

	return count;
}
