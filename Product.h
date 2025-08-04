#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
using namespace std;
class Product 
{
protected:
    string name;
    double price;
    int productID;
    int stock;
public:
    Product(string n, double p, int id, int s);
    virtual ~Product();
    virtual void display() const = 0;
    double getPrice() const;
    int getID() const;
    string getName() const;
    int getStock() const;
    void reduceStock(int qty);
    void increaseStock(int qty);
};
#endif