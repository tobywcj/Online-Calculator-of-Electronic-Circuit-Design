#ifndef CLOSED_LOOP_GAIN_H
#define CLOSED_LOOP_GAIN_H

#include <cmath>

class Gain {

public:
// constructor
Gain (float R1, float R2, float fT);
// only accessors and mutators are public
// mutators
void set_R1 (float R1);
void set_R2 (float R2);
void set_fT (float fT);
// accessors
float get_ideal_noninv_G(); // ideal op-amp
float get_ideal_inv_G(); // ideal op-amp
float get_B(); // feedback ratio
float get_A(float fT, float signal_freq); // calclation of open loop gain from the value of transition freq and highest signal freq within input range
float get_standard_noninv_G(float A); // standard op-amp by inputting resistors value
float get_standard_noninv_G_targetgain(float A, float B_target_gain); // standard op-amp by inputting target gain
float get_standard_inv_G(float A); // standard op-amp
float get_B_target_gain(float target_gain); // ask user whether has any target closed-loop gain
float get_decibel(float gain);

private:
// member variables are private and set/get via accessor/mutator
float _R1;
float _R2;
float _ideal_noninv_G;
float _ideal_inv_G;
float _B;
float _A;
float _fT;
float _standard_noninv_G;
float _standard_noninv_G_targetgain;
float _standard_inv_G;
float _B_target_gain;
float _decibel;
};

#endif