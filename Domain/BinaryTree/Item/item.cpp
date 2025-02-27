#include "item.h"

Item::Item() { CREATE_INFO("Item <- Default constructor: called;"); }
Item::Item(const string& plateNumber, const DriverFineType& fineType, const float& amount)
	: _plateNumber(plateNumber), _fineType(fineType), _amount(amount)
{ CREATE_INFO("Item <- constructor: called;"); }
Item::~Item() { CREATE_INFO("Item <- destructor: called;"); }


string Item::getPlateNumber() const { INFO("Item -> method getPlateNumber: called;"); return _plateNumber; }
DriverFineType Item::getFineType() const { INFO("Item -> method getFineType (DriverFineType): called;"); return _fineType; }
string Item::getFineType(bool indicator) const
{
    INFO("Item -> method getFineType (string): called;");

    switch (_fineType)
    {
        case DriverFineType::speeding: { return "Speeding"; }
        case DriverFineType::redLightViolation: { return "Red Light Violation"; }
        case DriverFineType::illegalParking: { return "Illegal Parking"; }
        case DriverFineType::recklessDriving: { return "Reckless Driving"; }
        case DriverFineType::DUI: { return "DUI"; }
        case DriverFineType::seatbeltViolation: { return "Seatbelt Violation"; }
        case DriverFineType::cellPhoneUse: { return "Cell Phone Use"; }
        case DriverFineType::expiredRegistration: { return "Expired Registration"; }
        default: { return "Unknown Fine Type"; }
    }
}

void Item::setFineType(const DriverFineType& value) { INFO("Item -> method setFineType: called;"); _fineType = value; }

float Item::getAmount() const { INFO("Item -> method getAmount: called;"); return _amount; }
void Item::setAmount(const float& value) { INFO("Item -> method setAmount: called;"); _amount = value; }