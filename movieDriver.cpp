// ------------------------------------------------ movieDriver.cpp --------------------------------------------------
// John Zoeller, CSS 343 A
// Creation Date: 3/7/16
// Date of Last Modification: 3/14/16
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - runs the whole movie store
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions
// --------------------------------------------------------------------------------------------------------------------
#include <iostream>
#include "movie.h"
#include "comedy.h"
#include "drama.h"
#include "bintree.h"
#include "classic.h"
#include "customer.h"
#include "customerhash.h"
#include "transaction.h"
#include "inventory.h"
#include "borrow.h"
#include "retu.h"
#include "history.h"
#include <vector>
#include <fstream>
using namespace std;


int main()
{
    //part one 
    char type, action, mediaType;
    BinTree com, dram, classy;
    NodeData* ptr;
    bool itsIn;
    //part two
    int id;
    string first, last, title, month, year, total;
    CustomerHash members;
    vector<Customer*> list;
    //part three
    Transaction *trans;

    //////////////////////////////////////////////////////PART ONE///////////////////////////////////////////////////////////////////
    ifstream in("data4movies.txt");
    if (!in){
        cout << "File could not be opened." << endl;
        return 1;
    }
    //factory later....... for now this is fine..
    while(!in.eof()){
        type = in.get();

        if(type == 'F'){
            Comedy john;
            ptr = john.makeFromStream(in);
            itsIn = com.insert(ptr);
            if(!itsIn)
                delete ptr;
        }
        else if(type == 'D'){
            Drama john;
            ptr = john.makeFromStream(in);
            itsIn = dram.insert(ptr);
            if(!itsIn)
                delete ptr;
        }
        else if(type == 'C'){
            Classic john;
            ptr = john.makeFromStream(in);
            itsIn = classy.insert(ptr);
            if(!itsIn)
                delete ptr;
        }
        else if(type == 'Z'){
            cout << "invalid movie entry" << endl;
            in.ignore(100, '\n');
        }
    }

    cout << endl;
    in.close();
    //////////////////////////////////////////////////////PART ONE///////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////PART TWO///////////////////////////////////////////////////////////////////
    ifstream in2("data4customers.txt");
    if (!in2){
        cout << "File could not be opened." << endl;
        return 1;
    }

    while(!in2.eof()){
        in2 >> id;
        in2.get();
        getline(in2, first, ' ');
        getline(in2, last, '\n');
        list.push_back(new Customer(id, first, last));
        members.tablePlus();
        in2.peek();
    }

    members.hashAll(list);
    in2.close();
    //////////////////////////////////////////////////////PART TWO///////////////////////////////////////////////////////////////////
    //////////////////////////////////////////////////////PART THREE///////////////////////////////////////////////////////////////////
    ifstream in3("data4commands.txt");
    if(!in3){
        cout << "File could not be opened." << endl;
        return 1;
    }

    while(!in3.eof()){
        in3.get(action);

        if(action == 'X'){
            in3.ignore(10, '\n');
            continue;
        }

        if(action == 'I'){
            trans = new Inventory;
            trans->perform(com, dram, classy, 0, " ", ' ', members);
            in3.ignore(10, '\n');
            continue;
        }
        in3.get();
        in3 >> id;

        if(action == 'H'){
            trans = new History;
            trans->perform(com, dram, classy, id, " ", ' ', members);
            in3.ignore(10, '\n');
            continue;
        }
        in3.get();
        in3.get(mediaType);

        if(mediaType != 'D'){
            in3.ignore(100, '\n');
            continue;
        }

        in3.get();
        in3.get(type); //movie tree type
        in3.get();

        //movie type switch
        // at the end of each of these save something diff to a string 
            // then pass that string to the 
        switch(type){
            case 'F' : getline(in3, title, ',');
            in3.get();
            getline(in3, year, '\n');
            year.erase(4);
            total = title + " " + year;
            break;

            case 'D' : getline(in3, first, ' ');
            getline(in3, last, ',');
            in3.get();
            getline(in3, title, ',');
            in3.ignore(10, '\n');
            total = first + " " + last + " " + title;
            break;

            case 'C' : in3 >> month;
            in3.get();
            in3 >> year;
            in3.get();
            getline(in3, first, ' ');
            getline(in3, last, '\n');
            last.erase(last.size() - 1);
            total = year + " " + month + " " + first + " " + last;
            break;

            case 'Z' : in3.ignore(100, '\n');
            default : break;
        }

        //transaction type switch
        if(action == 'B'){
            trans = new Borrow;
            trans->perform(com, dram, classy, id, total, type, members); 
        }
        else if(action == 'R'){
            trans = new Retu;
            trans->perform(com, dram, classy, id, total, type, members);
        }
    }

}