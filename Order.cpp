#include "Order.h"
#include <iostream>
using namespace std;
Order::Order() {}
void Order::addProduct(std::shared_ptr<Product> product, int quantity) 
{
    products.push_back({product, quantity});
}
void Order::calculateTotal() 
{
    total = 0;
    for (auto& item : products) 
	{
        total += item.first->getPrice() * item.second;
    }
}
void Order::displayOrder() const 
{
    cout << "Order Details:\n";
    for (const auto& item : products) 
	{
        cout << item.first->getName() << " x" << item.second << " = $" 
             << item.first->getPrice() * item.second << "\n";
    }
    cout << "Total: $" << total << "\n";
    cout << "Status: " << (paid ? "Paid" : "Unpaid") << "\n";
}
void Order::markAsPaid() 
{
    paid = true;
}