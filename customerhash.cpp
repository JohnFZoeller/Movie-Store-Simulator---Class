// ------------------------------------------------ customerhash.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for customerHash.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "customerhash.h"

// ------------------------------------constructor----------------------------------------------- 
// Description: tableSize is set to 0
// -------------------------------------------------------------------------------------------------------------
CustomerHash::CustomerHash(){ 
    tableSize = 0;
}

// ------------------------------------destructor----------------------------------------------- 
// Description: 
// -------------------------------------------------------------------------------------------------------------
CustomerHash::~CustomerHash() { }

// ------------------------------------find customer----------------------------------------------- 
// Description: uses the id number to search the hash table, returns the customer object stored in the hash table
// -------------------------------------------------------------------------------------------------------------
bool CustomerHash::findCustomer(int idNum, Customer* &p) {
    int index = idNum % tableSize;
    int i = 0;

    if(arr[index].getId() == idNum){
        p = &arr[index];
        return true;
    }
    else if(arr[index].getId() != idNum){
        while(arr[index].getId() != idNum){            
            i++;
            if((index + 1) >= tableSize){
                index = 0;
                continue;
            }

            index++;
            if(arr[index].getId() == idNum) {
                p = &arr[index];
                return true;
            }

            if(i >= tableSize) //run through entire hash table without finding value
                return false;
        }
    }
    return true;
}

// ------------------------------------tablePlus---------------------------------------------- 
//increments tableSize
// -------------------------------------------------------------------------------------------------------------
void CustomerHash::tablePlus(){
    tableSize++;
}

// ------------------------------------hashAll---------------------------------------------- 
// Description: hashes a vector of customer objects into a hash table array 
//                      the size of the hash table is 2 times the vector size,  and then the first prime number
//                      that setPrime can find.   For instance the first prime number after 24 is 29
// -------------------------------------------------------------------------------------------------------------
void CustomerHash::hashAll(vector<Customer*>& cust){
    int index, index2;
    int size = setPrime(tableSize * 2);
    arr = new Customer[size]; 
    tableSize = size;

    for(int i = 0; i < cust.size(); i++){
        index = cust[i]->getId() % size;
        index2 = 0;

        if(arr[index].getId() == 0)  //open slot?
            arr[index] = *cust[i];     //save
        else{   
            if(index + 1 >= size)    //just so happened to be on index 28
                index = 0;                 //reset index
            while(arr[index + index2].getId() != 0)  {
                index2++;
                if(index + index2 >= size)   
                    index = 0;
            }
            arr[index + index2] = *cust[i];
        }
    }
}

// ----------------------------------setPrime--------------------------------------------- 
// Description: sets a prime number
// -------------------------------------------------------------------------------------------------------------
int CustomerHash::setPrime(int newSize)
{
    bool john = false;

    while(john == false)
    {
        if(newSize % 2 == 0 || newSize % 3 == 0 || newSize % 5 == 0 || newSize % 7 == 0)
            newSize++;
        else
            john = true;
    }   
    //the size of the hash table is set to be 2 times more than the size of the data set
    //the smallest prime number after that number is then found
    //for example, example data set size = 12 * 2 = 24.  First prime after 24 is 29
    return newSize;
}










