#include "Discount.h"
#include <iostream>
using namespace std;
Discount::Discount(string c, double a, bool isPercent): code(c), amount(a), isPercentage(isPercent) {}
bool Discount::validate(const string& inputCode) const 
{
    return inputCode == code;
}
double Discount::apply(double total) const 
{
    if (isPercentage) 
	{
        return total - (total * amount / 100.0);
    } 
	else 
	{
        double discountedTotal = total - amount;
        return (discountedTotal > 0) ? discountedTotal : 0;
    }
}
string Discount::getCode() const 
{
    return code;
}
void Discount::display() const 
{
    cout << "Discount Code: " << code << "\n";
    if (isPercentage) 
	{
        cout << "Discount: " << amount << "% off\n";
    } 
	else 
	{
        std::cout << "Discount: $" << amount << " off\n";
    }
}