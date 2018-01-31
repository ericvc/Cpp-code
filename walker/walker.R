#Pair R and C++ code. The whole purpose of this enterprise is to use C++ to improve
#data analysis in R. One area where this could be helpful are in GIS applications.
#R has poor memory management, which can cause issues with computational performance.
#GIS applications typically involve operations on large matrices of data, which tend
#to be limited by system memory.
setwd("/Volumes/Data/GitHub/Cpp-code/walker/")
#compiles functions for R workspace
sourceCpp("walker_functions.cpp")

library(adehabitatHR)
library(Rcpp)
library(microbenchmark)

#simlulate movement path using a correlated random walk
nlocs = 1000
walk = simm.crw(1:nlocs, r = 0.1, h=5)
crds = walk[[1]][,c("x","y")]

#calculate displacements along each axis coordinate
dx = crds$x[-1] - crds$x[-nlocs]
dy = crds$y[-1] - crds$y[-nlocs]

#Cpp functions
s = step_length(dx, dy)
tu = turn_angle(dx, dy)

#analagous R functions
step_lengthR = function(xx, yy){
  
  sqrt(xx^2 + yy^2)
}
step_lengthR(dx,dy)

#compare performance
microbenchmark(step_length(dx,dy), 
               step_lengthR(dx,dy)
               )
# Unit: microseconds
# expr                    min      lq     mean median     uq    max neval
# step_length(dx, dy)  20.544 21.4165 23.25683 21.991 22.372 74.057 100
# step_lengthR(dx, dy) 27.118 27.8335 28.28806 28.088 28.546 39.028 100
