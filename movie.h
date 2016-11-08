// ------------------------------------------------ movie.h ------------------------------------------------------- -
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - Outlines the movie base class
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions:
//
// --------------------------------------------------------------------------------------------------------------------
#ifndef MOVIE_H
#define MOVIE_H
#include <iostream>
#include <string>
#include "nodedata.h"
using namespace std;

class Movie
{
    private:
        string director;                                           //director of Movie
        int year;                                                               //year made
        int stock;
        string title;                                                  //movie title
    public:
        Movie();
        ~Movie() {};



        //all pointless
        string getTitle() const;                                          //returns title of film
        string getDirector() const;                                   //returns director string
        bool setTitle(string);
        bool setDirector(string);                              //sets director to user string
        bool setYear(int);                                                  //sets year to user int
        int getYear() const;                                                     //returns year made
        int getStock() const;
        bool setStock(int);
};

#endif