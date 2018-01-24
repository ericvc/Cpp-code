//Unnecessarily complicated "guess the magic number" program written for C++. Because learning is fun.

#include <iostream>
#include <cstdlib>
#include <time.h> // 'time'

using namespace std;

void play(int m, int attempts);

int main()
{

    int option; // menu option
    int magic; // magic number
    int attempts; // default # of attempts is 10
    
    srand(time(NULL)); // seed pseudo random number generator
    magic = rand() % 100; // generate number between 0 and 100
    attempts = 10;
    
    cout << "\n\n"+string(80,'*')+"\n";
    cout << "     Needlessly complicated \"guess the magic number\" program written for C++    \n";
    cout << "\n"+string(80,'*')+"\n\n";

    do{

        cout << "1. Generate a new magic number\n";
        cout << "2. Play\n";
        cout << "3. Set number of attempts (default = 10)\n"
        cout << "4. Quit\n";

        do{
     
            cout << "Enter your choice: ";
            cin >> option;
        
        } while(option<1 || option >4); // if 'option' not set, ask for user selection
     
        switch(option){
        
            case 1:
                magic = rand() % 100; // range(0-100)
                break;
            case 2:
                play(magic, attempts);
                break;
            case 3:
                cout << "Set the number of attempts: ";
                cin >> attempts;
                break;
            case 4:
                cout << "\n"+string(10,' ')+"Take'er easy!"+string(10,' ')+"\n\n";
                break;
        
        }
        
    } while(option!=4); // if selection is '4', quit loop
        
 return 0;
    
}

// play the game
void play (int m, int attempts){
    
    int t, x;
    
    for(t=1; t<=attempts; t++){
        
        cout << "Guess the number (0-100): ";
        cin >> x;

        if(x>100 && x!=999) cout << "Try again (0-100): "; // '999' serves as hidden option to initiate 'win' (for debugging)
        
        else{
         
        if(x==m || x==999){ 
            
            cout << "\n"+string(100,'.');
            cout << "\n"+string(100,'.');
            cout << "\n"+string(42,'.')+"That is correct!"+string(42,'.');
            cout << "\n"+string(100,'.');
            cout << "\n"+string(100,'.')+"\n";

            return; // if correct, exit function
            
        }

        else{
        
            if(x<m) cout << "Your guess is too low =(.\n";
            else cout << "Your guess is too high =(.\n";
        
        }
    
        cout << "You have " << attempts-t <<" guesses remaining\n";
        
        }
   
    }

    cout << "You've used up all of your guesses.\n";
    cout << "Select a new option: \n";

}