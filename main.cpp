#include <iostream>
#include <regex>

//////////////////Xavier's header files///////////////////////
#include "menu.h"
#include "active.h"
#include "passive.h"
//////////////////end of Xavier's header files/////////////

//////////////////Toby's header files///////////////////////
#include "closed_loop_gain.h"
#include "Imperfection.h"
#include "essential_func.h"
#include "opamp_menu_items.h"
#include "login.h"
//////////////////end of Toby's header files///////////////////////

//////////////////Elizabeth's header files///////////////////////
#include "componentsmenu.h"
#include "NPV.h"
#include "print.h"
#include "Values.h"
//////////////////end of Elizabeth's header files//////////////

//////////////Main menu function//////////////////////
void main_menu();
int get_user_input();
void select_menu_item(int input);
void print_main_menu();
void go_back_to_main_menu();
bool is_integer(std::string num);
void menu_item_3();
/////////////////////////////////////////////////////

/////////////////Toby's function/////////////////////
void menu_item_2();
void opamp_menu();
void select_opamp_menu_item(int input); 
void go_back_to_opamp_menu();
////////////////////////////////////////////////////

/////////////////Elizabeth's function////////////////
void menu_item_1();
void components_submenu();
void go_back_to_components_sub_main();
void select_submenu_item(int input);
int get_user_input_components_calculator();
void components_menu_1();
void components_menu_2();
void components_menu_3();
void components_menu_4();
void components_menu_5();

////////////////////////////////////////////////////

int main(int argc, char const *argv[]) {
  LoginAdministrator app;
  /*the line below this comment allows the owner of the mini-encyclopedia to create users details and give them to users he would like to access the app. the details of the users en enrcrypted before saved on in files( we have 3 users at the moment 
  username : C.A.Evans@leeds.ac.uk, password : Evans) */
  //app.addUser("C.A.Evans@leeds.ac.uk", "Evans");
  
  //app.login();
  //   app.addUser("el19rb@email.com", "Regvith");
  main_menu();
  return 0;
}

void main_menu() {
  print_main_menu();
  int input = get_user_input();
  select_menu_item(input);
}

int get_user_input() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 4;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

void select_menu_item(int input) {
  switch (input) {
    case 1:
      menu_item_1();
      break;
    case 2:
      menu_item_2();
      break;
    case 3:
      menu_item_3();
      break;
    default:
      exit(1);
      break;
  }
}

void print_main_menu() {
  std::cout << "\n --------------- Main Menu--------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Electrical Components Calculator\t|\n";
  std::cout << "|\t2. Op-amp Calculator\t\t\t\t|\n";
  std::cout << "|\t3. Filter Calculator \t\t\t\t|\n";
  std::cout << "|\t4. Exit\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << " ---------------------------------------\n";
}

void go_back_to_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'b' or 'B' to go back to main menu: ";
    std::cin >> input;
  } while (input != "b" && input != "B");
  main_menu();
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool is_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}

////////////////////Elizabeth's functions////////////////////////////
void go_back_to_components_sub_main() {
  std::string input;
  do {
    std::cout << "\nEnter 'y' or 'Y' to go back to sub menu or enter 'e' or 'E' to go back to the main menu: ";
    std::cin >> input;
  } while (input != "y" && input != "Y" && input != "e" && input != "E");
  if (input == "y" || input == "Y") {
    components_submenu();
  } else {
    main_menu();
  }
}

void menu_item_1() {
  std::cout << "\n>> Electrical Component Calculator \n";
  components_submenu();
  go_back_to_main();
}

void select_submenu_item(int input) {
  switch (input) {
    case 1:
      components_menu_1();
      break;
    case 2:
      components_menu_2();
      break;
    case 3:
      components_menu_3();
      break;
    case 4:
      components_menu_4();
      break;
    case 5:
      components_menu_5();
      break;
    case 6:
      go_back_to_main();
      break;
    default:
      exit(1);
      break;
  }
}

// Print electrical components sub menu and get user's input
void components_submenu() {
  print_components_menu();
  int input_1 = get_user_input_components_calculator();
  select_submenu_item(input_1);
}

// get user input for electrical components calculator
int get_user_input_components_calculator() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 7;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = is_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      input = std::stoi(input_string);  // convert to int
      if (input >= 1 && input <= menu_items) {
        valid_input = true;
      } else {
        std::cout << "Invalid menu item!\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  return input;
}

//////////////////////////Electrical components calculator submenu (Elizabeth)////////////////////

void components_menu_1() {
  std::cout << "\n>> Total Resistance\n";
  std::cout << "\nWelcome to the total resistance calculator!\n" << std::endl;
  std::string components1 = "resistors";
  std::vector<double> v_resistor;
  std::string arrangement_resistor,ans1;
  double total_parallel = 0 , total_series = 0;
  
  int ans;
  //  Ask user for the arrangement of the resistors
  ans = get_arrangement(components1);

  // Parallel arrangement of resistors
  if (ans == 1) {
    arrangement_resistor = "parallel resistance";
    store_values(arrangement_resistor, components1, v_resistor);
    // If the vector is empty, the user wants to exit from the calculator 
    if (v_resistor[0] > 0 ) {
      // display the total parallel resistance
      total_parallel =  parallel_resistor(v_resistor, arrangement_resistor, components1);
      // ask user if they want to use the resistance calculator again
      ask_user("resistance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_1();
      } else {
        // Let user know that he/she can find out the NPV for their resistors 
        print_NPV();
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    }
  // Series arrangement of resistors
  } else {
    arrangement_resistor = "series resistance";
    store_values(arrangement_resistor, components1, v_resistor);
    // If the vector is empty, the user wants to exit from the calculator 
    if (v_resistor[0] > 0 ) {
      // display the total series resistance
      total_series = series_resistor(v_resistor, arrangement_resistor, components1);
      // ask user if they want to use the resistance calculator again
      ask_user("resistance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_1();
      } else {
        // Let user know that he/she can find out the NPV for their resistors 
        print_NPV();
        //return to sub menu
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    }
  }
}

// Total Capacitance calculator
void components_menu_2() {
  std::cout << "\n>> Total Capacitance\n";
  std::cout << "\nWelcome to the Total Capacitance calculator!\n" << std::endl;
  std::string components1 = "capacitors";
  std::vector<double> v_capacitors;
  std::string arrangement_capacitors;
  double total_parallel = 0 , total_series = 0;

  int ans;
  //  Ask user for the arrangement of the resistors
  ans = get_arrangement(components1);
  
  // parallel arrangement of capacitors 
  if (ans == 1) {
    arrangement_capacitors = "parallel capacitance";
    store_values( arrangement_capacitors, components1, v_capacitors);
    // If the vector is empty, the user wants to exit from the calculator 
    if (v_capacitors[0] > 0 ) {
      // display the total parallel capacitance
      total_series = series_resistor(v_capacitors, arrangement_capacitors, components1);
      // ask user if they want to use the capacitor calculator again
      ask_user("capacitance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_2();
      } else {
        // Let user know that he/she can find out the reactance and impedance 
        print_message();
        //return to sub menu
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    }
  // series arrangement of capacitors
  } else {
    arrangement_capacitors = "series capacitance";
    store_values( arrangement_capacitors, components1, v_capacitors);
    // If the vector is empty, the user wants to exit from the calculator 
    if (v_capacitors[0] > 0 ) {
      // display the total series capacitance
      total_parallel =  parallel_resistor(v_capacitors, arrangement_capacitors, components1);
      // ask user if they want to use the capacitor calculator again
      ask_user("capacitance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_2();
      } else {
        // Let user know that he/she can find out the reactance and impedance 
        print_message();
        //return to sub menu
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    } 
  } 
}

// Total Inductance calculator
void components_menu_3() {
  std::cout << "\n>> Total Inductance\n";

  std::cout << "\nWelcome to the Total Inductance calculator!\n" << std::endl;

  std::string components1 = "inductors";
  std::vector<double> v_inductors;
  std::string arrangement_inductors;
  double total_parallel = 0 , total_series = 0;

  int ans;
  //  Ask user for the arrangement of the resistors
  ans = get_arrangement(components1);

  // parallel arrangement of inductors
  if (ans == 1) {
    arrangement_inductors = "parallel inductance";
    store_values( arrangement_inductors, components1, v_inductors);
    if (v_inductors[0] > 0 ) {
      // display the total parallel inductance
      total_parallel =  parallel_resistor(v_inductors, arrangement_inductors, components1);
      // ask user if they want to use the inductance calculator again
      ask_user("inductance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_3();
      } else {
        // Let user know that he/she can find out the reactance and impedance 
        print_message();
        //return to sub menu
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    }

  // series arrangement of inductors
  } else {
    arrangement_inductors = "series inductance";
    store_values( arrangement_inductors, components1, v_inductors);
    if (v_inductors[0] > 0 ) {
      // display the total series inductance
      total_series = series_resistor(v_inductors, arrangement_inductors, components1);
      // ask user if they want to use the inductance calculator again
      ask_user("inductance" ,components1);
      char ans1;
      std::cin >> ans1;
      if (ans1 == 'y'|| ans1 == 'Y') {
        components_menu_3();
      } else {
        // Let user know that he/she can find out the reactance and impedance 
        print_message();
        //return to sub menu
        go_back_to_components_sub_main();
      }
    } else { 
      // The user wants to exit this calculator
      go_back_to_components_sub_main();
    }
  }
}

// Total Impedance and Reactance calculator
void components_menu_4() {
  std::cout << "\n>> Total Impedance and Reactance\n";
  std::cout << "\nWelcome to the Total Impedance and Reactance calculator!\n" << std::endl;
  
  Values values;
  void note1();
  int choice;
  std::string selection;
  double total_reactance,r,Xc,XL;
  std::complex<double> total_impedance;

  choice = print_message_sub_menu4();
  
  if (choice == 1) {
    selection = "capacitive";
  } else if (choice == 2) {
    selection = "inductive";
  } else {
    selection = "total";
  }
    
  total_reactance = reactance(selection,Xc,XL);

  // User want to calculate total reactance
  if(choice >= 3) {
    // prints the total reactance on the screen
    total_X(XL, Xc, total_reactance);
    // User want to calculate total impedance
    if (choice == 4) {
      std::cout << "Please enter the total resistance of the circuit:"<<std::endl;
      std::cin >> r;
      // store the resistance value into values
      values.set_resistance(r);
      // resistance value is the real part and the total reactance is the imaginary part 
      total_impedance = impedance(values.get_resistance(), total_reactance);
      // print the value of impedance on the screen
      total_Z(total_impedance.real(), total_impedance.imag(), std::abs(total_impedance), std::arg(total_impedance));
    
      go_back_to_components_sub_main();
    }
  }
  go_back_to_components_sub_main();
}

// NPV calculator
void components_menu_5() {
  // All the function for the NPV Calculator is stored in NPV.cpp
  NPV_calculator();

  // Ask user if they want to use the NPV calculator again
  char ans;
  std::cout << "Do you want to find the NPV value for another value/component?" << std::endl;
  std::cin >> ans;
  
  if (ans == 'y' || ans == 'Y') {
    components_menu_5();
  } else {
    go_back_to_components_sub_main();
  }
}

//////////////////End of Elizabeth's functions/////////////////////

//////////////////////////////Toby's Functions///////////////////////////////////////

void menu_item_2() {

  std::cout << "\n>> Menu 2\n";
  opamp_menu();
  go_back_to_main();

}

void opamp_menu() { 
  print_opamp_menu();
  int input = get_user_input_opamp_menu();
  select_opamp_menu_item(input);
}

void select_opamp_menu_item(int input) { 
    switch (input) {
    case 1:
      opamp_menu_item_1();
      go_back_to_opamp_menu();
      break;
    case 2:
      opamp_menu_item_2();
      go_back_to_opamp_menu();
      break;
    case 3:
      opamp_menu_item_3();
      go_back_to_opamp_menu();
      break;
    case 4:
      opamp_menu_item_4();
      go_back_to_opamp_menu();
    case 5:
      main_menu();
      break;
  }
}

void go_back_to_opamp_menu() {
  std::string input;
  do {
    std::cout << "\nEnter 'o' or 'O' to go back to Op-Amp Calculator menu: ";
    std::cin >> input;
  } while (input != "o" && input != "O");
  opamp_menu();
}

////////////////////////////////////////////////////////////////////////////////////////////////

//////////////////////////////////////////Xavier's Functions/////////////////////////////////////
void menu_item_3() {
  
  int code;
  menu();
  get_code( );
  
  go_back_to_main();
}

//////////////////////////////////////////////////////////////////////////////////////////////////

