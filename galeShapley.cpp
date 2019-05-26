
#include "galeShapley.h"

GaleShapley::GaleShapley(): GaleShapley(0,0,0){}
  GaleShapley::GaleShapley(int c,int ms,int ws):
             capacity(c),msize(ms), wsize(ws),engagedCount(0){ }

  GaleShapley::GaleShapley(int c,int ms,int ws, string mf, string wf): capacity(c),msize(ms), wsize(ws), menfile(mf),womenfile(wf),engagedCount(0){

        men = new string[msize];
        women = new string[wsize];
        //cout << "Men's list: ";
        for(int i=0; i<wsize; i++){
          men[i] = 'M' + to_string(i+1);
          //cout << men[i] << " ";
        }

      //  cout << "Women's list: ";
        for(int i=0; i<msize; i++){
          women[i] = 'W' + to_string(i+1);
        }

        womenPartner = new string[msize];
        menEngaged = new bool[wsize];
        for(int i=0; i<wsize; i++){
          menEngaged[i] = false;
        }


        womenPref = new string*[wsize];
        menPref = new string*[msize];


        for(int i=0; i<wsize; i++){
          womenPref[i] = new string[msize];
        }
        for(int i=0; i<msize; i++){
          menPref[i] = new string[wsize];
        }

        ifstream womenFileIn(womenfile);
        ifstream menFileIn(menfile);

      //assign the women's preference from user
        for(int i=0; i<wsize; i++){
          for(int j=0; j<msize;j++){
            womenFileIn >> womenPref[i][j];
            //mcout << womenPref[i][j] << endl;
          }
        }

        //assign the men's preference from user
            for(int i=0; i<msize; i++){
              for(int j=0; j<wsize;j++){
                menFileIn >> menPref[i][j];
              }
            }




        }






  /*GaleShapley::GaleShapley(int c, int s, int g, string m, string w, string mp, string wp):capacity(c),size(s),engagedCount(g){
    menPref = new string*[c];
    womenPref = new string*[c];
    men = new string[c];
    women = new string[c];
    menEngaged = new bool[c];
    womenPartner = new string[c];
  }*/

    // get men's index
      int GaleShapley::menIndex(string mname) const {
        for(int i=0; i<msize; i++)
          if(men[i]==mname)
            return i;

        return -1;
      }

    // get women's index
      int GaleShapley::womenIndex(string wname) const {
        for(int i=0; i<wsize; i++)
          if(women[i]==wname)
            return i;

        return -1;
      }

    // function to calculate all matches
        void  GaleShapley::calMathess(){
            //cout << "1-Matching function called!!" << endl;
            while(engagedCount<capacity){ // Pich the first free man ( we could pick any )
            //cout << "2-Matching function called!!" << endl;  //The men hasn't engage, this men is free
                int free;
                for(free=0; free<capacity; free++)// menEngaged = false, means the men is free;
                  if(!menEngaged[free])    // menEngaged = true, means the men is engaged;
                      break;     // break means once we find a men who is free, we don't need to iterate check the rest of number
                            //using break to terminate loop execution
              // One by one go to all women according to man's preferences;
              // Here man is menEngaged[free] is the picked free man
              //cout << "3-Matching function called!!" << endl;
                  for(int i=0; i<capacity && !menEngaged[free]; i++){
                      int index = womenIndex(menPref[free][i]);
                    //if the the number with index of woman is free, the man and woman become partners
                    //cout << "4-Matching function called!!" << endl;
                      if(womenPartner[index]==""){    // women with the number of index doesn't have any partner, she is free
                        womenPartner[index]= men[free]; //assign the number of free number to the number of index womon
                        //cout << men[free] << "$$ ";//*******************
                        menEngaged[free] = true; // set menEngaged[free] true= means the free number men is engaged;
                        engagedCount++;
                      }
                  else{  // if the women is not free, find the current engagement of man
                   cout << "***5-Matching function called!!" << endl;
                      string currentPartner = womenPartner[index];
                        if(morePreference(currentPartner, men[free], index)){
                        //cout << "***6-Matching function called!!" << endl;
                          womenPartner[index]=men[free];
                          //cout << "&& " << womenPartner[index] << "&& "  << women[i];
                          menEngaged[free] = true;    //the new partner is engaged
                          menEngaged[menIndex(currentPartner)]=false; //free the old partner
                        }
                     }
                  }
                }
              printCouples();
              /*for(int i=0; i<capacity; i++){
                cout << endl;
                cout << womenPartner[i] << "    " << women[i] << endl;
              }*/
         cout << "6Matching function called!!" << endl;

        }

      // This function to check if women is prefers new partner over old assigned partner when it is true
          bool GaleShapley::morePreference(string curPartner, string newPartner, int index){
                for(int i=0; i<capacity; i++){
                  //if newPartner's index comes before of , then free her current engagement, and she engaged wiht newPartner
                    if(womenPref[index][i]==newPartner){
                      return true;
                    }
                    if(womenPref[index][i]==curPartner){
                      return false;
                    }
                }
              return true;
          }


          void GaleShapley::printCouples() const{
            cout << endl;
            cout << " The Couples are: " << endl;
              for(int i=0; i<capacity; i++){
                cout << womenPartner[i] << "    " << women[i] << endl;
              }
            cout << endl;
          }



    /*string*  GaleShapley::addMen(int s){
       for(int i=0; i<s; i++){
         men[i] = 'W' + to_string(i+1);
       }
     return men;
     }

     string* GaleShapley::addWomen(int s){
       for(int i=0; i<s; i++){
         women[i] = 'M' + to_string(i+1);
       }
     return women;
   }*/

     void GaleShapley::displayPerson() const{
       cout << "Men's List:   " ;
         for(int i=0; i<msize; i++){
           cout << men[i] <<" " ;
         }
       cout << endl;
       cout << "Women's List: ";
         for(int i=0; i<wsize; i++){
           cout << women[i] <<" ";
         }
       cout << endl;
     }

      void GaleShapley::displayPersonPreference() const{

        cout << "Men's Preference List:" << endl;
          for(int i=0; i<msize; i++){
              for(int j=0; j<wsize; j++){
                cout << menPref[i][j] << " ";
              }
            cout << endl;
          }

          cout << "Women's Preference List:" << endl;
            for(int i=0; i<wsize; i++){
                for(int j=0; j<msize; j++){
                  cout << womenPref[i][j] << " ";
                }
              cout << endl;
            }

    }


    /*  Output
    Gale Shapley Marriage Algorithm

Couples are :
M4 W1
M2 W2
M5 W3
M3 W4
M1 W5  */
