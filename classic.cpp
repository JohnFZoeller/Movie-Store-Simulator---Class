// ------------------------------------------------ classic.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Implementation file for classic.h
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include "classic.h"

// ------------------------------------constructro---------------------------------------------- 
// -------------------------------------------------------------------------------------------------------------
Classic::Classic() { }

// ------------------------------------destructor---------------------------------------------- 

// -------------------------------------------------------------------------------------------------------------
Classic::~Classic() { }

// ------------------------------------makeFromSTream----------------------------------------------- 
//      creates a classic nodeData object from input stream
// -------------------------------------------------------------------------------------------------------------
NodeData* Classic::makeFromStream(istream& in)
{
    int stock;
    string director, title, month, year, first, last, temp;

    in.get();
    in.get();
    in >> stock;
    in.get();
    in.get();
    getline(in, director, ',');
    in.get();
    getline(in, title, ',');
    in.get();
    getline(in, first, ' ');
    getline(in, last, ' ');
    getline(in, month, ' ');
    getline(in, year, '\n');

    year.erase(4);

    NodeData* john = new NodeData(year +" " +  month + " " +  first + " " +  last, stock);

    return john;
}






