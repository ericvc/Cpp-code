/*
Often times in Bayesian modelling, we would like to specify priors that are informative, based 
on some sort of prior knowledge about the data or model, or that might help issues with convergence
by changing the shape of the posterior distribution. To aid in these decisions, it is helpful to know
the mean and variance of the prior distribution we wish to specify. For distributions other than the 
Gaussian, calculating these values is simple but requires looking up the formula. This program is a 
simple calculator for the mean and variance of an assortment of probability distributions.
 */

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;

// function prototypes
void betadist();
void betabinomdist();
void dirichletdist();
void gammadist();
void negbinomdist();
void weibulldist(); 

int main()
{

    int option; // menu option
    
    cout << "\n\n"+string(80,'*')+"\n";
    cout << string(20,' ')+"He's Got Priors: a program written for C++\n";
    cout << "\n"+string(80,'*')+"\n";

    do{

        cout << "\n"+string(80,'=')+"\n\n";
        cout << "   1. Beta\n";
        cout << "   2. Beta-Binomial\n";
        cout << "   3. Dirichlet\n";
        cout << "   4. Gamma\n";
        cout << "   5. Negative Binomial\n";
        cout << "   6. Weibull\n\n";
        cout << "   7. Quit\n\n";

        do{
     
            cout << "Enter your choice: ";
            cin >> option;
            while(cin.fail()) {
                  cout << "\nError, try again: ";
                  cin.clear();
                  cin.ignore(256,'\n');
                  cin >> option;
                };
        
        } while(option<1 || option >7);
     
        switch(option){
            
            case 1:
                betadist();
                break;
             case 2:
                betabinomdist();
                break;
             case 3:
                dirichletdist();
                break;
            case 4:
                gammadist();
                break;
            case 5:
                negbinomdist();
                break;
            case 6:
                weibulldist();
                break;
            case 7:
                break;
        }
        
    } while(option!=7);
        
 return 0;
    
}

// beta distribution
void betadist(){

    double mean;
    double var;
    double a; // parameters
    double b;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(35,' ') << "Beta Distribution"<< string(35,' ') <<"\n";
    cout << "\n"+string(80,'.')+"\n\n";
        
    do{
            
        cout << "Enter value for 'alpha' parameter: ";
        cin >> a;        
        while(cin.fail() || a<=0) {
        cout << "\nError, try again: ";
            cin.clear();
           cin.ignore(256,'\n');
            cin >> a;
        };
            
    } while(!a); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'beta' parameter: ";
        cin >> b;
        while(cin.fail() || b<=0) {
        cout << "\nError, try again: ";
            cin.clear();
           cin.ignore(256,'\n');
            cin >> b;
        };
            
    } while(a && !b); // if 'option' not set, ask for user selection

    mean = a  / (a+b);
    var = (a*b)/(pow((a+b),2)*(a+b+1));
    cout << string(40,'.')+"\n";
    cout << "\n\tMean: " << mean << "\n";
    cout << "\tVariance: " << var << "\n";

}

// beta-binomial distribution
void betabinomdist(){

    double mean;
    double var;
    double a; // parameters
    double b;
    int n;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(30,' ') << "Beta-Binomial Distribution"<< string(30,' ') <<"\n";
    cout << "\n"+string(80,'.')+"\n\n";
        
    do{
            
        cout << "Enter value for 'alpha' parameter: ";
        cin >> a;        
        while(cin.fail() || a<=0) {
        cout << "\nError, try again: ";
            cin.clear();
           cin.ignore(256,'\n');
            cin >> a;
        };
            
    } while(!a); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'beta' parameter: ";
        cin >> b;
        while(cin.fail() || b<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> b;
        };
            
    } while(a && !b); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'size' parameter: ";
        cin >> n;
        while(cin.fail() || !n>0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> n;
        };
            
    } while(a && b && !n); // if 'option' not set, ask for user selection

    mean = n*a  / (a+b);
    var = ( (n*a*b)*(a+b+n) )/ (pow((a+b),2)*(a+b+1));
    cout << string(40,'.')+"\n";
    cout << "\n\tMean: " << mean << "\n";
    cout << "\tVariance: " << var << "\n";

}

// beta-binomial distribution
void dirichletdist(){

    int n = 0;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(32,' ') << "Dirichlet Distribution\n";
    cout << "\n"+string(80,'.')+"\n\n";
    
    
    while(!n || n<=0){
    cout << "How many variables?: ";
    cin >> n;
    while(cin.fail() || !n>0){
        cout << "\nError, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> n;
        }
    }

    double a[n]; // parameters
    double tot;
    int t;

    for(t=0;t<n;t++){
    cout << "Enter value for 'alpha' parameter (" << t+1 << "): ";
    cin >> a[t];
    while(cin.fail() || !a) {
        cout << "\nError, try again: ";
        cin.clear();
        cin.ignore(256,'\n');
        cin >> a[t];
        }
    }
        
    for(t=0;t<n;t++) tot = tot + a[t];
    for(t=0;t<n;t++){
        
        double mean;
        double var;
        
        mean = a[t] / tot;
        var = (a[t]*(tot-a[t])) / (pow(tot,2)*(tot+1)); 

        cout << string(40,'.')+"\n";
        cout << "\n\tMean "<< t+1 << ": " << mean << "\n";
        cout << "\n\tVariance "<< t+1 << ": " <<  var << "\n";

    }

    return;

}

// gamma distribution
void gammadist(){

    double mean;
    double var;
    double a; // parameters
    double b;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(32,' ') << "Gamma Distribution\n";
    cout << "\n"+string(80,'.')+"\n\n";
        
    do{
            
        cout << "Enter value for 'alpha' parameter: ";
        cin >> a;        
        while(cin.fail() || a<=0) {
        cout << "\nError, try again: ";
            cin.clear();
           cin.ignore(256,'\n');
            cin >> a;
        };
            
    } while(!a); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'beta' parameter: ";
        cin >> b;
        while(cin.fail() || b<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> b;
        };
            
    } while(a && !b); // if 'option' not set, ask for user selection

    mean = a*b;
    var = a*pow(b,2);
    cout << string(40,'.')+"\n";
    cout << "\n\tMean: " << mean << "\n";
    cout << "\tVariance: " << var << "\n";

}

// negative binomial distribution
void negbinomdist(){

    double mean;
    double var;
    double a; // parameters
    double b;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(25,' ') << "Negative Binomial Distribution\n";
    cout << "\n"+string(80,'.')+"\n\n";
        
    do{
            
        cout << "Enter value for 'alpha' parameter: ";
        cin >> a;        
        while(cin.fail() || a<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> a;
        };
            
    } while(!a); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'beta' parameter: ";
        cin >> b;
        while(cin.fail() || b<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> b;
        };
            
    } while(a && !b); // if 'option' not set, ask for user selection

    mean = a/b;
    var = (a/pow(b,2))*(b+1);
    cout << string(40,'.')+"\n";
    cout << "\n\tMean: " << mean << "\n";
    cout << "\tVariance: " << var << "\n";

}

// weibull distribution
void weibulldist(){

    double mean;
    double var;
    double a; // parameters
    double b;

    cout << "\n\n"+string(80,'=')+"\n\n";
    cout << string(32,' ') << "Weibull Distribution\n";
    cout << "\n"+string(80,'.')+"\n\n";
        
    do{
            
        cout << "Enter value for 'alpha' parameter: ";
        cin >> a;        
        while(cin.fail() || a<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> a;
        };
            
    } while(!a); // if 'option' not set, ask for user selection

    do{
            
        cout << "Enter value for 'beta' parameter: ";
        cin >> b;
        while(cin.fail() || b<=0) {
        cout << "\nError, try again: ";
            cin.clear();
            cin.ignore(256,'\n');
            cin >> b;
        };
            
    } while(a && !b); // if 'option' not set, ask for user selection

    mean = b*std::tgamma(1 + (1/a));
    var = pow(b,2) * ( std::tgamma(1+(2/a)) - pow(std::tgamma(1+(1/a)),2) );
    cout << string(40,'.')+"\n";
    cout << "\n\tMean: " << mean << "\n";
    cout << "\tVariance: " << var << "\n";

}