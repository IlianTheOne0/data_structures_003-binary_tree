#ifndef NODE_H
#define NODE_H

// lib and core from "item.h"
#include "../List/list.h"
// DriverFineType from "item.h"

class Node
{
private:
	string _plateNumber;
	List* _fineList;

	Node* _leftNode;
	Node* _rightNode;
public:
	Node(const string& plateNumber, const Item& item);
	virtual ~Node();

	virtual string getPlateNumber() const;

	virtual List* getFineList() const;

	virtual Node* getLeftNode();
	virtual Node* getRightNode();

	virtual void setLeftNode(Node* value);
	virtual void setRightNode(Node* value);
};

#endif