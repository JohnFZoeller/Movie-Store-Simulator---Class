// ------------------------------------------------ customer.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a customer class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <string>
#include <iostream>
#include <vector>
using namespace std;

class Customer
{
    private:
        string first, last;
        int id;
        vector<string> hist;
        vector<string> due;
    public:
        Customer();
        Customer(int, string, string);
        ~Customer();
        int getId();
        string getFirst();
        string getLast();
        void addTransaction(string, string);
        void displayTransactions();
        bool checkHistory(string);

        Customer& operator=(const Customer&);
        bool operator==(const Customer&) const;
        bool operator!=(const Customer&) const;
};

#endif