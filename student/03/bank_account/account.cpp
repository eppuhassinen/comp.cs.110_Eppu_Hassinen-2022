#include "account.hh"
#include <iostream>
#include <string>

Account::Account(const std::string& owner, bool has_credit)
{
    generate_iban();
    owner_ = owner;
    has_credit_ = has_credit;
}

// Setting initial value for the static attribute running_number_
int Account::running_number_ = 0;

void Account::generate_iban()
{
    ++running_number_;
    std::string suffix = "";
    if(running_number_ < 10)
    {
        suffix.append("0");
    }
    else if(running_number_ > 99)
    {
        std::cout << "Too many accounts" << std::endl;
    }
    suffix.append(std::to_string(running_number_));

    iban_ = "FI00 1234 ";
    iban_.append(suffix);
}

void Account::print() const
{
    cout << owner_ << " : " << iban_ << " : " << balance_ << " euros" << endl;
}

void Account::save_money(int money)
{
    if (money > 0)
        balance_ += money;
}

bool Account::take_money(int money)
{
    if (balance_ + credit_limit_ >= money && money >= 0)
    {
        balance_ += -money;
        cout << money << " euros taken: new balance of " << iban_ << " is " <<
                balance_ << " euros" << endl;
        return true;
    }

    // Error message
    string message;
    if (has_credit_)
    {
        message = "credit limit overflow";
    } else
    {
        message = "balance underflow";
    }

    if (money < 0)
        message = "negative money doesn't exist";

    cout << "Cannot take money: " << message << endl;
    return false;
}

void Account::set_credit_limit(int limit)
{
    if (has_credit_)
    {
        credit_limit_ = limit;
    } else
    {
        cout << "Cannot set credit limit: the account has no credit card" << endl;
    }
}

void Account::transfer_to(Account& destination, int amount)
{
    // adds money to destination only if self has enough balance
    if (take_money(amount))
    {
        destination.save_money(amount);
    } else
    {
        cout << "Transfer from " << iban_ << " failed" << endl;
    }
}
