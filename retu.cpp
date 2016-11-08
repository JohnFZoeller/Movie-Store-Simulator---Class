// ------------------------------------------------ retu.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for retu.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "retu.h"

// ------------------------------------default constructor----------------------------------------------- 
// Description: no data members so this does next to nothing
// -------------------------------------------------------------------------------------------------------------
Retu::Retu() { }

// ------------------------------------destructor----------------------------------------------- 
// Description: destructs retu objects
// -------------------------------------------------------------------------------------------------------------
Retu::~Retu() { }

    //later on for your return function
        // handle this :  a return command when a movie was not borrowed, etc.
            // thus need to check a customers history vector every time they wanna return 

// ------------------------------------perform----------------------------------------------- 
// Description: attempts to return a movie for a customer, only executs if the customer exists, the movie exists, 
//                      and the customer has checked out the movie and it is due
//                      adds the transaction to the cutstomers transaction history vector
// -------------------------------------------------------------------------------------------------------------
void Retu::perform(BinTree& comedy, BinTree& drama, BinTree& classic, int id, string name, char tree, CustomerHash& mems)
{
    bool found = false, foundC = false, foundS = false;
    NodeData key(name);
    NodeData *ptr;
    Customer *pointer;
    int stock;

    //special case for classic
    switch(tree)
    {
        case 'F' : found = comedy.retrieve(key, ptr); break;
        case 'D' : found = drama.retrieve(key, ptr); break;
        case 'C' : found = classic.retrieve(key, ptr); break; 
        default : break;  //take care of z in main
    }

    if(found)
        stock = ptr->getStock();
    else 
        cout << "Movie does not exist" << endl; //going to cover dramas special stocking case in storage of movies 

        foundC = mems.findCustomer(id, pointer);
        if(foundC)
        {
            foundS = pointer->checkHistory(name); 
            if(foundS)  //therefore, yes, this item has been checked out and is due
            {
                pointer->addTransaction("Returned ", name);
                ptr->setStock(stock + 1); 
            }
            else cout << " never checked out" << endl;
        }
        else
            cout << "Customer does not exist" << endl;
}