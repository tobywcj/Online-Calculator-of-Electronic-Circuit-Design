#include "Imperfection.h"

Imperfection::Imperfection (float amplitude, float f, float CMRR)
  : _amplitude(amplitude), _f(f), _CMRR(CMRR) {}

// mutator
void Imperfection::set_amplitude (float amplitude) { _amplitude = amplitude;}
void Imperfection::set_f (float f) { _f = f;} 
void Imperfection::set_CMRR (float CMRR) { _CMRR = CMRR;}

// accessors
float Imperfection::get_slew_rate () {
  _slew_rate = _amplitude * 2*PI * _f * 1e-6;
  return _slew_rate;
}

void Imperfection:: get_additional_CMRR_Vout (float &add_Vout, float &noninv_V, float &inv_V, float &target_Vout, float &diff_Vin, float &comm_Vin, float &A_diff, float &A_comm, float &diff_Vout, float &total_Vout) {

  diff_Vin = (noninv_V - inv_V);
  comm_Vin = (noninv_V + inv_V) / 2.0;
  A_diff = target_Vout / diff_Vin;
  A_comm = A_diff / (pow(10.0, _CMRR / 20.0));
  
  diff_Vout = diff_Vin * A_diff;
  add_Vout = comm_Vin * A_comm;
  total_Vout = diff_Vout + add_Vout;

}