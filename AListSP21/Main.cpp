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
	cout << "First display of lists and union" << endl;
	list1->display();
	list2->display();

	list1->Union(UnionList, list1, list2);

	UnionList->display();

	//Removing a value
	Item.Set(1);
	UnionList->removeItem(Item);
	list1->removeItem(Item);

	//second display after remove
	cout << "Second display after value was removed" << endl;
	UnionList->display();
	list1->display();

	//Empty list/Reset list
	cout << "emptied list and replaced values" << endl;
	list1->emptyList();
	list2->emptyList();

	Item.Set(2);
	list1->itemPlace(Item);

	Item.Set(4);
	list1->itemPlace(Item);

	list1->display();

	Item.Set(11);
	list2->itemPlace(Item);

	Item.Set(88);
	list2->itemPlace(Item);

	list2->display();

	//Using the findIndex funcition
	Item.Set(11);

	cout << "The node location is: " <<list2->findIndex(Item);

	return 0;
}