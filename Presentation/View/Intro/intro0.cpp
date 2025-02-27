#include "../view.h"
#include "../../../Domain/domain.h"

void testAddViolation(BinaryTree& tree)
{
    tree.insert(Item("AB1234BC", DriverFineType::redLightViolation, 200.0f));

    Node* value = tree.search("AB1234BC");
    if (value != nullptr && value->getPlateNumber() == "AB1234BC" &&
        value->getFineList()->getData().getFineType() == DriverFineType::redLightViolation &&
        value->getFineList()->getData().getAmount() == 200.0f)
    { cout << "testAddViolation passed" << endl; }
    else { cout << "testAddViolation failed" << endl; }
}

void testPrintDatabase(BinaryTree& tree)
{
    string result = tree.printTree();
    
    cout << "Database content:\n" << result << endl;
    
    if (result.find("Plate: AB1234BC") != string::npos &&
        result.find("Plate: CD5678EF") != string::npos &&
        result.find("Plate: GH9012IJ") != string::npos)
    { cout << "testPrintDatabase passed" << endl; }
    else { cout << "testPrintDatabase failed" << endl; }
}

void testGetDataByCarNumber(BinaryTree& tree)
{
    Node* node = tree.search("CD5678EF");
    
    if (node != nullptr && node->getPlateNumber() == "CD5678EF" &&
        node->getFineList()->getData().getFineType() == DriverFineType::DUI &&
        node->getFineList()->getData().getAmount() == 500.0f)
    { cout << "testGetDataByCarNumber passed" << endl; }
    else { cout << "testGetDataByCarNumber failed" << endl; }
}

void testGetDataByRange()
{
    BinaryTree tree;

    tree.insert(Item("AA0000AA", DriverFineType::speeding, 100.0f));
    tree.insert(Item("BB1111BB", DriverFineType::DUI, 300.0f));
    tree.insert(Item("BB1111BB", DriverFineType::expiredRegistration, 1000.0f));
    tree.insert(Item("CC2222CC", DriverFineType::illegalParking, 150.0f));
    tree.insert(Item("DD3333DD", DriverFineType::redLightViolation, 200.0f));
    tree.insert(Item("EE4444EE", DriverFineType::cellPhoneUse, 120.0f));
    tree.insert(Item("FF5555FF", DriverFineType::expiredRegistration, 80.0f));

    string result = tree.printRange("BB1111BB", "EE4444EE");

    cout << "Data in range [BB1111BB, EE4444EE]:\n" << result << endl;

    if (result.find("Plate: BB1111BB") != string::npos &&
        result.find("Plate: CC2222CC") != string::npos &&
        result.find("Plate: DD3333DD") != string::npos &&
        result.find("Plate: AA0000AA") == string::npos &&
        result.find("Plate: EE4444EE") != string::npos &&
        result.find("Plate: FF5555FF") == string::npos)
    { cout << "testGetDataByRange passed" << endl; }
    else { cout << "testGetDataByRange failed" << endl; }
}


void View::Intro0() {
    BinaryTree tree;

    tree.insert(Item("AB1234BC", DriverFineType::speeding, 100.0f));
    tree.insert(Item("CD5678EF", DriverFineType::DUI, 500.0f));
    tree.insert(Item("GH9012IJ", DriverFineType::illegalParking, 50.0f));

    testAddViolation(tree);
    testPrintDatabase(tree);
    testGetDataByCarNumber(tree);
    testGetDataByRange();
}