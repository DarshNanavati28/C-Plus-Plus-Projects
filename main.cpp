#include <iostream>
#include <vector>
#include <memory>
#include <string>
#include "Physical_Product.h"
#include "Cart.h"
#include "Order.h"
#include "User.h"
#include "Customer.h"
#include "Admin.h"
#include "Payment.h"
#include "Discount.h"
using namespace std;
shared_ptr<User> loginUser(const vector<shared_ptr<User>>& users) 
{
    string username, password;
    const int maxAttempts = 3;
    int attempts = 0;
    while (attempts < maxAttempts) 
	{
        cout << "=== User Login (Attempt " << (attempts + 1) << "/" << maxAttempts << ") ===\n";
        cout << "Enter Username: ";
        cin >> username;
        cout << "Enter Password: ";
        cin >> password;
        for (const auto& user : users) 
		{
            if (user->getUsername() == username && user->authenticate(password)) 
			{
                cout << "Login successful! Welcome, " << username << "\n";
                return user;
            }
        }
        cout << "Login failed. Invalid username or password.\n\n";
        attempts++;
    }
    cout << "Maximum login attempts reached. Exiting program.\n";
    return nullptr;
}
void displayProducts(const vector<shared_ptr<Product>>& products) 
{
    cout << "\n=== Available Products ===\n";
    for (size_t i = 0; i < products.size(); ++i) 
	{
        cout << "[" << i + 1 << "] ";
        products[i]->display();
        cout << "-----------------------------\n";
    }
}
void adminMenu(vector<shared_ptr<Product>>& products) 
{
    int choice;
    do 
	{
        cout << "\n===== Admin Panel =====\n";
        cout << "1. View All Products\n";
        cout << "2. Restock a Product\n";
        cout << "3. Add New Product\n";
        cout << "4. Exit Admin Panel\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
		{
            case 1:
                displayProducts(products);
                break;
            case 2: 
			{
                int index, qty;
                cout << "Enter product number to restock: ";
                cin >> index;
                if (index < 1 || index > (int)products.size()) 
				{
                    cout << "Invalid product index!\n";
                    break;
                }
                cout << "Enter quantity to add: ";
                cin >> qty;
                products[index - 1]->increaseStock(qty);
                cout << "Stock updated!\n";
                break;
            }
            case 3: 
			{
                string name, dimensions;
                double price, weight;
                int id, stock;

                cin.ignore();
                cout << "Enter product name: ";
                getline(cin, name);
                cout << "Enter price: ";
                cin >> price;
                cout << "Enter product ID: ";
                cin >> id;
                cout << "Enter stock quantity: ";
                cin >> stock;
                cout << "Enter weight (kg): ";
                cin >> weight;
                cin.ignore();
                cout << "Enter dimensions: ";
                getline(cin, dimensions);
                products.push_back(make_shared<PhysicalProduct>(name, price, id, stock, weight, dimensions));
                cout << "Product added successfully!\n";
                break;
            }
            case 4:
                cout << "Exiting Admin Panel.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    } 
	while (choice != 4);
}
int main() 
{
    vector<shared_ptr<User>> users = 
	{
        make_shared<Customer>("User", "User@123"),
        make_shared<Admin>("Admin", "Admin@123")
    };
    vector<shared_ptr<Product>> products = 
	{
        make_shared<PhysicalProduct>("Laptop", 1200, 101, 5, 2.5, "15x10x1 in"),
        make_shared<PhysicalProduct>("Phone", 800, 102, 8, 0.5, "6x3x0.3 in"),
        make_shared<PhysicalProduct>("Tablet", 600, 103, 6, 0.8, "10x7x0.4 in"),
        make_shared<PhysicalProduct>("Smartwatch", 200, 104, 10, 0.3, "2x2x0.5 in"),
        make_shared<PhysicalProduct>("Headphones", 150, 105, 12, 0.6, "8x6x3 in"),
        make_shared<PhysicalProduct>("Keyboard", 70, 106, 7, 1.0, "18x6x1 in"),
        make_shared<PhysicalProduct>("Mouse", 40, 107, 15, 0.2, "5x3x2 in"),
        make_shared<PhysicalProduct>("Speaker", 90, 108, 10, 1.5, "10x6x5 in"),
        make_shared<PhysicalProduct>("Monitor", 300, 109, 4, 4.0, "22x14x3 in"),
        make_shared<PhysicalProduct>("Charger", 25, 110, 25, 0.3, "3x3x2 in")
    };
    shared_ptr<User> currentUser = loginUser(users);
    if (!currentUser) 
		return 0;
    currentUser->displayInfo();
    if (dynamic_pointer_cast<Admin>(currentUser))
	{
        adminMenu(products);
    }
    Cart<Product> cart;
    int choice;
    do 
	{
        cout << "\n===== DarshMart Menu =====\n";
        cout << "1. View Products\n";
        cout << "2. Add Product to Cart\n";
        cout << "3. View Cart\n";
        cout << "4. Checkout\n";
        cout << "5. View Order History\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;
        switch (choice) 
		{
            case 1:
                displayProducts(products);
                break;
            case 2: 
			{
                displayProducts(products);
                int prodChoice, quantity;
                cout << "Enter product number to add to cart: ";
                cin >> prodChoice;
                cout << "Enter quantity: ";
                cin >> quantity;
                if (prodChoice < 1 || prodChoice > (int)products.size()) 
				{
                    cout << "Invalid product choice!\n";
                } 
				else 
				{
                    auto selected = products[prodChoice - 1];
                    if (!cart.addItem(selected, quantity)) 
					{
                        cout << "Could not add product due to insufficient stock.\n";
                    } 
					else 
					{
                        cout << "Product added to cart successfully!\n";
                    }
                }
                break;
            }
            case 3:
                cout << "\n=== Your Shopping Cart ===\n";
                cart.displayCart();
                break;
            case 4: {
                if (cart.getItems().empty()) 
				{
                    cout << "Your cart is empty. Add products first.\n";
                    break;
                }
                Order order;
                for (auto& item : cart.getItems()) 
				{
                    order.addProduct(item.first, item.second);
                }
                order.calculateTotal();
                Discount discount1("SAVE10", 10, true);
                Discount discount2("FLAT50", 50, false);
                string code;
                cin.ignore();
                cout << "Enter discount code (or press Enter to skip): ";
                getline(cin, code);
                double totalAmount = cart.getTotal();
                double finalAmount = totalAmount;
                if (!code.empty()) 
				{
                    if (discount1.validate(code)) 
					{
                        cout << "Discount applied: " << discount1.getCode() << "\n";
                        finalAmount = discount1.apply(totalAmount);
                    } 
					else if (discount2.validate(code)) 
					{
                        cout << "Discount applied: " << discount2.getCode() << "\n";
                        finalAmount = discount2.apply(totalAmount);
                    } 
					else 
					{
                        cout << "Invalid discount code.\n";
                    }
                }
                cout << "Final amount after discount: $" << finalAmount << "\n";
                Payment paymentSystem;
                if (paymentSystem.processPayment(finalAmount, "Credit Card")) 
				{
                    order.markAsPaid();
                    for (auto& item : cart.getItems()) 
					{
                        item.first->reduceStock(item.second);
                    }
                    currentUser->addOrder(make_shared<Order>(order)); 
                    cout << "Order placed successfully!\n";
                    cart = Cart<Product>();
                }     
				else 
				{
                    cout << "Payment failed.\n";
                }
                break;
            }
            case 5:
                currentUser->listOrders();
                break;
            case 6:
                cout << "Thank you for shopping at DarshMart!\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";
        }
    }
	while (choice != 6);
    return 0;
}   