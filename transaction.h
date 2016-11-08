// ------------------------------------------------ transaction.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a transaction class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef TRANSACTION_H
#define TRANSACTION_H
#include <iostream>
#include <string>
#include "bintree.h"
#include "customer.h"
#include "customerhash.h"
using namespace std;

class Transaction
{
    private:
    public:
        Transaction();
        ~Transaction();
        virtual void perform(BinTree&, BinTree&, BinTree&, int, string, char, CustomerHash&) { cout << "perform" << endl;}
};

#endif