#include "Payment.h"
#include <iostream>
using namespace std;
bool Payment::processPayment(double amount, const string& paymentMethod) 
{
    cout << "Processing payment of $" << amount << " via " << paymentMethod << "...\n";
    if (paymentMethod == "Credit Card" || paymentMethod == "PayPal") 
	{
        cout << "Payment successful!\n";
        return true;
    } 
	else 
	{
        cout << "Payment failed: Unsupported payment method.\n";
        return false;
    }
}