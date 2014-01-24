#ifndef ROSSLER_H
#define ROSSLER_H 

#include "functions.h"


class RosslerFunction : public functions_capsule {
public:
  RosslerFunction();
  void set(value &t, container & variables, container & parameters);

 protected:
  value dx();
  value dy();
  value dz();
  
  value X,Y,Z;
  value a,b,c;

};

class Jacobian_RosslerFunction : public functions_capsule {
public:
  Jacobian_RosslerFunction();
  void set(value &t, container & variables, container & parameters);
protected:
  value dx();
  value dy();
  value dz();
  
  value X,Y,Z;
  value a,b,c,X_fiducial,Y_fiducial,Z_fiducial;
};
#endif /* ROSSLER_H */
