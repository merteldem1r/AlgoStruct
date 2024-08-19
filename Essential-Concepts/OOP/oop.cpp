#include <iostream>
#include <string>

using namespace std;

class BankAccount
{
private:
    string accountNumber; // Encapsulation: private data member
    double balance;

protected:
    string ownerName; // Protected member accessible by derived classes

public:
    // Constructor
    BankAccount(string accNum, string owner, double initialBalance) : accountNumber(accNum), ownerName(owner), balance(initialBalance) {};

    // Public method to get account balance (encapsulation: controlled access)
    double getBalance() const
    {
        return balance;
    }

    // Public method to deposit money
    void deposit(double amount)
    {
        if (amount > 0)
        {
            balance += amount;
        }
    }

    // Virtual method to be overridden in derived classes (Polymorphism)
    virtual void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            cout << "Insufficient funds!" << endl;
    }

    // Public method to display account information
    void displayAccountInfo() const
    {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Owner Name: " << ownerName << endl;
        cout << "Balance: $" << balance << endl;
    }
};

int main()
{

    return 0;
}