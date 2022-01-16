//BY: JINGYI LIU (ELIZABETH) 201485845
#include "Values.h"
#include <complex>

void Values::set_capacitance(double capacitance ) { _capacitance = capacitance;}

void Values::set_inductance(double inductance ) { _inductance = inductance;}

void Values::set_resistance(double resistance ) { _resistance = resistance;}

void Values::set_frequency(double frequency ) { _frequency = frequency;}

double Values::get_capacitance() {return _capacitance;}

double Values::get_inductance() {return _inductance;}

double Values::get_resistance() {return _resistance;}

double Values::get_frequency() {return _frequency;}

double Values::get_capacitivereactance() {
  _capacitivereactance = 1 / (2 * PI * _frequency * _capacitance);
  return _capacitivereactance;
}

double Values::get_inductivereactance() {
  _inductivereactance = 2 * PI * _frequency * _inductance;
  return _inductivereactance;
}



