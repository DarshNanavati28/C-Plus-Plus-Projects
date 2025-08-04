#include "Admin.h"
#include <iostream>
using namespace std;
Admin::Admin(string username, string password): User(username, password) {}
void Admin::displayInfo() const 
{
    cout << "Admin User: " << getUsername() << "\n";
}