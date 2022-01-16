//BY: JINGYI LIU (ELIZABETH) 201485845
#ifndef COMPONENTSMENU_H
#define COMPONENTSMENU_H

#include "Values.h"
#include <iostream>
#include <vector>
#include <string>

bool check_if_number(std::string string);

int choose_options(int no_of_options);

///////////////////////////start of the calculator for each component//////////////////////

// get the type of arrangement of the resistors
int get_arrangement(std::string component);

// function to change the SI unit for the respective component
void symbols(std::string components);

// function to get the total number of the components and to store the value of the components into a vector  
void store_values(std::string component,std::string arrangement,std::vector<double> &vector_value);

// function to get the total parallel resistance
// Parallel resistance and series capacitance and parallel inductance uses the same formula to calculate.
double parallel_resistor(std::vector<double> v, std::string arrangement, std::string components);

// function to get the total series resistance
// Series resistance and parallel capacitance and series inductance uses the same formula to calculate.
double series_resistor(std::vector<double> v1, std::string arrangement, std::string components);
///////////////////////////end of the calculator for each component//////////////////////


/////////////////start of the calculator for reactance and impedance//////////////////////

int print_message_sub_menu4();

// calculates the capacitive or inductive or total reactance 
double reactance(std::string selection,double &Xc, double &XL);

// outputs the display for total reactance and how to calculate it
void total_X(double L, double C, double X);

// outputs the display for the total impedance
void total_Z(double real, double imag, double abs, double arg);

// Impendance 
std::complex<double> impedance(double R,double overall_reactance);

/////////////////end of the calculator for reactance and impedance//////////////////////


#endif