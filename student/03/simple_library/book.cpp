#include "book.hh"
#include <iostream>

Book::Book(string writer, string book_name)
{
    writer_ = writer;
    book_name_ = book_name;
    loaned_ = false;
}

void Book::print() const
{
    cout << writer_ << " : " << book_name_ << endl;
    if (loaned_)
    {
        cout << "- loaned: ";
        loan_date_.print();

        cout << "- to be returned: ";
        return_date_.print();
    } else
    {
        cout << "- available" << endl;
    }
}

void Book::loan(Date loan_date)
{
    if (!loaned_)
    {
        loan_date_ = loan_date;
        loaned_ = true;

        return_date_ = loan_date;
        return_date_.advance(28);

    }
}

void Book::renew()
{
    if (!loaned_)
    {
        cout << "Not loaned: cannot be renewed" << endl;
        return;
    }
    return_date_.advance(28);
}

void Book::give_back()
{
    if (loaned_)
    {
        loaned_ = false;
        return;
    } else
    {
        cout << "Not loaned: cannot be returned" << endl;
    }
}
