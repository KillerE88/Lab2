#include "AList.h"
#include <iostream>

using namespace std;

int main()
{
	PList* list1 = new PList;
	PList* list2 = new PList;
	PList* UnionList = new PList;

	ItemType Item;
	//list1 setting
	Item.Set(1);
	list1->itemPlace(Item);

	Item.Set(5);
	list1->itemPlace(Item);

	Item.Set(9);
	list1->itemPlace(Item);
	//list2 setting
	Item.Set(3);
	list2->itemPlace(Item);

	Item.Set(5);
	list2->itemPlace(Item);

	Item.Set(8);
	list2->itemPlace(Item);

	cout << Item.Get() << endl;
	//Display of both lists then combined
	list1->display();
	list2->display();

	list1->Union(UnionList, list1, list2);

	UnionList->display();

	//Removing a value
	Item.Set(1);
	list1->removeItem(Item);

	//second display after remove
	list1->Union(UnionList, list1, list2) ->display();



	return 0;
}