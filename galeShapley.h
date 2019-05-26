
#ifndef GALESHAPLEY_H
#define GALESHAPLEY_H


#include <iostream>
using namespace std;
#include <string>
#include <string>
#include <fstream>


class GaleShapley{
  public:

    GaleShapley(); //defaul constructor
    GaleShapley(int c,int ms,int ws);// c: capacity; ms: men array size; ws: women array size
    GaleShapley(int c,int ms,int ws, string mf, string wf);// mf: men's preference txt file; wf: women's preference txt file

    int menIndex(string mname) const; // Find the men's index in men array
    int womenIndex(string wname) const; // Finde the women's index in women array
    //void addMen(int s);
    //void addWomen(int s);

    void calMathess();
    void printCouples() const;
    bool morePreference(string curPartner, string newPartner, int index);
    void displayPerson() const;
    void displayPersonPreference() const;
    //void displayCouple(char gender) const;



  private:
    string **menPref;
    string **womenPref;
    string menfile;
    string womenfile;
    string *men;
    string *women;
    string *womenPartner;//Stores partner of women. this array store pairing information.The value of womenPartner[i] indicates the partner assigned to women i.
                         // The value -1 indicates that i'th woman is free;
    bool *menEngaged; // An array to store availability of men. if menEngaged[i] is false, the man i is free; otherwise engaged;
    int capacity;  // The total number of man and woman
    int msize;
    int wsize;
    int engagedCount; //

  };


    #endif
