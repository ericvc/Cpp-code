//Unnecessarily complicated "guess the magic number" program written for C++. Because learning is fun.

#include <iostream>
#include <cstdlib>
#include <time.h> // 'time'

using namespace std;

// function prototypes
void play(int m, int attempts);
void autosolv(int m, int *a, int *i);
void submenu(int *a, int *i); // accepts integer pointers

int main()
{

    srand(time(NULL)); // seed pseudo random number generator

    int option; // menu option
    int attempts = 10; // default # of attempts is 10
    int magic = rand() % 100 + 1; // generate number between 1 and 100
    int init = 0;
    
    cout << "\n\n"+string(80,'*')+"\n";
    cout << "     Needlessly complicated \"guess the magic number\" program written for C++    \n";
    cout << "\n"+string(80,'*')+"\n\n";

    do{

        cout << "1. Generate a new magic number\n";
        cout << "2. Play\n";
        cout << "3. Options\n";
        cout << "4. Quit\n";
        cout << "5. Test the AutoSolv function \n\n";

        do{
     
            cout << "Enter your choice: ";
            cin >> option;
            while(cin.fail()) {
                  cout << "\nError, try again: ";
                  cin.clear();
                  cin.ignore(256,'\n');
                  cin >> option;
                };
        
        } while(option<1 || option >5); // if 'option' not set, ask for user selection
     
        switch(option){
            
            case 1:
                magic = rand() % 100 + 1; // range(1-100)
                break;
            case 2:
                play(magic, attempts);
                break;
            case 3:
                int *a; // declare pointers assign memory address
                int *b;
                a = &attempts;
                b = &init;
                submenu(a, b); // execute submenu function
                break;
            case 4:
                cout << "\n"+string(10,' ')+"Take'er easy!"+string(10,' ')+"\n\n";
                break;
            case 5:
                autosolv(magic, attempts, init);
                magic = rand() % 100 + 1; // range(1-100)
                break;
        }
        
    } while(option!=4); // if selection is '4', quit loop
        
 return 0;
    
}

// play the game
void play (int m, int attempts){
    
    int t, x;
    
    for(t=1; t<=attempts; t++){
        
        cout << "Guess the number (1-100): ";
        cin >> x;

        if(x>100 && x!=999) cout << "Try again (1-100): "; // '999' serves as hidden option to initiate 'win' (for debugging)
        
        else{
         
        if(x==m || x==999){ 
            
            cout << "\n"+string(100,'x');
            cout << "\n"+string(100,'x');
            cout << "\n"+string(41,'+')+" That is CORRECT! "+string(41,'+');
            cout << "\n"+string(100,'x');
            cout << "\n"+string(100,'x')+"\n";

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


// create simple algorithm to solve the magic number problem.
void autosolv(int m, int attempts, int init){
    
    int t;
    int glo_max  = 100;
    int glo_min = 1;
    if(init==0) init = rand() % 100 + 1;
    int x = init;

    for(t=0; t<=(attempts-1); t++){

        if(t>0) x = glo_min + (rand() % (int)(glo_max - glo_min + 1));
         
        if(x==m){ 
               
            cout << "\n\n *****AutoSolv correctly guessed " << m << " in " << t+1 << " attempts*****\n\n";

            return; // if correct, exit function
                
         }
            
            /* algorithm for iteratively searching for the magic number
            1. record attempts
            2. use information to restrict range of search in future attempts
            3. randomly sample from increasingly smaller range
            (Let's call this the "Guess Who" procedure)
            */
             
         if(x<m) glo_min = x; // update function variable
                
            else glo_max = x; // update function variable
                        
    }     

    cout << "\n\n^^^^^^AutoSolv failed to correctly guess the magic number in " << attempts << " attempts^^^^^^\n\n";
    cout << "Select a new option: \n\n";

}

// function for sub-option menu
void submenu(int *a, int *i){
    
    int sub_option; // menu suboption (local variable)
    
    cout << "\n\n"+string(80,'.')+"\n";
    cout << "              Program Settings: Make selection to change options.          ";
    cout << "\n"+string(80,'.')+"\n\n";
    
    do{
        
        cout << "1. Set number of attempts [current = " << *a << "]\n";
        cout << "2. Set initial value for AutoSolv [current = " << *i << "] (select 0  for random value)\n";
        cout << "3. Return to main menu\n\n";
        
        do{
            
            cout << "Enter your choice: ";
            cin >> sub_option;
            while(cin.fail()) {
                cout << "\nError, try again: ";
                cin.clear();
                cin.ignore(256,'\n');
                cin >> sub_option;
            };
            
        } while(sub_option<1 || sub_option >3); // if 'option' not set, ask for user selection
        
        switch(sub_option){
                
            case 1:
                cout << "\nNumber of attempts: ";
                cin >> *a;
                while(cin.fail()) {
                    cout << "\nError, try again: ";
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> *a;
                };
                break;
            case 2:
                cout << "\nStarting value: ";
                cin >> *i;
                while(cin.fail()) {
                    cout << "\nError, try again: ";
                    cin.clear();
                    cin.ignore(256,'\n');
                    cin >> *i;
                };
                break;
            case 3:
                break;
        }
        
    } while(sub_option != 3);

}

