#include "closed_loop_gain.h"

// alternatively, initialise class members using constructor arguments
Gain::Gain (float R1, float R2, float fT)
  : _R1(R1), _R2(R2), _fT(fT) {}

// mutator
void Gain::set_R1 (float R1) {_R1 = R1;}
void Gain::set_R2 (float R2) {_R2 = R2;}
void Gain::set_fT (float fT) {_fT = fT;}

// accessor
float Gain::get_ideal_noninv_G() {
  _ideal_noninv_G = 1 + _R2/_R1;
  return _ideal_noninv_G;
}

float Gain::get_ideal_inv_G() {
  _ideal_inv_G = -_R2/_R1;
  return _ideal_inv_G;
}

float Gain::get_B() {
  _B = _R1/(_R1+_R2);
  return _B;
}

float Gain::get_A(float fT, float signal_freq) {
  _A = _fT/signal_freq;
  return _A;
}

float Gain::get_standard_noninv_G(float A) {
  _standard_noninv_G = A / (1 + A*_B);
  return _standard_noninv_G;
}

float Gain::get_standard_noninv_G_targetgain(float A, float B_target_gain) {
  _standard_noninv_G_targetgain = A / (1 + A*B_target_gain);
  return _standard_noninv_G_targetgain;
}

float Gain::get_standard_inv_G(float A) {
  _standard_inv_G = -A * (1 - _B) / (1 + A*_B);
  return _standard_inv_G;
}

float Gain::get_B_target_gain(float target_gain) {
  _B_target_gain = 1 / target_gain;
  return _B_target_gain;
}

float Gain::get_decibel(float gain) {
  _decibel = 20 * log10(fabs(gain));
  return _decibel;
}
