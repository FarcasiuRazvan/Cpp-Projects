#pragma once
#include "employee.h"

class node
{
private:
	employee elem;
	node* next;
public:
	node() {};
	node(employee &el, node* ne) { this->elem = el; this->next = ne; };
	~node() {};

	employee getElem() { return this->elem; }
	node* getNext() { return this->next; };

	void setNext(node* elem) { this->next = elem; }
	void setElem(employee elem) { this->elem = elem; }
	
	void setNameEmployee(std::string name) { this->elem.setName(name); };
	void setTelNoEmployee(int n) { this->elem.setTelNo(n); };
};