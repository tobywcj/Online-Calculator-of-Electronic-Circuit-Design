#include "essential_func.h"

void print_opamp_menu() {
  std::cout << "\n-------------- Op-amp calculator menu --------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. Closed-loop gain with ideal op-amp\t\t\t|\n";
  std::cout << "|\t2. Closed-loop gain with standard op-amp\t\t|\n";
  std::cout << "|\t3. Checking slew rate for distortion\t\t\t|\n";
  std::cout << "|\t4. Common Mode Rejection Ratio \t\t\t\t\t|\n";
  std::cout << "|\t5. Return to the main menu\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------------------\n";
}

void print_choose_opamp_menu() { 
  std::cout << "\n-------------- Choose an Op-Amp to check --------------\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t1. CA3140E Op-Amp\t\t\t|\n";
  std::cout << "|\t2. 741  Op-Amp\t\t|\n";
  std::cout << "|\t3. OP07 Op-Amp\t\t\t|\n";
  std::cout << "|\t4. OPA344 Op-Amp\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t5. OPA657 Op-Amp \t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "|\t\t\t\t\t\t\t\t\t\t\t\t\t|\n";
  std::cout << "-----------------------------------------------------\n";
}

// https://codereview.stackexchange.com/questions/162569/checking-if-each-char-in-a-string-is-a-decimal-digit
bool check_integer(std::string num) {
  return std::regex_match(num, std::regex("[+-]?[0-9]+"));
}


int get_user_input_opamp_menu() {
  int input;
  std::string input_string;
  bool valid_input = false;
  int menu_items = 5;

  do {
    std::cout << "\nSelect item: ";
    std::cin >> input_string;
    valid_input = check_integer(input_string);
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

void opamp_menu_item_1();
void opamp_menu_item_2();
void opamp_menu_item_3();
void opamp_menu_item_4();