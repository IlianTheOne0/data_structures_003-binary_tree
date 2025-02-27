#ifndef ITEM_H
#define ITEM_H

#include "../../../lib.h"
#include "../../../Core/core.h"
#include "fineEnum.h"

class Item
{
private:
	string _plateNumber;
	DriverFineType _fineType;
	float _amount;
public:
	Item();
	Item(const string& plateNumber, const DriverFineType& fineType, const float& amount);
	virtual ~Item();

	virtual string getPlateNumber() const;
	virtual DriverFineType getFineType() const;
	virtual string getFineType(bool indicator) const;
	virtual void setFineType(const DriverFineType& value);
	
	virtual float getAmount() const;
	virtual void setAmount(const float& value);
};

#endif