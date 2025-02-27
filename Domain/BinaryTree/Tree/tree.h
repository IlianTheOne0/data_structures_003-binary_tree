#ifndef TREE_H
#define TREE_H

// lib and core from "item.h"
#include "../Node/node.h"
// DriverFineType from "item.h"

class BinaryTree
{
private:
	Node* _root;

	virtual string getFineList_(const Node& node);
	
	virtual Node* insert(Node* node, const Item& item);
	virtual void deleteTree(Node* node);

	virtual Node* search(Node* node, const string& plateNumber);
	virtual string printTree(Node* node);
	virtual string printRange(Node* node, const string& min, const string& max);
public:
	BinaryTree();
	virtual ~BinaryTree();

	virtual void insert(const Item& item);
	virtual void deleteTree();

	virtual string printTree();
	virtual Node* search(const string& plateNumber);
	virtual string printRange(const string& min, const string& max);
};

#endif