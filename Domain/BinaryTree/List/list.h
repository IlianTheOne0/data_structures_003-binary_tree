#ifndef LIST_H
#define LIST_H

// lib and core from "item.h"
#include "../Item/item.h"
// DriverFineType from "item.h"

class List
{
private:
	Item _data;

	List* _next;
public:
	List() = delete;
	List(const Item& data);
	virtual ~List();

	virtual Item getData();
	virtual void setData(const Item& value);

	virtual List* getNext();
	virtual void setNext(List* value);
};

#endif