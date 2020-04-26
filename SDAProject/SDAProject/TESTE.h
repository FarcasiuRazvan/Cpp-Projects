#pragma once
#include "set.h"
#include <assert.h>
#include "employee.h"
#include <iostream>
#include "Iterator.h"

using namespace std;

void testAll()
{
//	//TESTS FOR SET
//	Set s;
//	//test for getSize
//	assert(s.getSize() == 0);
//	employee emp("este", 748);
//
//	//test for add
//	s.add(emp);
//	assert(s.getSize() == 1);
//
//	//test for hashfunction
//	assert(s.hashFunction(emp) == 8);
//
//	//test for find
//	assert(s.find(emp) == true);
//
//	//test for getFirst the first position
//	employee emp1("este1", 740);
//	s.add(emp1);
//	assert(s.getSize() == 2);
//	assert(s.getFirst()->getElem().getName() == emp1.getName() && s.getFirst()->getElem().getTelNo() == emp1.getTelNo());
//	
//	//test for getM the dimension of the array of pointers
//	assert(s.getM() == 10);
//	
//	//test for getT the array of node pointers
//	assert(s.getT()[0]->getElem().getName() == emp1.getName() && s.getT()[0]->getElem().getTelNo() == emp1.getTelNo());
//	
//	//test for remove
//	s.remove(emp1);
//	assert(s.getSize() == 1);
//	
//	//TESTS FOR ITERATOR
//	employee emp2("este2", 741);
//	employee emp3("este3", 741);
//	s.add(emp2);
//	assert(s.getSize() == 2);
//	s.add(emp3);
//	assert(s.getSize() == 3);
//	IteratorS it(&s);
//	//test for valid
//	assert(it.valid() == true);
//	//test for getCurrentPos
//	assert(it.getCurrentPos() == 1);
//	//test for getCurrent
//	assert(it.getCurrent()->getElem().getName() == emp3.getName());
//	assert(it.getCurrent()->getElem().getTelNo() == emp3.getTelNo());
//	//tests for next
//	it.next();
//	it.next();
//	assert(it.getCurrent()->getElem().getName() == emp.getName());
//	assert(it.getCurrent()->getElem().getTelNo() == emp.getTelNo());
//	it.next();
//
//	//tests for adding and removing some elements to cover all the cases.
//	s.remove(emp2);
//	assert(s.getSize() == 2);
//	s.remove(emp3);
//	assert(s.getSize() == 1);
//	s.remove(emp);
//	assert(s.getSize() == 0);
//	s.add(emp2);
//	assert(s.getSize() == 1);
//	s.add(emp3);
//	assert(s.getSize() == 2);
//	s.remove(emp3);
//	assert(s.getSize() == 1);
//	s.add(emp3);
//	assert(s.getSize() == 2);
//	employee emp4("es", emp3.getTelNo());
//	s.add(emp4);
//	assert(s.getSize() == 3);
//	s.remove(emp3);
//	assert(s.getSize() == 2);
//	assert(s.find(emp3) == false);
}
