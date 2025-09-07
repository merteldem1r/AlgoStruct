#include <iostream>

// OOP C++ (Runtime Polymorphism, Inheritance, Operator Overloading etc.)
// Author: Mert Eldemir

class BankAccount
{
protected:
    int accountNumber = 0;
    std::string accountHolder;
    double balance = 0;

public:
    BankAccount(const int accNum, std::string accHolder, const double balance) : accountNumber(accNum),
                                                                                 accountHolder(std::move(accHolder)), balance(balance)
    {
        std::cout << "BankAccount: Account created" << std::endl;
    };

    bool operator==(const BankAccount &acc) const
    {
        return accountNumber == acc.accountNumber;
    }

    double operator+(const BankAccount &other) const
    {
        return balance + other.balance;
    }

    [[nodiscard]] double getBalance() const
    {
        return balance;
    }

    void deposit(const double amount)
    {
        if (amount <= 0)
        {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        balance += amount;
    }

    virtual void withdraw(const double &amount)
    {
        if (amount <= 0)
        {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        if (amount <= balance)
        {
            balance -= amount;
            std::cout << "BankAccount: Withdraw success." << std::endl;
        }
        else
        {
            std::cout << "BankAccount: Balance is less than withdraw amount." << std::endl;
        }
    }

    virtual void display() const
    {
        std::cout << "Bank Account Number: " << accountNumber << "\nBank Account Holder: " << accountHolder
                  << "\nBalance: " << balance << std::endl;
    }

    virtual ~BankAccount() { std::cout << "Bank Account destructed" << std::endl; };
};

class SavingAccount final : public BankAccount
{
private:
    float interestRate = 0; // percent
    double minimumBalance = 0;

public:
    SavingAccount(const int accNum, const std::string &accHolder, const double balance, const float intRate,
                  const double minBalance) : BankAccount(accNum, accHolder, balance), interestRate(intRate),
                                             minimumBalance(minBalance)
    {
        std::cout << "SavingAccount: Account created" << std::endl;
    };

    void applyInterest()
    {
        balance += (balance * (interestRate / 100.0));
        std::cout << "SavingAccount: Interest applied" << std::endl;
    }

    void withdraw(const double &amount) override
    {
        if (amount <= 0)
        {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        if (balance - amount >= minimumBalance)
        {
            balance -= amount;
            std::cout << "SavingAccount: Withdraw success." << std::endl;
        }
        else
        {
            std::cout << "SavingAccount: Balance on minimum limit, can not withdraw." << std::endl;
        }
    }

    void display() const override
    {
        std::cout << "Saving Account Number: " << accountNumber << "\nSaving Account Holder: " << accountHolder << "\nBalance: " << balance << "\nInterest Rate: " << interestRate << "\nMinimum Allowable Balance: " << minimumBalance << std::endl;
    }

    ~SavingAccount() override { std::cout << "Saving account destructed" << std::endl; }
};

class CheckingAccount final : public BankAccount
{
private:
    double overdraftLimit = 0;

public:
    CheckingAccount(const int accNum, const std::string &accHolder, const double balance,
                    const double overdraftLimit) : BankAccount(accNum, accHolder, balance),
                                                   overdraftLimit(overdraftLimit)
    {
        std::cout << "CheckingAccount: Account created" << std::endl;
    };

    void withdraw(const double &amount) override
    {
        if (amount <= 0)
        {
            std::cout << "Invalid amount" << std::endl;
            return;
        }

        if (balance - amount >= -overdraftLimit)
        {
            balance -= amount;
            std::cout << "CheckingAccount: Withdraw success." << std::endl;
        }
        else
        {
            std::cout << "CheckingAccount: Withdraw denied, balance can not be less than overdraftLimit" << std::endl;
        }
    }

    void display() const override
    {
        std::cout << "Checking Account Number: " << accountNumber << "\nChecking Account Holder: " << accountHolder << "\nBalance: " << balance << "\nOverdraft Limit: " << overdraftLimit << std::endl;
    }

    ~CheckingAccount() override
    {
        std::cout << "Checking account destructed" << std::endl;
    }
};

int main()
{
    BankAccount *accounts[3];

    // To show Runtime Polymorphism
    accounts[0] = new BankAccount(2334, "Mert Eldemir", 200.0);
    accounts[1] = new SavingAccount(4432, "Emre Bilir", 1000.0, 2.5, 400.0);
    accounts[2] = new CheckingAccount(5872, "Batuhan Buyuknacar", 700.0, 550);
    std::cout << std::endl;

    for (auto &account : accounts)
    {
        account->display();
        account->withdraw(500);
        std::cout << "Balance after withdrawal: " << account->getBalance() << "\n"
                  << std::endl;
    }

    for (auto &account : accounts)
    {
        delete account;
    }
    std::cout << std::endl;

    // Normal Inheritance behaviours
    BankAccount bankAcc(2334, "Mert Eldemir", 200.0);
    SavingAccount saveAcc(4432, "Emre Bilir", 0.0, 2.5, 400.0);
    CheckingAccount checkAcc(5872, "Batuhan Buyuknacar", 700.0, 550);

    std::cout << std::endl;

    bankAcc.display();
    bankAcc.deposit(500);
    bankAcc.withdraw(280);
    std::cout << "Balance: " << bankAcc.getBalance() << std::endl;
    bankAcc.withdraw(400);

    std::cout << std::boolalpha;
    std::cout << "bankAcc == saveAcc: " << (bankAcc == saveAcc) << std::endl;
    std::cout << std::noboolalpha;
    std::cout << std::endl;

    saveAcc.display();
    saveAcc.deposit(1000);
    saveAcc.applyInterest();
    std::cout << "Balance: " << saveAcc.getBalance() << std::endl;
    saveAcc.withdraw(1000);
    std::cout << std::endl;

    checkAcc.display();
    checkAcc.withdraw(750);
    checkAcc.withdraw(650);
    std::cout << std::endl;
}