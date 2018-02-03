// classes example
#include <stdio>
#include <math.h>
#include <random>

using namespace std;

class Prey{
  public:
    int id; // current state (position)
    int value; // prey item value
    Prey();
    check_value(); // reveal value
};

void Prey::Prey(int id_from_R){
    //assign numeric id
    int id = id_from_R;
    //randomize prey item value
    std::default_random_engine generator;
    std::poisson_distribution<double> distribution(5); //mean = 5
    int value = distribution(generator);
}

double Prey::check_value(){
    return value;
}