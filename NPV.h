//BY: JINGYI LIU (ELIZABETH) 201485845
#ifndef NPV_H
#define NPV_H

#include <iostream>
#include <string>

//print header
void printheader();

//function to get the values and percentage difference 
double NPV_value_2(const float array[], double value_entered, int arraysize, float &min);

// print on screen (for E6 to E96) (due to the formatting)
void print(double value_recommended, float p_diff , std::string name_series, int count_1);

// print on screen (E192) (due to the formatting)
void print_E192(double value_192, float p_diff_192, int count_1);

// what is printed at the submenu;
void NPV_calculator();

#endif 