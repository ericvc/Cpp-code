step_lengthR = function(xx, yy){
  
  sqrt(xx^2 + yy^2)
  
}

turn_angleR <- function(xx,yy){
  
  b <- sign(xx)
  b[b=0] <- 1
  temp = b*(yy<0)*pi+atan(xx/yy)
  ta = temp[-1]-temp[-length(b)]
  ta[ta < -pi] = ta[ta < -pi] + 2*pi
  ta[ta > pi] = ta[ta > pi] - 2*pi
    
  return(ta)
  
}