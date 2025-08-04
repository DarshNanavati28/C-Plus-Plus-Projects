#ifndef USER_H
#define USER_H
#include <string>
#include <vector>
#include <memory>
#include "Order.h"
using namespace std;
class User 
{
protected:
    string username;
    string password;
    vector<shared_ptr<Order>> orders;
public:
    User(string uname, string pwd);
    virtual ~User() = default;
    string getUsername() const;
    bool authenticate(const string& pwd) const;
    void addOrder(std::shared_ptr<Order> order);
    void listOrders() const;
    virtual void displayInfo() const = 0;
};
#endif