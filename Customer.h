#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "User.h"
using namespace std;
class Customer : public User 
{
public:
    Customer(string uname, string pwd);
    void displayInfo() const override;
};
#endif