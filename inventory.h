// ------------------------------------------------ inventory.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a inventory transaction class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef INVENTORY_H
#define INVENTORY_H
#include <iostream>
#include <string>
#include "transaction.h"
#include "customerhash.h"
using namespace std;

class Inventory : public Transaction
{
    private:
    public:
        Inventory();
        ~Inventory();
        void perform(BinTree&, BinTree&, BinTree&, int, string, char, CustomerHash&);
};

#endif