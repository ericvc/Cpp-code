#Pair R and C++ code. The whole purpose of this enterprise is to use C++ to improve
#data analysis in R. One area where this could be helpful are in GIS applications.
#R has poor memory management, which can cause issues with computational performance.
#GIS applications typically involve operations on large matrices of data, which tend
#to be limited by system memory.
setwd("Documents/GitHub/Cpp-code/walker/")

library(adehabitatHR)
library(Rcpp)
library(microbenchmark)

#compiles functions for R workspace
sourceCpp("walker_functions.cpp")
#reads in R analagrous R functions
source("r_functions.R")

#simlulate movement path using a correlated random walk
nlocs = 1e4
walk = simm.crw(1:nlocs, r = 0.1, h=5)
crds = walk[[1]][,c("x","y")]

#calculate displacements along each axis
dx = crds$x[-1] - crds$x[-nlocs]
dy = crds$y[-1] - crds$y[-nlocs]

#compare performance of R and C++ functions
microbenchmark(step_length(dx,dy),
               step_lengthR(dx,dy),
               turn_angle(dx,dy),
               turn_angleR(dx,dy))

# Unit: microseconds
#                 expr     min       lq      mean  median      uq      max neval
#
#  step_length(dx, dy)  26.738  27.8760  63.26713  28.445  29.015 3425.284   100
# step_lengthR(dx, dy)  71.112  72.8180 108.81811  73.388  74.526 3483.310   100
#
#   turn_angle(dx, dy) 307.770 319.7170 359.47062 321.424 329.957 3736.466   100
#  turn_angleR(dx, dy) 618.953 637.4415 822.64909 642.277 664.180 4140.947   100

#Functions written for C++ perform much faster than analagous R functions. The difference is particularly
#large for the "turn angle" function. This is to be expected because the R function uses a lot of
#indexing, which exposes some of the slowness in R. The increase in performance also scales with the
#amount of data being processed. C++ functions outperform R counterparts especially well with large amounts of data.

#---Walker virtual environment
preyDens = 100
#simulate Poisson distribution of resources
x = runif(preyDens)
y = runif(preyDens)

plot(x,y)