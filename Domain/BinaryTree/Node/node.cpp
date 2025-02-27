#include "node.h"

Node::Node(const string& plateNumber, const Item& item)
	: _plateNumber(plateNumber), _fineList(new List(item)), _leftNode(nullptr), _rightNode(nullptr)
{ CREATE_INFO("Node <- constructor: called;"); }
Node::~Node() { CREATE_INFO("Node <- destructor: called;"); delete _fineList; }

string Node::getPlateNumber() const { INFO("Node -> method getPlateNumber: called;"); return _plateNumber; }

List* Node::getFineList() const { INFO("Node -> method getFineList: called;"); return _fineList; }

Node* Node::getLeftNode() { INFO("Node -> method getLeftNode: called;"); return _leftNode; }
Node* Node::getRightNode() { INFO("Node -> method getRightNode: called;"); return _rightNode; }

void Node::setLeftNode(Node* value) { INFO("Node -> method setLeftNode: called;"); _leftNode = value; }
void Node::setRightNode(Node* value) { INFO("Node -> method setRightNode: called;"); _rightNode = value; }