#include <iostream>

class Account
{
private:
    std::string name;
    int balance;

public:
    Account(std::string name, int balance) : name(name), balance(balance) {};

    void setName(std::string n)
    {
        name = n;
    }

    std::string getName() const
    {
        return name;
    }

    int getBalance() const
    {
        return balance;
    }

    friend Account operator+(const Account &a, const Account &b)
    {
        Account newAcc("", 0);
        newAcc.balance = a.balance + b.balance;
        return newAcc;
    }
};

int main()
{
    Account acc1("John", 100);
    Account acc2("Elizabeth", 50);

    Account acc3 = acc1 + acc2;
    acc3.setName("Mert");

    std::cout << "Balance sum of " << acc1.getName() << " and " << acc2.getName() << "accounts is:" << std::endl; // Balance sum of John and Elizabeth is:
    std::cout << acc3.getName() << ": " << acc3.getBalance() << std::endl;                                        // Mert: 150

    return 0;
}