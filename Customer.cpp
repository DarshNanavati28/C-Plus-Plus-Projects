#include "Customer.h"
#include <iostream>
using namespace std;
Customer::Customer(std::string uname, std::string pwd): User(uname, pwd) {}
void Customer::displayInfo() const 
{
    cout << "Customer Username: " << username << "\n";
    cout << "Orders placed: " << orders.size() << "\n";
}