// ------------------------------------------------ customerhash.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a customerhash table class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef CUSTOMERHASH_H
#define CUSTOMERHASH_H
#include <iostream>
#include <string>
#include "customer.h"
#include <vector>
using namespace std;
 
class CustomerHash
{
    private:
        Customer* arr;
        int tableSize;
    public:
        CustomerHash();
        ~CustomerHash();

        bool findCustomer(int, Customer* &p);
        void tablePlus();
        void hashAll(vector<Customer*>&);
        int setPrime(int);
};

#endif