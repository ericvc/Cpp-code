//Small program to make a dancing Kirby animation. Must be compiled for C++11
#include <iostream>
#include <cstdio>
#include <chrono> //time delay functions
#include <thread>

using namespace std;

int main(int argc, char **argv, int randomize)
{

if(!argc) argc = 1;

//randomize kirbies dance moves
int i;
for(i=0;i<argc;i++){
   
    char token[80]; // array for character string and tokens
    char *k, *t;

    char kirb[] = "<(**<) (>**)> <(**<) (>**)> (^**^) <(**)> (>**<) <(**)> t(**t) (w**w)";
    k = kirb;

    while(*k){

        t = token;

        while(*k!=' ' && *k){

            *t = *k;
            t++; k++;

        }
        
        if(*k) *k++;
        *t = '\0';
        cout << "\t\t" << token << "\r";
        
        using namespace std::this_thread; // sleep_for, sleep_until
        using namespace std::chrono; // nanoseconds, system_clock, seconds
        sleep_for(nanoseconds(10));
        sleep_until(system_clock::now() + seconds(1));
    
    }

  }
  
  return 0;

}
