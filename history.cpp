// ------------------------------------------------ history.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for history.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "history.h"

// ------------------------------------Constructor----------------------------------------------- 
// Description: 
// -------------------------------------------------------------------------------------------------------------
History::History() { }

// -----------------------------------destructor---------------------------------------------- 
// Description:
// -------------------------------------------------------------------------------------------------------------
History::~History() { }

// ------------------------------------perform----------------------------------------------- 
// Description: uses the find customer function to obtain the customer from the hash table
//outputs every transaction that customer has made
// -------------------------------------------------------------------------------------------------------------
void History::perform(BinTree& comedy, BinTree& drama, BinTree& classic, int id, string name, char tree, CustomerHash& mems)
{
    bool exist = false;
    Customer *p;

    exist = mems.findCustomer(id, p);
    if(exist)
    {
        cout << "----------";
        cout << p->getFirst() << " " << p->getLast() << " - " <<  p->getId() << " Transaction history ";
        cout << "----------" << endl;
        p->displayTransactions();
        cout << endl;
    }
    else
        cout << "No such customer " << endl;
}
