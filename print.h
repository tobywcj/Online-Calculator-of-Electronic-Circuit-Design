//BY: JINGYI LIU (ELIZABETH) 201485845
#ifndef PRINT_H
#define PRINT_H

#include "componentsmenu.h"
#include "NPV.h"
#include "print.h"

#include <iostream>

// Electrical components menu
void print_components_menu();

// let user know that they can calculate the total imepdance and reactance
void print_message();

// ask if the user want to use the calculator again
void ask_user(std::string arrangement ,std::string component_string);

// let user know that they can calculate the NPV
void print_NPV();

// Tell user they could use the calculators to calculate the components values
void note1();

#endif