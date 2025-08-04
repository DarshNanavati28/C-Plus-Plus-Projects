#include "Physical_Product.h"
#include <iostream>
using namespace std;
PhysicalProduct::PhysicalProduct(string n, double p, int id, int s, double w, string dim): Product(n, p, id, s), weight(w), dimensions(dim) {}
void PhysicalProduct::display() const 
{
    cout << "Product: " << name << "\n"
	          << "ID: " << productID << "\n"
              << "Price: $" << price << "\n"
              << "Stock: " << stock << "\n"
              << "Weight: " << weight << " kg\n"
              << "Dimensions: " << dimensions << "\n"
              << "Shipping: $" << calculateShippingCost() << "\n";
}
double PhysicalProduct::calculateShippingCost() const 
{
    return weight * 5.0;
}