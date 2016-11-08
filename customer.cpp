// ------------------------------------------------ customer.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for customer.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "customer.h"

// ------------------------------------Customer default----------------------------------------------- 
// Description: sets first, last, and id to empty or 0
// -------------------------------------------------------------------------------------------------------------
Customer::Customer(){
    first = " ";
    last = " ";
    id = 0;
}

// ------------------------------------Customer data constructor----------------------------------------------- 
// Description: sets all customer values to user entered 
// -------------------------------------------------------------------------------------------------------------
Customer::Customer(int i, string f, string l)
{
    id = i;
    first = f;
    last = l;
}

// ------------------------------------Customer destructor----------------------------------------------- 
// Description: destructs customer objects
// -------------------------------------------------------------------------------------------------------------
Customer::~Customer() { }

// ------------------------------------Overloaded assignment----------------------------------------------- 
// Description: sets calling customer object to values of rhs
// -------------------------------------------------------------------------------------------------------------
Customer& Customer::operator=(const Customer& rhs)
{
    if(this != &rhs)
    {
        id = rhs.id;
        first = rhs.first;
        last = rhs.last;
    }
    return *this;
}

// ------------------------------------Overloaded equality----------------------------------------------- 
// Description: tests if two customers are the exact same thing
// -------------------------------------------------------------------------------------------------------------
bool Customer::operator==(const Customer& rhs) const
{
    return (first == rhs.first && last == rhs.last && id == rhs.id);
}

// ------------------------------------Overloaded inequality----------------------------------------------- 
// Description: returns true if equality operator is false
// -------------------------------------------------------------------------------------------------------------
bool Customer::operator!=(const Customer& rhs) const
{
    return !(*this == rhs);
}

// ------------------------------------addTransaction----------------------------------------------- 
// Description: if called from borrowed class, adds a movie to the due vector
//                       if called from retu class, pops the last movie off the due vector
//                       because of checkHistory() (below), the last movie in due vector 
//                       will always be the one the customer is looking to return 
//                       no matter what a transaction is added to the transaction history vector (hist)
// -------------------------------------------------------------------------------------------------------------
void Customer::addTransaction(string action, string name)   
{
    hist.push_back(action + name);
    if(action == "Borrowed ")
        due.push_back(name);
    else if(action == "Returned ")
        due.pop_back();
}

// ------------------------------------displayTransaction----------------------------------------------- 
// Description: displays all contents of customer objects hist vector
// -------------------------------------------------------------------------------------------------------------
void Customer::displayTransactions()
{
    for(int i = 0; i < hist.size(); i++)
        cout << hist[i] << endl;
}

// ------------------------------------checkHistory----------------------------------------------- 
// Description: works through the entire due vector attempting to find a movie that is due
//                       which a customer wishes to return.    If this movie is found it is moved to the 
//                      vector so that it can be popped off
// -------------------------------------------------------------------------------------------------------------
bool Customer::checkHistory(string name)
{
    for(int i = 0; i < due.size(); i++){
        if(name == due[i])  //therefore this thing has for sure been checked out
        {
            swap(due[i], due.back()); //move found movie to the back to be popped off the due vector
            return true; 
        }
    }
    return false; 
}

// ------------------------------------getId----------------------------------------------- 
// Description: returns the id of a specified customer object
// -------------------------------------------------------------------------------------------------------------
int Customer::getId()
{
    return id;
}

// ------------------------------------getFirst----------------------------------------------- 
// Description: returns the first name of a specified customer object
// -------------------------------------------------------------------------------------------------------------
string Customer::getFirst()
{
    return first;
}

// ------------------------------------getLast----------------------------------------------- 
// Description: returns the last name of a specified customer object 
// -------------------------------------------------------------------------------------------------------------
string Customer::getLast()
{
    return last;
}