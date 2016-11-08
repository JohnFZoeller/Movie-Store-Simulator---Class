// ------------------------------------------------ drama.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a drama movie class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef DRAMA_H
#define DRAMA_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"
using namespace std;

class Drama : public Movie
{
    public:
        Drama();
        ~Drama();
        NodeData* makeFromStream(istream&);
};

#endif