//BY Xavier Yip SSID 201310964
#include <iostream>
#include "active.h"
using namespace std;

float CHLP052(float fc, float C, float Rb){
  float k = 1.842;
  // identifying constant
  float cn = 1.231;

  cout << "\nYou have selected to build a 2 poles Chebyshev 0.5dB ripple low pass filter.\n\n"; // telling the user which filter they have chosen.
  bool valid_input = false;

  cout << "The gain of this circuit is " << k << "\n\n";

  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ\n\n";

  cin >> Rb;

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra = (k - 1) * Rb;

  cout << "The value of RA is " << Ra << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n\n"; 

  cin >> fc;

  if (fc <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float RC = 1 / (2 * pi *fc * cn);  

  cout << "\nThe calculated RC value is " << RC << endl;

  do {

  cout << "\nPlease enter the value of the capacitor that will be used. Values from 1..100 nF are recommended\n\n";
  
  cin >> C;

  if (C <= 0){
  cout << "\nPlease enter a positive non-zero value!\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float R = RC/ C;

  cout << "\nThe calculated resistor value is " << R << " Ω\n";
  cout << "\nUsing the Equal Component approach, R1 = R2\n";

  
  return 0; 
}

float CHHP052(float fc, float C, float Rb){
  float k = 1.842;
  // identifying constant
  float cn = 0.812;

  cout << "\nYou have selected to build a 2 poles Chebyshev 0.5dB ripple high pass filter.\n\n"; // telling the user which filter they have chosen.
  bool valid_input = false;

  cout << "The gain of this circuit is " << k << "\n\n";

  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ\n\n";

  cin >> Rb;

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra = (k - 1) * Rb;

  cout << "The value of RA is " << Ra << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n\n"; 

  cin >> fc;

  if (fc <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float RC = 1 / (2 * pi *fc * cn);  

  cout << "\nThe calculated RC value is " << RC << endl;

  do {

  cout << "\nPlease enter the value of the capacitor that will be used. Values from 1..100 nF are recommended\n\n";
  
  cin >> C;

  if (C <= 0){
  cout << "\nPlease enter a positive non-zero value!\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float R = RC/ C;

  cout << "\nThe calculated resistor value is " << R << " Ω\n";
  cout << "\nUsing the Equal Component approach, R1 = R2\n";

  
  return 0; 
}

float CHLP22(float fc, float C, float Rb){
  float k = 2.114;

  float cn = 0.907;

  cout << "You have selected to build a 2 poles Chebyshev 2dB ripple low pass filter.\n\n";
  bool valid_input = false;

  cout << "The gain of this circuit is " << k << "\n\n";

  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ\n\n";

  cin >> Rb;

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra = (k - 1) * Rb;

  cout << "The value of RA is " << Ra << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n\n"; 

  cin >> fc;

  if (fc <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float RC = 1 / (2 * pi *fc * cn);  

  cout << "\nThe calculated RC value is " << RC << endl;

  do {

  cout << "\nPlease enter the value of the capacitor that will be used. Values from 1..100 nF are recommended\n\n";
  
  cin >> C;

  if (C <= 0){
  cout << "\nPlease enter a positive non-zero value!\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float R = RC/ C;

  cout << "\nThe calculated resistor value is " << R << " Ω\n";
  cout << "\nUsing the Equal Component approach, R1 = R2\n";
  return 0; 
}

float CHHP22(float fc, float C, float Rb){
  float k = 2.114;

  float cn = 1.103;

  cout << "You have selected to build a 2 poles Chebyshev 2dB ripple high pass filter.\n\n";
  bool valid_input = false;

  cout << "The gain of this circuit is " << k << "\n\n";

  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ\n\n";

  cin >> Rb;

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra = (k - 1) * Rb;

  cout << "The value of RA is " << Ra << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n\n"; 

  cin >> fc;

  if (fc <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float RC = 1 / (2 * pi *fc * cn);  

  cout << "\nThe calculated RC value is " << RC << endl;

  do {

  cout << "\nPlease enter the value of the capacitor that will be used. Values from 1..100 nF are recommended\n\n";
  
  cin >> C;

  if (C <= 0){
  cout << "\nPlease enter a positive non-zero value!\n";
  valid_input = false;}
  else {valid_input = true;}

  }
  while(valid_input == false);

  float R = RC/ C;

  cout << "\nThe calculated resistor value is " << R << " Ω\n";
  cout << "\nUsing the Equal Component approach, R1 = R2\n";
  return 0; 
}

float CHLP054(float fc, float C1, float C2, float Rb){
  bool valid_input = false;
  
  float k1 = 1.582;
  float k2 = 2.660;

  float cn1 = 0.597;
  float cn2 = 1.031;

  cout << "You have selected to build a 4 poles Chebyshev 0.5dB ripple low pass filter.\n\n";
  
  cout << "The gain of this circuit for the first stage is " << k1 << " and for the second stage is " << k2 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  cout << "\nThe calculated RC value for first stage is " << RC1 << " and for the second stage is " << RC2 << "\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "Please enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 =  RC1 / C1;

  float R2 = RC2 / C2;

  cout << "The calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω.\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4\n";

  return 0; 
}

float CHLP24(float fc, float C1, float C2, float Rb){
  bool valid_input = false;
  float k1 = 1.924;
  float k2 = 2.782;

  float cn1 = 0.471;
  float cn2 = 0.964;

  cout << "You have selected to build a 4 poles Chebyshev 2dB ripple low pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << " and for the second stage is " << k2 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  cout << "\nThe calculated RC value for first stage is " << RC1 << " and for the second stage is " << RC2 << "\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "Please enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 =  RC1 / C1;

  float R2 = RC2 / C2;

  cout << "The calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω.\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4\n";

  return 0; 
}

float CHHP054(float fc, float C1, float C2, float Rb){
  bool valid_input = false;
  float k1 = 1.582;
  float k2 = 2.660;

  float cn1 = 1.675;
  float cn2 = 0.970;

  cout << "You have selected to build a 4 poles Chebyshev 0.5dB ripple high pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << " and for the second stage is " << k2 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  cout << "\nThe calculated RC value for first stage is " << RC1 << " and for the second stage is " << RC2 << "\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "Please enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 =  RC1 / C1;

  float R2 = RC2 / C2;

  cout << "The calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω.\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4\n";

  return 0; 
}

float CHHP24(float fc, float C1, float C2, float Rb){
  bool valid_input = false;
  float k1 = 1.924;
  float k2 = 2.782;

  float cn1 = 2.123;
  float cn2 = 1.037;

  cout << "You have selected to build a 4 poles Chebyshev 2dB ripple high pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << " and for the second stage is " << k2 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  cout << "\nThe calculated RC value for first stage is " << RC1 << " and for the second stage is " << RC2 << "\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "Please enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 =  RC1 / C1;

  float R2 = RC2 / C2;

  cout << "The calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω.\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4\n";

  return 0; 
}

float CHLP056(float fc, float C1, float C2, float C3, float Rb){
  bool valid_input = false;

  float k1 = 1.537;
  float k2 = 2.448;
  float k3 = 2.846;

  float cn1 = 0.396;
  float cn2 = 0.768;
  float cn3 = 1.011;

  cout << "You have selected to build a 6 poles Chebyshev 0.5dB ripple low pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << ", for the second stage is " << k2 <<" and for the third stage is " << k3 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2 = RB3\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  float Ra3 = (k3 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n";
  cout << "The value of RA3 is " << Ra3 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  float RC3 = 1 / (2 * pi *fc * cn3);

  cout << "\nThe calculated RC value for first stage is " << RC1 << ", for the second stage is " << RC2 << " and for the third stage is " << RC3 <<"\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the third stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C3;

  if (C3 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 = RC1 / C1;

  float R2 = RC2 / C2;

  float R3 = RC3 / C3;

  cout << "\nThe calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω. The second stage resistor value is " << R3 <<"\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4, R5 = R6\n";


  return 0; 
}

float CHLP26(float fc, float C1, float C2, float C3, float Rb){
  bool valid_input = false;
  float k1 = 1.891;
  float k2 = 2.648;
  float k3 = 2.904;

  float cn1 = 0.316;
  float cn2 = 0.730;
  float cn3 = 0.983;

  cout << "You have selected to build a 6 poles Chebyshev 2dB ripple low pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << ", for the second stage is " << k2 <<" and for the third stage is " << k3 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2 = RB3\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  float Ra3 = (k3 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n";
  cout << "The value of RA3 is " << Ra3 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  float RC3 = 1 / (2 * pi *fc * cn3);

  cout << "\nThe calculated RC value for first stage is " << RC1 << ", for the second stage is " << RC2 << " and for the third stage is " << RC3 <<"\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the third stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C3;

  if (C3 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 = RC1 / C1;

  float R2 = RC2 / C2;

  float R3 = RC3 / C3;

  cout << "\nThe calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω. The second stage resistor value is " << R3 <<"\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4, R5 = R6\n";

  return 0; 
}

float CHHP056(float fc, float C1, float C2, float C3, float Rb){
  bool valid_input = false;
  float k1 = 1.537;
  float k2 = 2.448;
  float k3 = 2.846;

  float cn1 = 2.525;
  float cn2 = 1.302;
  float cn3 = 0.989;

  cout << "You have selected to build a 6 poles Chebyshev 0.5dB ripple high pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << ", for the second stage is " << k2 <<" and for the third stage is " << k3 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2 = RB3\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  float Ra3 = (k3 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n";
  cout << "The value of RA3 is " << Ra3 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  float RC3 = 1 / (2 * pi *fc * cn3);

  cout << "\nThe calculated RC value for first stage is " << RC1 << ", for the second stage is " << RC2 << " and for the third stage is " << RC3 <<"\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the third stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C3;

  if (C3 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 = RC1 / C1;

  float R2 = RC2 / C2;

  float R3 = RC3 / C3;

  cout << "\nThe calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω. The second stage resistor value is " << R3 <<"\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4, R5 = R6\n";

  return 0; 
}

float CHHP26(float fc, float C1, float C2, float C3, float Rb){
  bool valid_input = false;
  float k1 = 1.891;
  float k2 = 2.648;
  float k3 = 2.904;

  float cn1 = 3.165;
  float cn2 = 1.370;
  float cn3 = 1.017;

  cout << "You have selected to build a 6 poles Chebyshev 2dB ripple high pass filter.\n\n";
  cout << "The gain of this circuit for the first stage is " << k1 << ", for the second stage is " << k2 <<" and for the third stage is " << k3 <<"\n\n";
  
  do{
  
  cout << "Please enter the value for Rb. Choose RB to be at least 10 kΩ. RB1 = RB2 = RB3\n\n";

  cin >> Rb; // only one RB will be needed, as the the value for all RB will be the same 

  if (Rb <= 0){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float Ra1 = (k1 -1) * Rb;

  float Ra2 = (k2 -1) * Rb;

  float Ra3 = (k3 -1) * Rb;

  cout << "\nThe value of RA1 is " << Ra1 << " Ω\n";
  cout << "The value of RA2 is " << Ra2 << " Ω\n";
  cout << "The value of RA3 is " << Ra3 << " Ω\n\n";

  do {

  cout << "What is the wanted cut-off frequency?\n";

  cin >> fc;

  if (fc <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float RC1 = 1 / (2 * pi *fc * cn1);

  float RC2 = 1 / (2 * pi *fc * cn2);

  float RC3 = 1 / (2 * pi *fc * cn3);

  cout << "\nThe calculated RC value for first stage is " << RC1 << ", for the second stage is " << RC2 << " and for the third stage is " << RC3 <<"\n\n";

  do {

  cout << "Please enter the value of the first stage capacitor that will be used. Values from 1..100 nF are recommended\n\n";

  cin >> C1;

  if (C1 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the second stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C2;

  if (C2 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  do{

  cout << "\nPlease enter the value of the third stage capacitor. Again, values from 1..100 nF are recommended\n\n";

  cin >> C3;

  if (C3 <= 0 ){
  cout << "\nPlease enter a positive non-zero value!\n\n";
  valid_input = false;}
  else {valid_input = true;}
  }
  while(valid_input == false);

  float R1 = RC1 / C1;

  float R2 = RC2 / C2;

  float R3 = RC3 / C3;

  cout << "\nThe calculated first stage resistor value is " << R1 << " Ω. The second stage resistor value is " << R2 << " Ω. The second stage resistor value is " << R3 <<"\n ";
  cout << "\nUsing the Equal Component approach, R1 = R2, R3 = R4, R5 = R6\n";
  return 0; 
}