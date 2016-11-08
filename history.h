// ------------------------------------------------ history.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a history transaction class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef HISTORY_H
#define HISTORY_H
#include <iostream>
#include <string>
#include "transaction.h"
#include "customer.h"
#include "customerhash.h"
using namespace std;

class History : public Transaction
{
    private:
    public:
        History();
        ~History();
        void perform(BinTree&, BinTree&, BinTree&, int, string, char, CustomerHash&);
};

#endif