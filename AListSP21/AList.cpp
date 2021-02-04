#include <iostream>
#include "AList.h"
#include "ItemType.h"
using namespace std;

PList::PList() {
	length = 0;
	start = nullptr;
	currentPos = nullptr;
}
PList::~PList() {
	emptyList();
}
ItemType PList::findIndex(ItemType inputData) { //This function is used to find the value in the index
	node* item = start;
	bool found = false;
	int counter = 0;

	while (item != NULL) 
	{
		if (item->data.ComparedTo(inputData) == EQUAL)//while loop to advance the pointer till the end of the list
		{
			found = true;
			return item->data;
		}
		else
			item = item->next;
	}
}
void PList::removeItem(ItemType value) { //Used to remove unwanted items
	node* item = start;
	node* itemTrailer = nullptr;
	if (item->data.ComparedTo(value) == EQUAL) {
		if (start->next != NULL) {
			itemTrailer = start->next;
			start = itemTrailer;
			delete item;
		}
		else {
			delete item;
			start = NULL;
		}
	}
	else {
		while (item != NULL) {
			if (item->data.ComparedTo(value) == EQUAL) {
				itemTrailer->next = item->next;
				delete item;
			}
			else {
				itemTrailer = item;
				item = item->next;
			}
		}
	}
	length--;
}
void PList::itemPlace(ItemType value) //used to place new value within the index
{
	node* temp = start;

	if (listFull() == true) //Checking if list is full
	{
		return;
	}
	if (start == NULL) { //creating a new list
		temp = new node;
		temp->data = value;
		temp->next = NULL;
		start = temp;
	}
	else { //Adding an item in to list if not full or created a new list
		temp = new node;
		temp->data = value;
		temp->next = start;
		start = temp;
	}
	length++;
	currentPos = temp;
}

bool PList::listFull() {
	if (length == maxLength) {
		return true;
	}
	else {
		return false;
	}

}

int PList::getLength() 
{
	return length;
}
void PList :: emptyList() //this will empty all of the unwanted storage
{
	node* temp;
	node* trailerValue;
	temp = start;
	trailerValue = NULL;
	while (start != NULL)
	{
		if (temp -> next == NULL)
		{
			removeItem(temp->data);
		} else
		{
			trailerValue = temp;
			temp = temp->next;
			removeItem(trailerValue -> data);
		}
	}
}


PList* PList::Union(PList* joinListPtr, PList* list1, PList* list2) {
	node *temp1 = list1->start, *temp2 = list2->start; //These are iterators (moving throught the list) for list 1 and 2 respectively.
	bool match; //checks for a true or false

	//Runner iterators scan ahead through the list to find duplicates.
	node* temp1Runner = temp1->next;
	while (temp1 != NULL) { //Item to be added to unionList if a duplicate is not found.
		match = false; //setting to false to find a match
		temp1Runner = temp1->next;
		while (temp1Runner != NULL) { //Scan through the rest of list1 looking for duplicate items.
			if (temp1->data.ComparedTo(temp1Runner->data) == EQUAL) {
				match = true; //set true for finding a match
			}
			temp1Runner = temp1Runner->next; //Looking through list (aka position in list)
		}

		if (match == false) { //adds unique elements from list1 to the unionList. //addes value from position into new list
			joinListPtr->itemPlace(temp1->data);
		}

		temp1 = temp1->next; //list1 = list1->next
	}

	node* unionListRunner = joinListPtr->start;
	while (temp2 != NULL) { //item to be added to the unionList from list2. //copy from above but for list2
		match = false;
		unionListRunner = joinListPtr->start;
		while (unionListRunner != NULL) { //Pointer to second list.
			if (temp2->data.ComparedTo(unionListRunner->data) == EQUAL) {
				match = true;
			}

			unionListRunner = unionListRunner->next;
		}

		if (match == false) {
			joinListPtr->itemPlace(temp2->data);
		}

		temp2 = temp2->next;
	}

	return joinListPtr; //returns pointer to the head of the list
}

void PList :: display()
{
	node* temp;
	temp = start;
	while (temp != NULL) 
	{
		cout << (*temp).data.Get() << " ";//pointless use -> instead 
		temp = temp->next;
	}
	cout << "\n";
	/*string Alpha = "";
	for (int i = 0; i < length; i++)
	{
		Alpha += " " + to_string(findIndex(i)->getValue().getValue());
	}
	return Alpha;*/
}


