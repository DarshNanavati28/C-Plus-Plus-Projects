#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include <memory>
#include "Product.h"
using namespace std;
class Order 
{
private:
    vector<pair<shared_ptr<Product>, int>> products;
    double total = 0;
    bool paid = false;
public:
    Order();
    void addProduct(std::shared_ptr<Product> product, int quantity);
    void calculateTotal();
    void displayOrder() const;
    void markAsPaid();
};
#endif