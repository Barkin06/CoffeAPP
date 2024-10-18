#include <string>
#include <iostream>
#include <vector>
using namespace std;

struct Customer
{
    string name;
    string surname;
    int customerID;
    string favoriteCoffee;
};

void addCustomer(vector<Customer>& customers)
{
    Customer newCustomer;
    cout << "Enter the name of the customer: ";
    cin >> newCustomer.name;
    cout << "Enter the surname of the customer: ";
    cin >> newCustomer.surname;
    cout << "Enter the customer ID: ";
    cin >> newCustomer.customerID;
    cout << "Enter the favorite coffee of the customer: ";
    cin >> newCustomer.favoriteCoffee;
    customers.push_back(newCustomer);
}

void deleteCustomer(vector<Customer>& customers) {
    bool found = false;
    int id;
    cout << "Enter the ID of the customer you want to delete: ";
    cin >> id;
    for (int i = 0; i < customers.size(); i++) {
        if (id == customers[i].customerID) {
            customers.erase(customers.begin() + i);
            found = true;
            cout << "Customer deleted successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Customer not found!" << endl;
    }
}

void updateInfo(vector<Customer>& customers) {
    int id;
    cout << "Enter the ID of the customer you want to update: ";
    cin >> id;
    bool found = false;
    for (int i = 0; i < customers.size(); i++) {
        if (customers[i].customerID == id) {
            cout << "Enter the new name, surname, ID and favorite coffee of the customer: ";
            cin >> customers[i].name >> customers[i].surname >> customers[i].customerID >> customers[i].favoriteCoffee;
            found = true;
            cout << "Customer updated successfully." << endl;
            break;
        }
    }
    if (!found) {
        cout << "Customer not found!" << endl;
    }
}

void listCustomers(const vector<Customer>& customers) {
    if (customers.empty()) {
        cout << "No customers found." << endl;
        return;
    }
    for (const auto& customer : customers) {
        cout << "Name: " << customer.name << endl;
        cout << "Surname: " << customer.surname << endl;
        cout << "ID: " << customer.customerID << endl;
        cout << "Favorite Coffee: " << customer.favoriteCoffee << endl;
        cout << "----------------------" << endl;
    }
}

void displayMenu()
{
    cout << "Welcome to the Coffee Shop!" << endl;
    cout << "---------------------------" << endl;
    cout << "1. Add a new customer" << endl;
    cout << "2. Delete a customer" << endl;
    cout << "3. Update customer info" << endl;
    cout << "4. List customers" << endl;
    cout << "5. Exit" << endl;
}

int main()
{
    vector<Customer> customers;
    int choice;

    while (true) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            addCustomer(customers);
            break;
        case 2:
            deleteCustomer(customers);
            break;
        case 3:
            updateInfo(customers);
            break;
        case 4:
            listCustomers(customers);
            break;
        case 5:
            cout << "Exiting the program." << endl;
            return 0;
        default:
            cout << "Invalid choice! Please try again." << endl;
            break;
        }
    }
}
