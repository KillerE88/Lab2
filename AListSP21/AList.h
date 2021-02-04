#ifndef ALIST_H
#define ALIST_H

#include "ItemType.h"
#include <string>

using namespace std;

struct node {
	ItemType data;
	node* next;
};

class PList
{
public:
	ItemType value;
	ItemType getValue() { return value; }
	PList();
	~PList();
	void emptyList();
	bool listFull();
	int getLength();
	ItemType itemGet(ItemType item, bool& found);
	void itemPlace(ItemType item);
	void removeItem(ItemType item);
	void Reset();
	ItemType nextItem();
	PList* Union(PList* unionList, PList* list1, PList* list2);
	int findIndex(ItemType inputData);
	void display();

private:
	int length;
	int maxLength = 100;
	node* start;
	node* currentPos;
	

};

#endif // !ALIST_H

