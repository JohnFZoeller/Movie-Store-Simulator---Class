// ------------------------------------------------ borrow.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for borrow.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "borrow.h"

// ------------------------------------Constructor----------------------------------------------- 
// -------------------------------------------------------------------------------------------------------------
Borrow::Borrow() { }

// ------------------------------------destructor----------------------------------------------- 
// -------------------------------------------------------------------------------------------------------------
Borrow::~Borrow() { }

// ------------------------------------perform----------------------------------------------- 
// borrows a movie for a customer as long as that movie is in stock
// -------------------------------------------------------------------------------------------------------------
//MAIN ASSUMPTION: That its ok to borrow multiple copies of the same movie
void Borrow::perform(BinTree& comedy, BinTree& drama, BinTree& classic, int id, string name, char tree, CustomerHash& mems)
{
    bool found = false, foundC = false;
    NodeData key(name);
    NodeData *ptr;
    Customer *pointer;
    int stock = 0;

    switch(tree)
    {
        case 'F' : found = comedy.retrieve(key, ptr); break;
        case 'D' : found = drama.retrieve(key, ptr); break;
        case 'C' : found = classic.retrieve(key, ptr); break;
        default : break; 
    }

    if(found)
        stock = ptr->getStock();
    else 
        cout << "Movie does not exist" << endl; 
    if(stock > 0)
    {
        ptr->setStock(stock - 1);
        foundC = mems.findCustomer(id, pointer);

        if(foundC)
            pointer->addTransaction("Borrowed ", name);
        else
            cout << "Customer does not exist" << endl;
    }
    else  
        cout << "Out of Stock" << endl;
}











