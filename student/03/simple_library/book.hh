#ifndef BOOK_HH
#define BOOK_HH

#include "date.hh"
#include <string>
using namespace std;

class Book
{
public:
    Book(string writer, string book_name);

    // prints the book name and status (loaned or available)
    void print() const;

    // if not loaned
    // Saves loan date and calculates return date
    void loan(Date loan_date);

    // if loaned, adds 28 days to return date
    void renew();

    // if loaned, return the book to be loaned again
    void give_back();

private:
    string writer_, book_name_;

    Date loan_date_, return_date_;
    // to check if book is loaned
    bool loaned_;
};

#endif // BOOK_HH
