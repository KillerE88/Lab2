#ifndef ALIST_H
#define ALIST_H

#include "ItemType.h"
#include <string>

using namespace std;

class Node 
{
private:
	typedef struct node {
		ItemType data;
		node* next;
	};
	ItemType value;
	Node* Wolf;
	Node* Pup;
public:
	void setPup(Node* newPup) { Pup = newPup; }
	void setWolf(Node* newWolf) { Wolf = newWolf; }
	Node* getPup() { return Pup; }
	Node* getWolf() { return Wolf; }
	Node(ItemType newValue) { value = newValue; }
	void setValue(ItemType newValue) { value = newValue; }
	ItemType getValue() { return value; }
};
class PList
{
public:
	ItemType value;
	ItemType getValue() { return value; }
	PList();
	~PList();
	Node* Location = nullptr;
	void emptyList();
	bool listFull() const;
	int getLength();
	ItemType itemGet(ItemType item, bool& found);
	void itemPlace(ItemType item);
	void removeItem(ItemType item);
	void Reset();
	ItemType nextItem();
	PList Union(PList list1);
	PList* findIndex(int Index);
	string display();
	PList* detect(ItemType value);

private:
	int length;
	Node* head = nullptr;
	Node* tail = nullptr;
	int maxLength = 100;
	

};

#endif // !ALIST_H

