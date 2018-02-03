// classes example
#include <stdio>
#include <math.h>
#include <random>

using namespace std;

class Walker{
  int energy; // energetic state
  int current_patch;
  int future_patch;
 public:
  int id;
  int alive;
  idle(); // foraging process (stay in place)
  hamburgerTime();
  move(int patch);
  cur_patch(int patch);
  fut_patch(int patch);
  position(int patch);
};

void Walker::Walker(int id_from_R){
    //assign numeric id
    int id = id_from_R;
    //assign initial energy state
    int energy = 100;
    //set as living
    int alive = 1;
}

void Walker::move(IntegerVector patches){ // pass index of class ids

  fut_patch = cur_patch;
  register int n = patches.size();
  register int t;
  //select from among possible foraging destinations
  for(t=0;t<n;t++){

      double d = sqrt(pow(Walker[t].x-Patches[t].x,2)+pow(Walker[t].y-Patches.y,2));
      if( Patches[t].check_value() / d > Patches.current_patch) fut_patch = patches[t]; // energy / distance (time)

  }

  if(fut_patch == cur_patch) Walker[t].idle();

}

void Walker::idle(){
    energy -= 2; // cost of doing business (i.e., staying alive)
    if (energy <= 0 ) hamburgerTime();
}

void Walker::position(int patch){
    
// need function to get coordinate position on grid from patch id. will depend on whether virtual environment
// is bounded or toroidal


}

void Walker::hamburgerTime(){
   alive = 0;
}