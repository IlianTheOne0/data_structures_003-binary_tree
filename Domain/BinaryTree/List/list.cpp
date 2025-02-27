#include "list.h"

List::List(const Item& data)
	: _data(data), _next(nullptr)
{ CREATE_INFO("List <- constructor: called;"); }
List::~List()
{ CREATE_INFO("List <- destructor: called;"); }

Item List::getData() { INFO("List -> method getData: called;"); return _data; }
void List::setData(const Item& value) { INFO("List -> method setData: called;"); _data = value; }

List* List::getNext() { INFO("List -> method getNext: called;"); return _next; }
void List::setNext(List* value) { INFO("List -> method getNext: called;"); if (_next) { delete _next; } _next = value; }