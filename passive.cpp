//BY Xavier Yip SSID 201310964
#include <iostream>
#include "passive.h"
using namespace std;


float passive(float fc, float c){
  bool valid_input = false;
  cout << "\nYou have selected to build a passive filter.\n\n"; // telling the user which filter they have chosen.

  do {

  cout << "What is the wanted cut-off frequency?\n\n"; 

  cin >> fc;

  if (fc <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float RC = 1 / (2 * pi *fc );  

  cout << "\nThe calculated RC value is " << RC << endl;

  do {

  cout << "\nPlease enter the value of the capacitor that will be used. Values from 1..100 nF are recommended\n\n";
  
  cin >> c;

  if (c <= 0){
  cout << "\nPlease enter a positive non-zero value!\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float R = RC/ c;

  cout << "\nThe calculated resistor value is " << R << " Ω\n";

  return 0;
}
