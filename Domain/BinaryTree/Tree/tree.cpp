#include "tree.h"

string BinaryTree::getFineList_(const Node& node)
{
	string result;
	List* fineList = node.getFineList();

	while (fineList) { result += "\n   " + fineList->getData().getFineType(true) + " (" + to_string(fineList->getData().getAmount()) + " UAH)"; fineList = fineList->getNext(); }
	result += '\n';
	return result;
}

Node* BinaryTree::insert(Node* node, const Item& item)
{
	INFO("BinaryTree -> method insert: called;");

	if (!node) { return new Node(item.getPlateNumber(), item); }

	if (item.getPlateNumber() < node->getPlateNumber()) { INFO("BinaryTree -> method insert -> leftNode: processing;"); node->setLeftNode(insert(node->getLeftNode(), item)); }
	else if (item.getPlateNumber() > node->getPlateNumber()) { INFO("BinaryTree -> method insert -> rightNode: processing;"); node->setRightNode(insert(node->getRightNode(), item)); }
	else
	{
		INFO("BinaryTree -> method insert -> new List: processing;");

		List* fineList = node->getFineList();

		while (fineList->getNext()) { fineList = fineList->getNext(); }
		fineList->setNext(new List(item));
	}

	return node;
}
void BinaryTree::deleteTree(Node* node)
{
	INFO("BinaryTree -> method deleteTree: called;");

	if (!node) { return; }

	deleteTree(node->getLeftNode());
	deleteTree(node->getRightNode());

	delete node;
}

Node* BinaryTree::search(Node* node, const string& plateNumber)
{
	INFO("BinaryTree -> method search: called;");

	if (!node || node->getPlateNumber() == plateNumber) { return node; }
	
	if (plateNumber < node->getPlateNumber()) { return search(node->getLeftNode(), plateNumber); }
	else { return search(node->getRightNode(), plateNumber); }
}

string BinaryTree::printTree(Node* node)
{
	INFO("BinaryTree -> method printTree: called;");

	if (!node) { return ""; }

	printTree(node->getLeftNode());

	string result;
	result += node->getPlateNumber() + ": " + getFineList_(*node) + printTree(node->getRightNode());

	return result;
}
string BinaryTree::printRange(Node* node, const string& min, const string& max)
{
	INFO("BinaryTree -> method printRange: called;");

	if (!node) { return ""; }
	
	string result;
	if (min < node->getPlateNumber()) { result += printRange(node->getLeftNode(), min, max); }
	if (min <= node->getPlateNumber() && node->getPlateNumber() <= max) { result += node->getPlateNumber() + ": " + getFineList_(*node); }
	if (max > node->getPlateNumber()) { result += printRange(node->getRightNode(), min, max); }

	return result;
}

BinaryTree::BinaryTree()
	: _root(nullptr)
{ CREATE_INFO("BinaryTree <- Default constructor: called;"); }
BinaryTree::~BinaryTree() { CREATE_INFO("BinaryTree <- destructor: called;"); deleteTree(); }

void BinaryTree::insert(const Item& item) { _root = insert(_root, item); }
void BinaryTree::deleteTree() { return deleteTree(_root); _root = nullptr; }

Node* BinaryTree::search(const string& plateNumber) { return search(_root, plateNumber); }
string BinaryTree::printTree() { return printTree(_root); }
string BinaryTree::printRange(const string& min, const string& max) { return printRange(_root, min, max); }