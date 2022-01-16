//BY: JINGYI LIU (ELIZABETH) 201485845
#include "componentsmenu.h"
#include "Values.h"

#include <iostream>
#include <regex>
#include <vector>
#include <string>

// check if the input is an integer
bool check_if_number(std::string string) {
  for (int i = 0; i < string.length(); i++ ) {
    if (isdigit(string[i]) == false ) {
      return false;
    } 
  }
  return true;
}

int choose_options(int no_of_options) {
  std::string ans;
  bool integer= false;
  int ansint;

  do {
    std::cout << "\nEnter here:";
    std::cin >> ans;
    integer = check_if_number(ans);
    // prompt user to enter an integer if they did not input an integer
    if (integer == false) {
      std::cout << "\nPlease enter an integer!\n" << std::endl;
    } else {
      // convert the string to an integer
      ansint = std::stoi(ans);
      if (ansint > 0 && ansint <= no_of_options) {
        integer = true;
      } else {
        // if the user enter a value that is out of the range, prompt the user to input again
        std::cout << "\nPlease choose the options as stated above!\n";
        integer = false;
      }
    }
  } while (integer == false );
  
  return ansint;

}

///////////////////////////start of the calculator for each component//////////////////////

// Asks user for the arrangement of the resistors
int get_arrangement(std::string component) {

  std::cout << "How are the " << component << " arranged? (Key in 1 or 2 to answer)\n 1.In Parallel\n 2.In Series\n";
  return choose_options(2);
}

// function to change the SI unit of the value entered
void symbols(std::string components) {
  if (components == "resistors") {
    std::cout << "Ω" << std::endl;
  } else if (components == "capacitors") {
    std::cout << "F" << std::endl;
  } else if (components == "inductors") {
    std::cout << "H" << std::endl;
  }
}

// function to get the total number of the components and to store the value of the components into a vector  
void store_values(std::string arrangement, std::string components, std::vector<double> &vector_value) {
  char ans1;
  std::cout << "Enter y/Y if you are calculating the total " << arrangement << ", if not, enter any key to exit: ";
  std::cin >> ans1;

  double resistor_value;
  int num_of_resistors;
  vector_value.push_back(0);

  if (ans1 == 'y' || ans1 == 'y') {

    // start the loop if the user answers 'y'/'Y'
    while (ans1 == 'y' || ans1 == 'Y') {
      //allows user to ammend the value if they key in wrongly
      vector_value.erase(vector_value.begin(),vector_value.end());
      
      std::cout << "How many " << components << " are there ?" << std::endl; 
      std::cin >> num_of_resistors;

      // error message if the value that is entered is less or equal to 0
      if (num_of_resistors <= 0) {
          std::cout << "ERROR! Values can only be positive!\nPlease restart to use the calculator again!" << std::endl;
        }
      // loop to get the values of resistors in 
      for (int i = 0; i < num_of_resistors; i++) {
        double value_of_resistors;
        std::cout << "Enter your value for" << components << i + 1 << ": " ;
        std::cin >> value_of_resistors;
        vector_value.push_back(value_of_resistors);
        // error message if the value that is entered is less or equal to 0
        if (value_of_resistors <= 0) {
          std::cout << "ERROR! Values can only be positive!\nPlease restart to use the calculator again!" << std::endl;
          }  
        }
      //shows whats stored in vector
      std::cout << "The values of the " << components << " are as follows:" << std::endl;
      for (std::vector<double>::iterator i = vector_value.begin(); i < vector_value.end(); i++){
        std::cout << *i ;
        symbols(components);
      }
      std::cout << "Do you need to ammend your values? (Enter 'y'/'n'):";
      std::cin >> ans1;
      if (ans1 == 'n' || ans1 == 'N') {
        return;
      } else if (ans1 == 'y' || ans1 == 'Y') {
        std::cout << "\nYou can change your value now!\n" << std::endl;
      } else {
          std::cout << "Error Please try again!" << std::endl;
          //if theres an error make the user key in again
        }
    }
  } else { 
    std::cout<<"\nLoading... "<< std::endl;
    return;
  }
}

// Parallel resistance and series capacitance and parallel inductance uses the same formula to calculate.
double parallel_resistor(std::vector<double> v, std::string arrangement, std::string components) {
  //loop to calculate the sum of the inverse resistances
  double inverse = 0, sum = 0, total_parallel;
  for (std::vector<double>::iterator i = v.begin(); i < v.end(); i++) {
    inverse = 1 / *i;
    sum = sum + inverse;
  } 
  //calculate total parallel resistance/inductance or series capacitance
  total_parallel = 1 / sum; 
  // prints a divider to allow the user to spot the final answer right away 
  std::cout <<"\n_______________________________________________________________\n" << std::endl;
  //print the answer in scientific format so it is easier to see
  std::cout << "The total " << arrangement << " is = " << std::scientific << total_parallel;
  symbols(components);
  std::cout <<"_______________________________________________________________\n" << std::endl;

  return total_parallel;
}

// Series resistance and parallel capacitance and series inductance uses the same formula to calculate.
double series_resistor(std::vector<double> v1, std::string arrangement, std::string components) {
  // loop to calculate the sum of the series resistance
  double sum = 0, total_series;
  for (std::vector<double>::iterator i = v1.begin(); i < v1.end(); i++) {
    sum = sum + *i;
  } 
  // calculate total series resistance/inductance or parallel capacitance
  total_series = sum; 
  // prints a divider to allow the user to spot the final answer right away 
  std::cout <<"\n_______________________________________________________________\n" << std::endl;
  // print the answer in scientific format so it is easier to see
  std::cout << "The total " << arrangement << " is = " << std::scientific << total_series;
  symbols(components);
  std::cout <<"_______________________________________________________________\n" << std::endl;

  return total_series;
}
///////////////////////////end of the calculator for each component//////////////////////

/////////////////start of the calculator for reactance and impedance//////////////////////

int print_message_sub_menu4() {
  // Asks user for the arrangement of the resistors
  std::cout << "\nWhat do you want to calculate (Key in 1, 2 or 3 to answer)\n 1.Capacitive Reactance\n 2.Inductive Reactance\n 3.Total Reactance\n 4.Total Impedance" <<std::endl;
  return choose_options(4);
}

double reactance(std::string selection, double &Xc, double &XL) {
  // set a class object values;
  Values values;
  double l,c,f; 
  std::cout << "\nPlease enter the total frequency of the circuit:"<<std::endl;
  std::cin >> f;
  values.set_frequency(f);
  if (selection == "capacitive" || selection == "total") {
    std::cout << "Please enter the total capacitance of the circuit:"<<std::endl;
    std::cin >> c;
    values.set_capacitance(c);
    Xc = values.get_capacitivereactance();
    //std::cout <<"_______________________________________________________________\n" << std::endl;
    std::cout << "\nThe capacitive reactance of the circuit is "<< Xc << "Ω\n" <<std::endl;
    //std::cout <<"_______________________________________________________________\n" << std::endl;

  } 

  if (selection == "inductive" || selection == "total") {
    std::cout << "Please enter the total inductance of the circuit:"<<std::endl;
    std::cin >> l;
    values.set_inductance(l);
    XL = values.get_inductivereactance();
    //std::cout <<"_______________________________________________________________\n" << std::endl;
    std::cout << "\nThe inductive reactance of the circuit is "<< XL << "Ω\n" <<std::endl;
    //std::cout <<"_______________________________________________________________\n" << std::endl;

  } 
  // total impedance is the sum of XL and Xc where Xc is negative in imaginary form
  return XL - Xc;
}

// outputs the display for total reactance and how to calculate it
void total_X(double L, double C, double X) {
  std::cout << "Total reactance is calculated by "<< L << "(the inductive reactance) -" << C <<"(the capacitive reactance)"<< std::endl;
    std::cout <<"_______________________________________________________________\n" << std::endl;
    std::cout << "The total reactance = " << X << std::endl;
    std::cout <<"_______________________________________________________________\n" << std::endl;
}

// outputs the display for the total impedance
void total_Z(double real, double imag, double abs, double arg) {
  std::cout <<"_______________________________________________________________\n" << std::endl;
  std::cout << "Complex impedance is : " << real << " + (" << imag << "j)Ω" << std::endl;
  std::cout << "Absolute impedance is: " << abs << "Ω"<< std::endl;
  std::cout << "Phase angle of the impedance is: " << arg << "°" << std::endl;
  std::cout <<"_______________________________________________________________\n" << std::endl;
}

// total reactance is the the sum of total inductive reactance and the total capacitive reactance
std::complex<double> impedance(double R,double overall_reactance) {
  return {R, overall_reactance};
}

/////////////////end of the calculator for reactance and impedance//////////////////////