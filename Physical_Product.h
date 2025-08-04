#ifndef PHYSICALPRODUCT_H
#define PHYSICALPRODUCT_H
#include "Product.h"
#include <string>
using namespace std;
class PhysicalProduct : public Product 
{
    double weight;
    string dimensions;
public:
    PhysicalProduct(string n, double p, int id, int s, double w, string dim);
    void display() const override;
    double calculateShippingCost() const;
};
#endif