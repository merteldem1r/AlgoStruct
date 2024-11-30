#include <iostream>
#include <string>

class BankAccount
{
private:
    std::string accountNumber; // Encapsulation: private data member
    double balance;

protected:
    std::string ownerName; // Protected member accessible by derived classes

public:
    // Constructor
    BankAccount(std::string accNum, std::string owner, double initialBalance) : accountNumber(accNum), ownerName(owner), balance(initialBalance) {};

    // Public method to get account balance (encapsulation: controlled access)
    double getBalance() const
    {
        return balance;
    }

    // Public method to deposit money
    void deposit(double amount)
    {
        balance += amount;
    }

    // Virtual method to be overridden in derived classes (Polymorphism)
    virtual void withdraw(double amount)
    {
        if (amount <= balance)
            balance -= amount;
        else
            std::cout << "Insufficient funds!" << std::endl;
    }

    // Public method to display account information
    void displayAccountInfo() const
    {
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Owner Name: " << ownerName << std::endl;
        std::cout << "Balance: $" << balance << std::endl;
    }

    // Destructor
    ~BankAccount() {}
};

class SavingsAccount : public BankAccount
{
private:
    double interestRate;

public:
    // Constructor
    SavingsAccount(std::string accNum, std::string owner, double initialBalance, double rate) : BankAccount(accNum, owner, initialBalance), interestRate(rate) {}

    void withdraw(double amount) override
    {
        std::cout << "Withdrawals not allowed in savings accounts!" << std::endl;
    }

    // Method to calculate and add interest to the balance
    void addInterest()
    {
        deposit(getBalance() * interestRate / 100);
    }
};

// Derived class representing a checking account
class CheckingAccount : public BankAccount
{
private:
    double overdraftLimit;

public:
    // Constructor
    CheckingAccount(std::string accNum, std::string owner, double initialBalance, double overdraft) : BankAccount(accNum, owner, initialBalance), overdraftLimit(overdraft) {}

    // Overriding the withdraw method with additional functionality (polymorphism)
    void withdraw(double amount) override
    {
        if (amount <= getBalance() + overdraftLimit)
        {
            deposit(-amount);
        }
        else
        {
            std::cout << "Exceeds overdraft limit!" << std::endl;
        }
    }
};

// Abstract base class representing a bank customer (abstraction)
class BankCustomer
{
public:
    virtual void getCustomerInfo() = 0; // Pure virtual function
};

// Derived class representing a specific bank customer
class SpecificCustomer : public BankCustomer
{
private:
    std::string name;
    int age;

public:
    SpecificCustomer(std::string name, int age) : name(name), age(age) {}

    void getCustomerInfo() override
    {
        std::cout << "Customer Name: " << name << ", Age: " << age << std::endl;
    }
};

int main()
{
    // Creating objects
    SavingsAccount savings("SA12345", "John Doe", 1000.0, 3.5);
    CheckingAccount checking("CA12345", "Jane Doe", 500.0, 200.0);

    // Demonstrating encapsulation and polymorphism
    savings.displayAccountInfo();
    savings.addInterest();
    savings.displayAccountInfo();
    savings.withdraw(100); // Will show that withdrawals are not allowed

    checking.displayAccountInfo();
    checking.withdraw(600); // Will allow overdraft
    checking.displayAccountInfo();

    // Demonstrating abstraction
    SpecificCustomer customer("Alice", 30);
    customer.getCustomerInfo();

    return 0;
}

/*

-> Encapsulation:

The BankAccount class encapsulates the accountNumber, balance, and ownerName properties. The balance and account number are private, so they can only be accessed through public methods (getBalance, deposit, etc.).

-> Inheritance:

The SavingsAccount and CheckingAccount classes inherit from the BankAccount class. They reuse and extend the functionality of the BankAccount class, demonstrating inheritance.

-> Polymorphism:

The withdraw method in BankAccount is declared as virtual, allowing derived classes (SavingsAccount, CheckingAccount) to override it. This demonstrates runtime polymorphism, where the correct method is called based on the object's type.

-> Abstraction:

The BankCustomer class is an abstract base class with a pure virtual function getCustomerInfo, which must be implemented by derived classes. This allows defining a general interface for all bank customers.

*/