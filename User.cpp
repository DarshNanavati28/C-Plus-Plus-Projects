#include "User.h"
#include <iostream>
using namespace std;
User::User(string uname, string pwd): username(uname), password(pwd) {}
string User::getUsername() const 
{
    return username;
}
bool User::authenticate(const string& pwd) const 
{
    return pwd == password;
}
void User::addOrder(shared_ptr<Order> order) 
{
    orders.push_back(order);
}
void User::listOrders() const 
{
    cout << "Order history for " << username << ":\n";
    for (const auto& order : orders) 
	{
        order->displayOrder();
        cout << "------------------\n";
    }
}