//BY: JINGYI LIU (ELIZABETH) 201485845
#include "NPV.h"
#include <math.h>
#include <iostream>
#include <string>
#include "componentsmenu.h"

void printheader() {
  std::cout << "________________________________________________________________\n|\tSeries\t|\tRecommended values\t|\tPercentage difference\t|\n________________________________________________________________" << std::endl;
}

//function to get the values and percentage difference 
double NPV_value_2(const float array[], double value_entered, int arraysize, float &min) {
  double percentage_difference;
  //set min to be 100 to represent 100% percentage difference
  float NPV;
  min = 100;
  for (int i = 0; i < arraysize; i++ ) {
    if (array[i] > value_entered ) {
      percentage_difference = (array[i] - value_entered)/value_entered * 100;
    }
      else {
        percentage_difference = (value_entered - array[i])/value_entered * 100;
      }
    // Get the NPV with the least percentage difference
    if (percentage_difference < min) {
      min = percentage_difference;
      NPV = array[i];
    }
  } return NPV;
}

// reference to set the value to 2dp and scienctific:
// http://www.cplusplus.com/reference/ios/fixed/

// print on screen (for E3 to E96) (due to the formatting)
void print(double value_recommended, float p_diff , std::string name_series, int count_1) {
  //set to 2dp
  std::cout.precision(2);
  std::cout << "|\t" << name_series << "\t\t|\t\t" << std::scientific << value_recommended*pow(10,count_1)  << " \t\t|\t\t";
  std::cout << std::fixed << p_diff  << "%\t\t\t\t|\n________________________________________________________________" << std::endl;
}

// print on screen (E192) (due to the formatting)
void print_E192(double value_192, float p_diff_192, int count_1) { 
  std::cout << "|\tE192\t|\t\t"<< std::scientific << value_192*pow(10,count_1) << "Ω\t\t|\t\t";
  //set to 2dp
  std::cout.precision(2);
  std::cout << std::fixed << p_diff_192 << "%\t\t\t\t|\n________________________________________________________________" << std::endl;

}

//////////////////////what is printed at the sub menu///////////////////
void NPV_calculator() {
  std::cout << "\n>> Recommended NPV Values\n";
  
  std::cout <<"Welcome to the NPV calculator!\n"<< std::endl;
  std::cout << "This calculator list out the Nearest Preferred Value (NPV) of your component\n" << std::endl;

  std::string ansstring;
  bool number = false;
  double value;

  // check if the input is valid. If not, the user would have to key again
  do {
    std::cout << "Please enter the value of your component: ";
    std::cin >> ansstring;
    int count = 0 ;
    // check if the input contains one or more 'e' as 'e' can refer to the scientic notation of a certain value
    for (int i = 0; i < ansstring.length();i++) {
      if (ansstring[i] == 'e') {
        count++;
      }
    }
    // if the there are one or 0 'e', the input that was entered is indeed a valid value
    if (count <= 1) {
      value = std::stod(ansstring);
      number = true;
    } else {
      // if there are more than one 'e' in the string, it is invalid
      number = check_if_number(ansstring);
    }
    
    // prompt user to enter an number if they did not input an number
    if (number == false) {
      std::cout << "\nPlease enter numbers only!\n" << std::endl;
    } else {
      // convert the string to an double
      value = std::stod(ansstring);
      number = true;
    }
  } while (number == false );
  
  //collating the NPV series
  const float E3_values[3] = {10,22,47}, E6_values[6] = {10,15,22,33,47,68}, E12_values[12] = {10,12,15,18,22,27,33,39,47,56,68,82}, E24_values[24] = {10,11,12,13,15,16,18,20,22,24,27,30,33,36,39,43,47,51,56,62,68,75,82,91},E48_values[48] = {10.0,10.5,11.0,11.5,12.1,12.7,13.3,14.0,14.7,15.4,16.2,16.9,17.8,18.7,19.6,20.5,21.5,22.6,23.7,24.9,26.1,27.4,28.7,30.1,31.6,33.2,34.8,36.5,38.3,40.2,42.2,44.2,46.4,48.7,51.1,53.6,56.2,59.0,61.9,64.9,68.1,71.5,75.0,78.7,82.5,86.6,90.9,95.3}, E96_values[96] = {10.0,10.2,10.5,10.7,11.0,11.3,11.5,11.8,12.1,12.4,12.7,13.0,13.3,13.7,14.0,14.3,14.7,15.0,15.4,15.8,16.2,16.5,16.9,17.4,17.8,18.2,18.7,19.1,19.6,20.0,20.5,21.0,21.5,22.1,22.6,23.2,23.7,24.3,24.9,25.5,26.1,26.7,27.4,28.0,28.7,29.4,30.1,30.9,31.6,32.4,33.2,34.0,34.8,35.7,36.5,37.4,38.3,39.2,40.2,41.2,42.2,43.2,44.2,45.3,46.4,47.5,48.7,49.9,51.1,52.3,53.6,54.9,56.2,57.6,59.0,60.4,61.9,63.4,64.9,66.5,68.1,69.8,71.5,73.2,75.0,76.8,78.7,80.6,82.5,84.5,86.6,88.7,90.9,93.1,95.3,97.6}, E192_values[192] = {10.0,10.1,10.2,10.4,10.5,10.6,10.7,10.9,11.0,11.1,11.3,11.4,11.5,11.7,11.8,12.0,12.1,12.3,12.4,12.6,12.7,12.9,13.0,13.2,13.3,13.5,13.7,13.8,14.0,14.2,14.3,14.5,14.7,14.9,15.0,15.2,15.4,15.6,15.8,16.0,16.2,16.4,16.5,16.7,16.9,17.2,17.4,17.6,17.8,18.0,18.2,18.4,18.7,18.9,19.1,19.3,19.6,19.8,20.0,20.3,20.5,20.8,21.0,21.3,21.5,21.8,22.1,22.3,22.6,22.9,23.2,23.4,23.7,24.0,24.3,24.6,24.9,25.2,25.5,25.8,26.1,26.4,26.7,27.1,27.4,27.7,28.0,28.4,28.7,29.1,29.4,29.8,30.1,30.5,30.9,31.2,31.6,32.0,32.4,32.8,33.2,33.6,34.0,34.4,34.8,35.2,35.7,36.1,36.5,37.0,37.4,37.9,38.3,38.8,39.2,39.7,40.2,40.7,41.2,41.7,42.2,42.7,43.2,43.7,44.2,44.8,45.3,45.9,46.4,47.0,47.5,48.1,48.7,49.3,49.9,50.5,51.1,51.7,52.3,53.0,53.6,54.2,54.9,55.6,56.2,56.9,57.6,58.3,59.0,59.7,60.4,61.2,61.9,62.6,63.4,64.2,64.9,65.7,66.5,67.3,68.1,69.0,69.8,70.6,71.5,72.3,73.2,74.1,75.0,75.9,76.8,77.7,78.7,79.6,80.6,81.6,82.5,83.5,84.5,85.6,86.6,87.6,88.7,89.8,90.9,92.0,93.1,94.2,95.3,96.5,97.6,98.8}; 

  int count = 0;
  // count the exponent value to multiply to the original values of the series to match the given value of the user's component
  // For values that are lesser than 10
  while (value < 10) {
    count = count - 1; 
    value = value * 10;
  }

  // For values that are greater than 10
  while (value > 100) {
    count = count + 1;
    value = value/10;
  }

  float percentage_difference;

  printheader();
  
  //E3 Series
  //const int E3_values = E3_series();
  double E3 = NPV_value_2(E3_values, value, 3, percentage_difference);
  float percentageE3 = percentage_difference;
  print(E3, percentage_difference, "E3", count);

  //E6 Series
  //const int E6_values = E6_series();
  double E6 = NPV_value_2(E6_values, value, 6, percentage_difference);
  float percentageE6 = percentage_difference;
  print(E6, percentage_difference, "E6", count);
  
  //E12 Series
  //const int E12_values = E12_series();
  double E12 = NPV_value_2(E12_values, value, 12, percentage_difference);
  float percentageE12 = percentage_difference;
  print(E12, percentage_difference, "E12", count);

  //E24 Series
  //const int E24_values = E24_series();
  double E24 = NPV_value_2(E24_values, value, 24, percentage_difference);
  float percentageE24 = percentage_difference;
  print(E24, percentage_difference, "E24", count);
  
  //E48 Series
  //const int E48_values = E48_series();
  double E48 = NPV_value_2(E48_values, value, 48, percentage_difference);
  float percentageE48 = percentage_difference;
  print(E48, percentage_difference, "E48", count);

  //E96 Series
  //const int E96_values = E96_series();
  double E96 = NPV_value_2(E96_values, value, 96, percentage_difference);
  float percentageE96 = percentage_difference;
  print(E96, percentage_difference, "E96", count);
  
  //E192 Series
  //const int E192_values = E192_series();
  double E192 = NPV_value_2(E192_values, value, 192, percentage_difference);
  float percentageE192 = percentage_difference;
  print_E192(E192, percentage_difference, count);
}