#ifndef CART_H
#define CART_H
#include <vector>
#include <memory>
#include <iostream>
#include <utility>
#include "Product.h"
using namespace std;
template<typename T>
class Cart 
{
    vector<pair<shared_ptr<T>, int>> items;
public:
    bool addItem(shared_ptr<T> item, int quantity) 
	{
        if (item->getStock() < quantity) 
		{
            cout << "Not enough stock for product: " << item->getName() << "\n";
            return false;
        }
        for (auto& pair : items) 
		{
            if (pair.first->getID() == item->getID()) 
			{
                if (pair.first->getStock() < pair.second + quantity) 
				{
                    cout << "Not enough stock to add more quantity for product: " << item->getName() << "\n";
                    return false;
                }
                pair.second += quantity;
                return true;
            }
        }
        items.emplace_back(item, quantity);
        return true;
    }
    void removeItem(int index) 
	{
        if (index >= 0 && index < (int)items.size())
            items.erase(items.begin() + index);
    }
    const vector<pair<shared_ptr<T>, int>>& getItems() const 
	{
        return items;
    }
    void displayCart() const 
	{
        cout << "Cart Items:\n";
        for (const auto& pair : items) 
		{
            pair.first->display();
            cout << "Quantity: " << pair.second << "\n";
            cout << "-----------------\n";
        }
    }
    double getTotal() const 
	{
        double total = 0;
        for (const auto& pair : items) 
		{
            total += pair.first->getPrice() * pair.second;
        }
        return total;
    }
};
#endif