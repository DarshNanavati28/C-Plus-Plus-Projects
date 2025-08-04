#include "Product.h"
#include <stdexcept>
using namespace std;
Product::Product(string n, double p, int id, int s): name(n), price(p), productID(id), stock(s) {}
Product::~Product() {}
double Product::getPrice() const { return price; }
int Product::getID() const { return productID; }
string Product::getName() const { return name; }
int Product::getStock() const { return stock; }
void Product::reduceStock(int qty) 
{
    if (qty > stock) 
	{
        throw runtime_error("Not enough stock available!");
    }
    stock -= qty;
}
void Product::increaseStock(int qty) 
{
    stock += qty;
}