// ------------------------------------------------ retu.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a return transaction class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef RETU_H
#define RETU_H
#include <iostream>
#include <string>
#include "transaction.h" 
#include "customer.h"
#include "customerhash.h"
using namespace std;

class Retu : public Transaction
{
    private:
    public:
        Retu();
        ~Retu();
        void perform(BinTree&, BinTree&, BinTree&, int, string, char, CustomerHash&);
};

#endif