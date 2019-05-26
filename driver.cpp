

#include "galeShapley.h"

int main(){

  cout << " Gale Shapley Marriage Algorithm" << endl;

const string menInFile = "/Users/shuhuasong/2019-Spring/CS-203/Project/CS-203/MenPreference.txt";
const string womenInFile = "/Users/shuhuasong/2019-Spring/CS-203/Project/CS-203/WomenPreference.txt";
int capacity = 5;
int wsize = 0;
int msize = 0;

  cout << "Please enter the number of Men want to engage(reccommand 5): " << endl;
  cin >> msize;
  cout << "Please enter the number of Women want to engage(reccommand 5): " << endl;
  cin >> wsize;

//int c,int ms,int ws, int g, string m, string w, string mp, string wp, string wpartner, bool menEng
GaleShapley *gale = new GaleShapley(capacity, msize, wsize, menInFile, womenInFile);

gale->displayPerson();
gale->displayPersonPreference();
gale->calMathess();


    return 0;
  }
