#ifndef DISCOUNT_H
#define DISCOUNT_H
#include <string>
using namespace std;
class Discount 
{
    string code;
    double amount;
    bool isPercentage;
public:
    Discount(string c, double a, bool isPercent);
    bool validate(const string& inputCode) const;
    double apply(double total) const;
    string getCode() const;
    void display() const;
};
#endif