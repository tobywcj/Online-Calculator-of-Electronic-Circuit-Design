//BY: JINGYI LIU (ELIZABETH) 201485845
#ifndef VALUES_H
#define VALUES_H
#include <complex>

#define PI 3.1415926536

class Values {
 public:
  void set_capacitance(double capacitance);
  void set_inductance(double inductance);
  void set_resistance(double resistance);
  void set_frequency(double frequency);
  double get_capacitance();
  double get_inductance();
  double get_resistance();
  double get_frequency();
  double get_capacitivereactance();
  double get_inductivereactance();

 private:
  double _capacitance;
  double _inductance;
  double _resistance;
  double _frequency;
  double _capacitivereactance;
  double _inductivereactance;

};

#endif