#ifndef ADMIN_H
#define ADMIN_H
#include "User.h"
#include <string>
using namespace std;
class Admin : public User 
{
public:
    Admin(string username, string password);
    void displayInfo() const override;
};
#endif