//will optimize functions for speed later on by passing pointers to these functions.

// classes example
#include <Rcpp.h>
#include <cmath>
using namespace Rcpp;

// This is a simple example of exporting a C++ function to R. You can
// source this function into an R session using the Rcpp::sourceCpp 
// function (or via the Source button on the editor toolbar). Learn
// more about Rcpp at:
//
//   http://www.rcpp.org/
//   http://adv-r.had.co.nz/Rcpp.html
//   http://gallery.rcpp.org/
//

// [[Rcpp::export]]
NumericVector step_length(NumericVector xx, NumericVector yy){
  
  register int t;
  register int n = xx.size(); //get array dimension
  register NumericVector out(n); // vector to return to R environment
  
  for(t=0;t<n;t++){
    
    out[t] = sqrt( std::pow(xx[t],2) + std::pow(yy[t],2) );
    
  }

  return out;
  
}

// [[Rcpp::export]]
NumericVector turn_angle(NumericVector xx, NumericVector yy){

  double pi =  3.14159;
  register int n = xx.size(); //get array dimension
  register int t;
  register NumericVector turns1(n);
  register NumericVector turns2(n-1); // vector to return to R environment

  for(t=0; t<n; t++){

    turns1[t] = atan(xx[t]/yy[t]);
    
    if(yy[t]<0){
      
      if(xx[t]<0) turns1[t] -= pi;
      
        else turns1[t] += pi;
      
    }

    if(t>0){
      
      turns2[t-1] = (turns1[t] - turns1[t-1]);
      
      if(turns2[t-1] > pi){turns2[t-1] -= 2*pi;}
      
      if(turns2[t-1] < -1*pi){turns2[t-1] += 2*pi;}
           
    }
  
  }
    
  return turns2;
  
}

// You can include R code blocks in C++ files processed with sourceCpp
// (useful for testing and development). The R code will be automatically 
// run after the compilation.
//
/*** R



*/

