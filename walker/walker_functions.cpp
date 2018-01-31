//will optimize functions for speed later on by passing pointers to these functions.

// classes example
#include <Rcpp.h>
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
  
  const double pi =  3.14159;
  register int n = xx.size(); //get array dimension
  register int t;
  NumericVector out(n); // vector to return to R environment
  
  for(t=0; t<n; t++){
    
   out[t] = pow(pow(xx[t],2)+pow(yy[t],2),0.5);
      
  }
    
  return out;
  
}

// [[Rcpp::export]]
NumericVector turn_angle(NumericVector xx, NumericVector yy){

  const double pi =  3.14159;
  register int n = xx.size(); //get array dimension
  register int t;
  NumericVector turns1(n);
  NumericVector turns2(n-1); // vector to return to R environment
  
  for(t=0; t<n; t++){
    
    if(yy[t]<0){
      
      if(xx[t]<0) turns1[t] = -pi + atan(xx[t]/yy[t]);
      
      else turns1[t] = pi + atan(xx[t]/yy[t]);
      
    }
    
    else turns1[t] = atan(xx[t]/yy[t]);

    if(t>0){
      
      double eval = (turns1[t] - turns1[t-1]);
      
      if(eval < -pi){turns2[t-1] = eval + 2*pi;}
        
      if(eval > pi) {turns2[t-1] = eval - 2*pi;}
        
        else {turns2[t-1] = eval;}
        
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

