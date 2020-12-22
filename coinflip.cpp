//Program Name: Coin Flip
//If the number is even --> head; if the number is odd --> tail

#include <iostream>
#include <time.h>
//#include <random>

using std::cin;
using std::cout;
using std::endl;
//using std::srand;

int main () {
    srand (time(NULL));
    //int rand();
    //int random_number = rand();
    
    int i = 0;
    int numhead = 0;
    int numtail = 0;
    while (i < 1000000) { 
    	int rand();
    	int random_number = rand();
    	if (random_number%2 == 0) {
        	//coin flips HEAD
    		numhead = numhead + 1;
  	}
        else {
          	//coin flips TAIL
       		numtail = numtail + 1;
        }
        i++;
    }

    int numtot = numhead + numtail;
    float headpercent = numhead*100./numtot;
    float tailpercent = numtail*100./numtot;
    
    cout << "The number of HEADs flipped is " << numhead << " (" << headpercent << " %)" << endl;
    cout << "The number of TAILs flipped is " << numtail << " (" << tailpercent << " %)" << endl;
    return 0;
}
                                                  
