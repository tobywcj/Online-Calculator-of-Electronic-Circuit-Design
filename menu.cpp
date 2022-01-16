//BY Xavier Yip SSID 201310964
#include "menu.h"
#include "passive.h"
#include "active.h"
#include <iostream>
using namespace std;

void menu(){
  cout << "Welcome to the Op-Amp calculator! This calculator is designed to calculate the needed resistor value for you! You will be needed to provide the cut-off frequency and the capcacitor's values. Below, you can choose the type of filter that you want to build. Thank you for using our calculator!\n\n";

  cout << "Here are the short forms that will be used below\n";

  cout << "CH = chebyshev\tBU = butterworth\tLP = low-pass\t HP = high-pass\n\n";

  cout << "-----------------------------\n";
  cout << "Types\tRipples\t Poles\tCode\n";
  cout << "-----------------------------\n";
  cout << "CH\tLP\t\t0.5\t\t2\t1112\n";
  cout << "CH\tLP\t\t0.5\t\t4\t1114\n";
  cout << "CH\tLP\t\t0.5\t\t6\t1116\n";
  cout << "CH\tHP\t\t0.5\t\t2\t1012\n";
  cout << "CH\tHP\t\t0.5\t\t4\t1014\n";
  cout << "CH\tHP\t\t0.5\t\t6\t1016\n";
  cout << "CH\tLP\t\t2\t\t2\t1102\n";
  cout << "CH\tLP\t\t2\t\t4\t1104\n";
  cout << "CH\tLP\t\t2\t\t6\t1106\n";
  cout << "CH\tHP\t\t2\t\t2\t1002\n";
  cout << "CH\tHP\t\t2\t\t4\t1004\n";
  cout << "CH\tHP\t\t2\t\t6\t1006\n";
  cout << "Passive\t\tNA\t\tNA\t0000\n";
  cout << "-----------------------------\n";
}

void get_code(){
  int code;
  cout << "Please refer the table above and type the 4 digits code for the desired circuit.\n";

  cin >> code;
  if (code == 0000){
    float fc;
    float c;

    float  R = passive(fc, c);
  }
  else if (code == 1112){
    float fc;
    float C;
    float Rb;

    float R =CHLP052(fc, C, Rb);
  }
  else if (code == 1012){
    float fc;
    float C;
    float Rb;

    float R =CHHP052(fc, C, Rb);
  }
  else if (code == 1002){
    float fc;
    float C;
    float Rb;

    float R =CHHP22(fc, C, Rb);
  }
  else if (code == 1114){
    float fc;
    float C1;
    float C2;
    float Rb;

    float R =CHLP054(fc, C1, C2, Rb);
  }
  else if (code == 1104){
    float fc;
    float C1;
    float C2;
    float Rb;

    float R =CHLP24(fc, C1, C2, Rb);
  }
  else if (code == 1014){
    float fc;
    float C1;
    float C2;
    float Rb;

    float R =CHHP054(fc, C1, C2, Rb);
  }
  else if (code == 1004){
    float fc;
    float C1;
    float C2;
    float Rb;

    float R =CHHP24(fc, C1, C2, Rb);
  }
  else if (code == 1106){
    float fc;
    float C1;
    float C2;
    float C3;
    float Rb;
    
    float R =CHLP26(fc, C1, C2, C3, Rb);
  }
  else if (code == 1116){
    float fc;
    float C1;
    float C2;
    float C3;
    float Rb;
    
    float R =CHLP056(fc, C1, C2, C3, Rb);
  }
  else if (code == 1006){
    float fc;
    float C1;
    float C2;
    float C3;
    float Rb;
    
    float R =CHHP26(fc, C1, C2, C3, Rb);
  }
  else if (code == 1016){
    float fc;
    float C1;
    float C2;
    float C3;
    float Rb;
    
    float R =CHHP056(fc, C1, C2, C3, Rb);
  }
  else{ 
    cout << "You have entered the wrong code, please enter again!\n\n";
    return get_code();
  }
 go_back_to_sub();

}
void go_back_to_sub() {
  string input;
  do {
    cout << "\nEnter 'b' or 'B' to go back to sub menu: ";
    cin >> input;
  } while (input != "b" && input != "B");
  menu();
  }