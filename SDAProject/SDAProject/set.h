#pragma once
#include "TNode.h"
#include <vector>

class Set
{
private:
	node* T[10];
	int m=10;
	int size=0;

	int getM() { return this->m; }
	friend class IteratorS;
	node* getFirst() { return this->T[0]; }

	node** getT() { return this->T; }
	int hashFunction(employee &elem) { return elem.getTelNo() % this->m; };

public:
	Set() { for (int i = 0; i < m; i++) { employee emp("", NULL); T[i] = new node(emp, nullptr); } };
	~Set() {};
	//Set() : m(10), size(0) {};
	
	
	void add(employee &elem);
	void remove(employee &elem);
	bool find(employee &elem);

	int getSize() { return this->size; }
};