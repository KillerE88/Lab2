#include "AList.h"
using namespace std;

PList* PList::findIndex(int Index) { //This function is used to find the value in the index
	Node* item = nullptr;
	for (int i = 0; i < length; i++)
	{
		if (i == 0)
			item = head;
		else
			item = item->getPup();
		if (i == Index)
			return item->data;
	}
	return nullptr;
}
void PList::removeItem(ItemType value) { //Used to remove unwanted items
	Node* found = detect(value);
	if (found == nullptr) return;
	if (length == 1) {
		delete findIndex(0);
		head = nullptr;
		tail = nullptr;
		length = 0;
		return;
		
	}
	if (found == tail)
	{
		found->getWolf()->setPup(nullptr);
		tail = found->getWolf();
	}

	else if (found == head) 
	{
		head = found->getPup();
		found->getPup()->setWolf(nullptr);
	}
	else
	{
		found->getWolf()->setPup(found->getPup());
		found->getPup()->setWolf(found->getWolf());
	}
	delete found;
	length--;
}
void PList::itemPlace(ItemType value) //used to place new value within the index
{
	if (length == maxLength) return;
	Node* nItem = new Node(value);
	if (head == nullptr)
	{
		head = nItem;
		Location = head;
		tail = nItem;
	}
	else
	{
		nItem->setWolf(tail);
		tail->setPup(nItem);
	}
	tail = nItem;
	tail->setPup(nItem);
}

PList* PList::detect(ItemType Value) { //used to find a value within index
	for (int i = 0; i < length; i++)
	{
		PList* cItem = findIndex(i);

		if (cItem->getValue().ComparedTo(Value) == EQUAL)
			return cItem;
	}
}

int PList::getLength() 
{
	return length;
}
void PList :: emptyList() //this will empty all of the unwanted storage
{
	while (getLength() > 0) 
	{
		removeItem(findIndex(0)->getValue());
	}
}
PList PList :: Union(PList list1) 
{
	PList newPList = PList();
	Node* item = nullptr;
	for (int i = 0; i < getLength(); i++)
	{
		if (item == nullptr)
			item = head;
		else
			item = item->getPup();

		if (newPList.detect(item->getValue()) == nullptr)
			newPList.itemPlace(item->getValue());
	}
	return newPList;

}
string PList :: display()
{
	string Alpha = "";
	for (int i = 0; i < length; i++)
	{
		Alpha += " " + to_string(findIndex(i)->getValue().getValue());
	}
	return Alpha;
}


