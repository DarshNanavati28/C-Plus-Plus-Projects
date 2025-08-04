#ifndef PAYMENT_H
#define PAYMENT_H
#include <string>
class Payment {
public:
    bool processPayment(double amount, const std::string& paymentMethod);
};
#endif