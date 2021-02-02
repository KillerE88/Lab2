#include "AList.h"
#include <iostream>

using namespace std;

int main()
{
	PList list1;
	PList list2;

	ItemType Item;

	Item.Set(1);

	list1.itemPlace(Item);

	cout << Item.Get();

	cout << "List: " << list1.nextItem();

	return 0;
}