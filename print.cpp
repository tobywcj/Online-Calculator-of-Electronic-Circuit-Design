//BY: JINGYI LIU (ELIZABETH) 201485845
#include "print.h"
#include <iostream>

#include "componentsmenu.h"
#include "NPV.h"
#include "print.h"

// Electrical components menu
void print_components_menu() {
  std::cout << "\n------------ Welcome to the Electrical Components Calculator -----------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\tThis calculator calculates the value of electrical components\t\t|\n| \t\t\t\t\(Capacitors, Inductors & Resistors)\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t What do you want to calculate?\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Total Resistance (Resistors) \t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t2. Total Capacitance (Capacitors) \t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t3. Total Inductance (Inductors) \t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t4. Total Impedance and Reactance (Resistors, Capacitors &Inductors)\t|\n";
  std::cout << "|\t5. Recommended Nearest Preferred Value (NPV) Values\t\t\t\t\t|\n";
  std::cout << "|\t6. Back to Main Menu \t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t7. Exit this calculator\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "------------------------------------------------------------------------\n";
}

// let user know that they can calculate the total imepdance and reactance
void print_message() {
 std::cout << "\n\nIf you want to know the total impedance and/or the reactance of the circuit, please go back to the 'Electrical Component Calculator' Menu and choose option '4'." << std::endl;
}

// ask if the user want to use the calculator again
void ask_user(std::string arrangement ,std::string component_string) {
  std::cout << "\n\nDo you want to use this calculator for other " << component_string << " arrangements?"<< std::endl;
}

// let user know that they can calculate the NPV
void print_NPV() {
 std::cout << "\n\nDo you want to know what NPV series is the most suitable for your resistance?\nIf your answer is a yes, do head back to the 'Electrical Component Calculator' Menu and choose option '5'. " << std::endl;
}

// Tell user they could use the calculators to calculate the components values
void note1() {
  std::cout << "\nGentle reminder: If you have not calculated your total resistance, inductance or capacitance, do use our other calculators in the 'Electrical Components Calculater' page before using this calculator!\n "<< std::endl;
}

