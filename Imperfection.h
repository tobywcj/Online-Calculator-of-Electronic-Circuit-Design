#ifndef IMPERFECTION_H
#define IMPERFECTION_H

#include <cmath>
#include <math.h>
#define PI 3.1415926536

class Imperfection {

  public:
  // constructor
  Imperfection(float amplitude, float f, float CMRR);

  // mutator
  void set_amplitude (float amplitude); // output amplitude
  void set_f (float f); // signal frequency
  void set_CMRR (float CMRR);

  // accessors
  float get_slew_rate ();
  void get_additional_CMRR_Vout (float &add_Vout, float &noninv_V, float &inv_V, float &target_Vout, float &diff_Vin, float &comm_Vin, float &A_diff, float &A_comm, float &diff_Vout, float &total_Vout); // user's output info

  private:
  float _amplitude;
  float _f;
  float _slew_rate;
  float _CMRR;
  
};

#endif