//BY Wong Chen Jing el19cjw SSID 201386604

#include "opamp_menu_items.h"
#include "essential_func.h"

void opamp_menu_item_1() {

  std::cout << "\n| Calculation of closed-loop gain of ideal non-inverting and inverting op-amp |\n\n";

  int option;
  std::string input_string;
  bool valid_input = false;

  do {
    std::cout << "Type '0' for the calculation of non inverting op-amp\n";
    std::cout << "Type '1' for the calculation of inverting op-amp\n";
    std::cout <<"\nOp-Amp number: ";
    std::cin >> input_string;
    valid_input = check_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      option = std::stoi(input_string);  // convert to int
      if (option == 0 || option ==1) {
        valid_input = true;
      } else {
        std::cout << "\nPlease enter either '0' or '1' to choose corresponding op-amp\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  float R1 = 0.0;
  std::cout << "\nPlease enter R1 value(Ω):\n";
  std::cin >> R1;
  float R2 = 0.0;
  std::cout << "Please enter R2 value(Ω):\n";
  std::cin >> R2;

  if (option == 0) {
  // create an object using the constructor
  Gain ideal_noninv (R1, R2, 0.0);
  std::cout << "The closed-loop gain of your ideal non-inverting op-amp: " << ideal_noninv.get_ideal_noninv_G() << "\n";

  float decibel = ideal_noninv.get_decibel(ideal_noninv.get_ideal_noninv_G());
  std::cout << "The closed-loop gain in terms of dB: " << decibel << " dB\n";
  }

  else if (option == 1) {
  Gain ideal_inv(R1, R2, 0.0);
  std::cout << "The closed-loop gain of your ideal inverting op-amp: " << ideal_inv.get_ideal_inv_G() << "\n";

  float decibel = ideal_inv.get_decibel(ideal_inv.get_ideal_inv_G());
  std::cout << "The closed-loop gain in terms of dB: " << decibel << " dB\n";
  }
}

//////////////////////////////////////////////////////////////////////////////

void opamp_menu_item_2() {
  
  std::cout << "\n| Calculation of closed-loop gain of standard non-inverting and inverting op-amp |\n\n";

  int option;
  std::string input_string;
  bool valid_input = false;

  do {
    std::cout << "Type '0' for the calculation of non-inverting op-amp\n";
    std::cout << "Type '1' for the calculation of inverting op-amp\n";
    std::cout <<"\nOp-Amp number: ";
    std::cin >> input_string;
    valid_input = check_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      option = std::stoi(input_string);  // convert to int
      if (option == 0 || option ==1) {
        valid_input = true;
      } else {
        std::cout << "\n\n<< Please enter either '0' or '1' to choose corresponding op-amp >>\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  float fT = 0;
  std::cout << "\nPlease enter transition frequency of your op-amp (Hz):\n";
  std::cin >> fT;
  
  bool nothing = true;
  float signal_freq = 0;
  std::cout << "\n<<Reminder>> : Maximum closed-loop gain can be obtained by entering the highest frequency in the signal frequency range ! )\n\n";
  std::cout << "Enter a signal frequency you want to amplify for a non-inverting op-amp circuit (Hz):\n";

  // ensure the user limits the use of the op-amp to frequencies << 0.1 fT
  while (nothing) {
    std::cin >> signal_freq;
    if (signal_freq >= fT * 0.1) {
      std::cout << "Please enter a value of signal frequency which is < 0.1 fT will ensure the open-loop gain is at least 20 dB (Hz):\n";
    }
    else {
      nothing = false;
    }
  }

  // calculation of open loop gain
  Gain open_loop_gain(0.0, 0.0, fT);
  float A = open_loop_gain.get_A(fT, signal_freq);
  std::cout << "\nThe calculated open loop gain = " << A << "\n";
  std::cout << "The Gain Bandwidth Product = " << fT << "\n";
  
  // calculation of non inverting op-amp
  if (option == 0) { 

  std::string input_string;
  do {
    std::cout << "\nDo you have any target gain of this non-inverting op-amp? 'yes' or 'no'\n";
    std::cin >> input_string;
  } while (input_string != "yes" && input_string != "no");
  
  if (input_string == "yes") {

    Gain standard_noninv_targetgain(0.0, 0.0, fT);

    float target_gain = 0;
    std::cout << "What is your target gain?\n";
    std::cin >> target_gain;
    float B_target_gain = standard_noninv_targetgain.get_B_target_gain(target_gain);
    std::cout << "\nThe closed-loop gain of your standard non-inverting op-amp = " << standard_noninv_targetgain.get_standard_noninv_G_targetgain(A, B_target_gain) << "\n";

    float decibel = standard_noninv_targetgain.get_decibel(standard_noninv_targetgain.get_standard_noninv_G_targetgain(A, B_target_gain));
    std::cout << "\nThe closed-loop gain in terms of dB = " << decibel << " dB\n";
  }

  // calculation by using standard equation of closed-loop gain of non-inverting op-amp
  else if (input_string == "no") {

  float R1 = 0.0;
  std::cout << "\nPlease enter R1 value(Ω) to calculate the feedback ratio:\n";
  std::cin >> R1;
  float R2 = 0.0;
  std::cout << "Please enter R2 value(Ω) to calculate the feedback ratio:\n";
  std::cin >> R2;

  Gain standard_noninv(R1, R2, fT);
  std::cout << "\nThe feedback ratio = " << standard_noninv.get_B() << "\n\n";
  std::cout << "The closed-loop gain of your standard non-inverting op-amp = " << standard_noninv.get_standard_noninv_G(A) << "\n\n";

  float decibel = standard_noninv.get_decibel(standard_noninv.get_standard_noninv_G(A));
  std::cout << "The closed-loop gain in terms of dB = " << decibel << " dB\n";

  }
  }
  
  // calculation of non-inverting op-amp
  else if (option == 1) {

  float R1 = 0.0;
  std::cout << "\nPlease enter R1 value(Ω) to calculate the feedback ratio:\n";
  std::cin >> R1;
  float R2 = 0.0;
  std::cout << "Please enter R2 value(Ω) to calculate the feedback ratio:\n";
  std::cin >> R2;

  Gain standard_inv(R1, R2, fT);
  std::cout << "\nThe feedback ratio = " << standard_inv.get_B() << "\n";
  std::cout << "\nThe closed-loop gain of your standard inverting op-amp = " << standard_inv.get_standard_inv_G(A) << "\n\n";

  float decibel = standard_inv.get_decibel(standard_inv.get_standard_inv_G(A));
  std::cout << "The closed-loop gain in terms of dB =  " << decibel << " dB\n";

  }

}

//////////////////////////////////////////////////////////////////////////////////////

void opamp_menu_item_3() {

  // create a map of op-amps with its slew rate value
  std::map<std::string, float> opamp_slew_rate;
  opamp_slew_rate["CA3140E Op-Amp"] = 9.0;
  opamp_slew_rate["741 Op-Amp"] = 0.5;
  opamp_slew_rate["OP07 Op-Amp"] = 0.3;
  opamp_slew_rate["OPA344 Op-Amp"] = 0.8;
  opamp_slew_rate["OPA657 Op-Amp"] = 700.0;
  int map_key_counter = 1;

  std::cout << "\n| Checking slew rate for distortion |\n";

  
  std::cout << "\n<< Choose an Op-Amp to check your signal frequency will be distorted for the selected Op-Amp >>\n\n";
  std::map<std::string, float>::iterator i;
  for (i = opamp_slew_rate.begin(); i != opamp_slew_rate.end(); i++) {
    std::cout << map_key_counter << ". " << i->first <<", " << i->second << " V/us" << std::endl;
    map_key_counter++;
  }

  int option;
  std::string input_string;
  bool valid_input = false;
  std::cout <<"\nOp-Amp number: ";

  do {
    std::cin >> input_string;
    valid_input = check_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      option = std::stoi(input_string);  // convert to int
      if (option >= 1 && option <= map_key_counter - 1) {
        valid_input = true;
      } else {
        std::cout << "Please enter '1'-'5' to choose corresponding op-amp\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  float amplitude = 0.0;
  std::cout << "\nPlease enter the value of output amplitude of voltage of your input signal(V):\n";
  std::cin >> amplitude;
  float f = 0.0; 
  std::cout << "\nPlease enter the signal frequency(Hz):\n";
  std::cin >> f;

  Imperfection slew_rate (amplitude, f, 0.0);

  std::cout << "\nThe corresponding slew rate of your signal frequency = " << slew_rate.get_slew_rate() << "V/us";

  if (option == 1) {
    if (slew_rate.get_slew_rate() <= opamp_slew_rate["741 Op-Amp"]) {
      std::cout << "\nThe Op-Amp will produce an UNDISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
    else {
      std::cout << "\nThe Op-Amp will produce a DISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
  }

  if (option == 2) {
    if (slew_rate.get_slew_rate() <= opamp_slew_rate["CA3140E Op-Amp"]) {
      std::cout << "\nThe Op-Amp will produce an UNDISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
    else {
      std::cout << "\nThe Op-Amp will produce a DISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
  }

  if (option == 3) {
    if (slew_rate.get_slew_rate() <= opamp_slew_rate["OP07 Op-Amp"]) {
      std::cout << "\nThe Op-Amp will produce an UNDISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
    else {
      std::cout << "\nThe Op-Amp will produce a DISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
  }

  if (option == 4) {
    if (slew_rate.get_slew_rate() <= opamp_slew_rate["OPA344 Op-Amp"]) {
      std::cout << "\nThe Op-Amp will produce an UNDISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
    else {
      std::cout << "\nThe Op-Amp will produce a DISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
  }

  if (option == 5) {
    if (slew_rate.get_slew_rate() <= opamp_slew_rate["OPA657 Op-Amp"]) {
      std::cout << "\nThe Op-Amp will produce an UNDISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
    else {
      std::cout << "\nThe Op-Amp will produce a DISTORTED output for an " << amplitude << " V, " << f << " Hz signal.\n";
    }
  }
}

//////////////////////////////////////////////////////////////////////////////////

void opamp_menu_item_4() {

  // create a map of op-amps with its CMRR value
  std::map<std::string, float> opamp_CMRR;
  opamp_CMRR["CA3140E Op-Amp"] = 90.0; // in dB
  opamp_CMRR["741 Op-Amp"] = 90.0;
  opamp_CMRR["OP07 Op-Amp"] = 123.0;
  opamp_CMRR["OPA344 Op-Amp"] = 92.0;
  opamp_CMRR["OPA657 Op-Amp"] = 89.0;
  int map_key_counter = 1;

  std::cout << "\n| Calculation additional output voltage due to common-mode gain  |\n";

  std::cout << "\n<< Choose an Op-Amp to check your additional output voltage for the selected Op-Amp >>\n\n";
  std::map<std::string, float>::iterator i;
  for (i = opamp_CMRR.begin(); i != opamp_CMRR.end(); i++) {
    std::cout << map_key_counter << ". " << i->first << ", " << i->second << " dB (CMRR)" << std::endl;
    map_key_counter++;
  }

  std::cout << "\n( There is a limited range for each input corresponding to each Op-Amp, invalid value will pop up a reminder throughout the calculation )\n\n";

  int option;
  std::string input_string;
  bool valid_input = false;
  std::cout <<"Op-Amp number: ";

  do {
    std::cin >> input_string;
    valid_input = check_integer(input_string);
    // if input is not an integer, print an error message
    if (valid_input == false) {
      std::cout << "Enter an integer!\n";
    } else {  // if it is an int, check whether in range
      option = std::stoi(input_string);  // convert to int
      if (option >= 1 && option <= map_key_counter - 1) {
        valid_input = true;
      } else {
        std::cout << "\nPlease enter '1'-'5' to choose corresponding op-amp\n";
        valid_input = false;
      }
    }
  } while (valid_input == false);

  float add_Vout, noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout, V_supply;

  if (option == 1) {

    do {

      std::cout << "\nPlease enter your non-inverting input signal(V):\n";
      std::cin >> noninv_V;
      std::cout << "\nPlease enter your inverting input signal(V):\n";
      std::cin >> inv_V;

      Imperfection opamp_inputs (0.0, 0.0, 0.0);
      opamp_inputs.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
      
      // check max differential input signal
      if (diff_Vin > 30 || diff_Vin < -30) {
        std::cout << "\n<<Reminder>> : Exceed the maximum value of differential input signal of 741 Op-Amp (30 V), please enter a value smaller than 30 V\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
      
      // check the range of common-mode input signal 
      if (comm_Vin > 15 || comm_Vin < -15) {
        std::cout << "\n<<Reminder>> : Exceed common-mode input signal of 741 Op-Amp, please enter a smaller value of either the input signals !\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }

    } while (valid_input == false);

    do {
      std::cout << "\nPlease enter your target or measured output voltage(V):\n";
      std::cin >> target_Vout; 
      // check the range of output voltage
      if (target_Vout > 14  || target_Vout < -14) {
        std::cout << "\n<<Reminder>> : Exceed the output voltage swing of 741 Op-Amp which is between 14 V and -14 V, please enter a value between them\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
    } while (valid_input == false);

    Imperfection opamp (0.0, 0.0, opamp_CMRR["741 Op-Amp"]);
    opamp.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
    std::cout << "\n\n----------------------------------------------------\n\n";
    std::cout << "The differential input signal = " << diff_Vin << " V\n";
    std::cout << "The common-mode input signal = " << comm_Vin << " V\n";
    std::cout << "The open-loop common-mode gain = " << A_comm << "\n\n";
    std::cout << "The differential output voltage = " << diff_Vout << " V\n";
    std::cout << "The additional common-mode output voltage = " << add_Vout << " V\n";
    std::cout << "The total actual output voltage = " << total_Vout << " V\n";
    
  }

  if (option == 2) {

    do {

      std::cout << "\nPlease enter your non-inverting input signal(V):\n";
      std::cin >> noninv_V;
      std::cout << "\nPlease enter your inverting input signal(V):\n";
      std::cin >> inv_V;

      Imperfection opamp_inputs (0.0, 0.0, 0.0);
      opamp_inputs.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
      
      // check max differential input signal
      if (diff_Vin > 8 || diff_Vin < -8) {
        std::cout << "\n<<Reminder>> : Exceed the maximum value of differential input signal of CA3140E Op-Amp (8 V), please enter a value smaller than 8 V\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
      
      // check the range of common-mode input signal 
      if (comm_Vin > 12 || comm_Vin < -15) {
        std::cout << "\n<<Reminder>> : Exceed common-mode input signal of CA3140E Op-Amp, please enter a smaller value of either the input signals !\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }

    } while (valid_input == false);

    do {
      std::cout << "\nPlease enter your target or measured output voltage(V):\n";
      std::cin >> target_Vout; 
      // check the range of output voltage
      if (target_Vout > 13 || target_Vout < -13) {
        std::cout << "\n<<Reminder>> : Exceed the output voltage swing of CA3140E Op-Amp which is between 13 V and -13 V, please enter a value between them\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
    } while (valid_input == false);

    Imperfection opamp (0.0, 0.0, opamp_CMRR["CA3140E Op-Amp"]);
    opamp.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);

    std::cout << "\n\n----------------------------------------------------\n\n";
    std::cout << "The differential input signal = " << diff_Vin << " V\n";
    std::cout << "The common-mode input signal = " << comm_Vin << " V\n";
    std::cout << "The open-loop differential gain = " << A_diff << "\n";
    std::cout << "The open-loop common-mode gain = " << A_comm << "\n\n";
    std::cout << "The differential output voltage = " << diff_Vout << " V\n";
    std::cout << "The additional common-mode output voltage = " << add_Vout << " V\n";
    std::cout << "The total actual output voltage = " << total_Vout << " V\n";

  }

  if (option == 3) {

    do {

      std::cout << "\nPlease enter your non-inverting input signal(V):\n";
      std::cin >> noninv_V;
      std::cout << "\nPlease enter your inverting input signal(V):\n";
      std::cin >> inv_V;

      Imperfection opamp_inputs (0.0, 0.0, 0.0);
      opamp_inputs.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
      
      // check max differential input signal
      if (diff_Vin > 14 || diff_Vin < -14) {
        std::cout << "\n<<Reminder>> : Exceed the maximum value of differential input signal of OPA07 Op-Amp (14 V), please enter a value smaller than 14 V\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
      
      // check the range of common-mode input signal 
      if (comm_Vin > 14 || comm_Vin < -14) {
        std::cout << "\n<<Reminder>> : Exceed common-mode input signal of OPA07 Op-Amp, please enter a smaller value of either the input signals !\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }

    } while (valid_input == false);

    do {
      std::cout << "\nPlease enter your target or measured output voltage(V):\n";
      std::cin >> target_Vout; 
      // check the range of output voltage
      if (target_Vout > 13 || target_Vout < -13) {
        std::cout << "\n<<Reminder>> : Exceed the output voltage swing of OPA07 Op-Amp which is between 13 V and -13 V, please enter a value between them\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
    } while (valid_input == false);

    Imperfection opamp (0.0, 0.0, opamp_CMRR["OP07 Op-Amp"]);
    opamp.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
    std::cout << "\n\n----------------------------------------------------\n\n";
    std::cout << "The differential input signal = " << diff_Vin << " V\n";
    std::cout << "The common-mode input signal = " << comm_Vin << " V\n";
    std::cout << "The open-loop common-mode gain = " << A_comm << "\n\n";
    std::cout << "The differential output voltage = " << diff_Vout << " V\n";
    std::cout << "The additional common-mode output voltage = " << add_Vout << " V\n";
    std::cout << "The total actual output voltage = " << total_Vout << " V\n";

  }

  if (option == 4) {
  
    do {
      std::cout << "Please enter the value of power supply of this Op-Amp ( +Vsupply must between +5V and +2.7V, -Vsupply must between -5V and -2.7V ) :\n";
      std::cin >> V_supply;
      std::cout << "\nPlease enter your non-inverting input signal(V):\n";
      std::cin >> noninv_V;
      std::cout << "\nPlease enter your inverting input signal(V):\n";
      std::cin >> inv_V;

      Imperfection opamp_inputs (0.0, 0.0, 0.0);
      opamp_inputs.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
      
      // check max differential input signal
      if (diff_Vin > 2*V_supply || diff_Vin < -2*V_supply) {
        std::cout << "\n<<Reminder>> : Exceed the maximum value of differential input signal of OPA344 Op-Amp (" << 2*V_supply << " V), please enter a value smaller than " << 2*V_supply << " V\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
      
      // check the range of common-mode input signal 
      if (comm_Vin > V_supply + 0.3 || inv_V < -0.3) {
        std::cout << "\n<<Reminder>> : Exceed common-mode input signal of OPA344 Op-Amp, please enter a smaller value of either the input signals !\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }

    } while (valid_input == false);

    do {
      std::cout << "\nPlease enter your target or measured output voltage(V):\n";
      std::cin >> target_Vout; 
      // check the range of output voltage
      if (target_Vout > V_supply || target_Vout < -V_supply) {
        std::cout << "\n<<Reminder>> : Exceed the output voltage swing of OPA344 Op-Amp which is between " << V_supply << " V and " << -V_supply << " V, please enter a value between them\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
    } while (valid_input == false);

    Imperfection opamp (0.0, 0.0, opamp_CMRR["OPA344 Op-Amp"]);
    opamp.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
    std::cout << "\n\n----------------------------------------------------\n\n";
    std::cout << "The differential input signal = " << diff_Vin << " V\n";
    std::cout << "The common-mode input signal = " << comm_Vin << " V\n";
    std::cout << "The open-loop common-mode gain = " << A_comm << "\n\n";
    std::cout << "The differential output voltage = " << diff_Vout << " V\n";
    std::cout << "The additional common-mode output voltage = " << add_Vout << " V\n";
    std::cout << "The total actual output voltage = " << total_Vout << " V\n";

  }

  if (option == 5) {

    do {

      std::cout << "\nPlease enter your non-inverting input signal(V):\n";
      std::cin >> noninv_V;
      std::cout << "\nPlease enter your inverting input signal(V):\n";
      std::cin >> inv_V;

      Imperfection opamp_inputs (0.0, 0.0, 0.0);
      opamp_inputs.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
      
      // check max differential input signal
      if (diff_Vin > 10 || diff_Vin < 10) {
        std::cout << "\n<<Reminder>> : Exceed the maximum value of differential input signal of OPA657 Op-Amp (10 V), please enter a value smaller than 10 V\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
      
      // check the range of common-mode input signal 
      if (comm_Vin > 2.5 || comm_Vin < -4) {
        std::cout << "\n<<Reminder>> : Exceed common-mode input signal of OPA657 Op-Amp, please enter a smaller value of either the input signals !\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }

    } while (valid_input == false);

    do {
      std::cout << "\nPlease enter your target or measured output voltage(V):\n";
      std::cin >> target_Vout; 
      // check the range of output voltage
      if (target_Vout > 3.5 || target_Vout < -3.5) {
        std::cout << "\n<<Reminder>> : Exceed the output voltage swing of OPA657 Op-Amp which is between 3.5 V and -3.5 V, please enter a value between them\n";
        valid_input = false;
      }
      else {
        valid_input = true;
      }
    } while (valid_input == false);

    Imperfection opamp (0.0, 0.0, opamp_CMRR["OPA657 Op-Amp"]);
    opamp.get_additional_CMRR_Vout (add_Vout,  noninv_V, inv_V, target_Vout, diff_Vin, comm_Vin, A_diff, A_comm, diff_Vout, total_Vout);
    std::cout << "\n\n----------------------------------------------------\n\n";
    std::cout << "The differential input signal = " << diff_Vin << " V\n";
    std::cout << "The common-mode input signal = " << comm_Vin << " V\n";
    std::cout << "The open-loop common-mode gain = " << A_comm << "\n\n";
    std::cout << "The differential output voltage = " << diff_Vout << " V\n";
    std::cout << "The additional common-mode output voltage = " << add_Vout << " V\n";
    std::cout << "The total actual output voltage = " << total_Vout << " V\n";
 }

}