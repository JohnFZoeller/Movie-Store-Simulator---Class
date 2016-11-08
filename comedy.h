// ------------------------------------------------ comedy.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines a comedy movie class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef COMEDY_H
#define COMEDY_H
#include <iostream>
#include <string>
#include "movie.h"
#include "nodedata.h"
using namespace std;
 
class Comedy : public Movie
{
    public:
        Comedy();
        ~Comedy();
        NodeData* makeFromStream(istream&);          //creates a movie from the istream

        bool operator==(const Comedy&) const;
        bool operator!=(const Comedy&) const;
        bool operator>(const Comedy&) const;
        bool operator<(const Comedy&) const;
        bool operator<=(const Comedy&) const;
        bool operator>=(const Comedy&) const;
};

#endif	