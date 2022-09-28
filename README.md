# Online Calculator of Electronic Circuit Design
This project aims to assist electronic engineers for three indispensable categories of calculation in electronic designs, which are electrical components, op-amp and filter calculator.

# Release/Demo Version
![image](https://user-images.githubusercontent.com/71925079/192723990-3031a347-e52e-43ee-b40d-667137b1e72e.png)
link to the online calculator: https://replit.com/@WongChenJing (ONLY accessing the op-amp calculator)

# Special Features
- Login Encryption

## ***Electrical Component Calculator***
![image](https://user-images.githubusercontent.com/71925079/192732562-25fbf89c-b8df-4b3e-9ec2-d45abf30b39c.png)

## ***Op-amp Calculator***
![image](https://user-images.githubusercontent.com/71925079/192733580-83d229f2-48f5-4caf-a077-b5c1c744c9e2.png)

- Pre-set common 5 industrial op-amp (Inverting / Non-inverting)
- Consideration of imperfections (CMRR & slew rate)
- Reminders of op-amp constraints

## ***Filter Calculator***
![image](https://user-images.githubusercontent.com/71925079/192733174-f1c14838-cb77-41d7-987a-8d3dd8bfc143.png)

# Explanation of Op-amp Calculator
## 1. Ideal closed-loop gain
- G_(non-inv)≈1+R_2/R_1
- G_inv≈-R_2/R_1 

The approximate expressions used for closed-loop voltage gain which are typically used to design amplifiers (the above equations) only valid when the open-loop gain, A, is very high.

An op-amp is a differential voltage amplifier. For an ideal op-amp, the output voltage is determined solely by the relationship:

- V_out=A(V^+-V^- )

where A is the open-loop gain, and V + and V – are the voltages presented to the non-inverting and inverting inputs.

Ideal op-amps also have the following three properties:
- The open-loop gain, A, is infinite
- The input impedance is infinite
- The output impedance is zero

For this calculator, we can find the ideal closed-loop gain of non-inverting and inverting op-amps in terms of both voltage gain and decibels.

## 2. Standard closed-loop gain

- G_(non-inv)=A/(1+AB)
- G_inv=-A(1-B)/(1+AB)
- B=R_1/(R_1+R_2 )
There are some consequences of the roll-off in the open-loop gain (where assumption that A is very large is no longer valid). The above equations are gain equations for the non-inverting and inverting amplifiers, where A is the open loop gain and B is the feedback ratio for both configurations.

For this calculator, we can find the actual closed-loop gain of non-inverting and inverting op-amps for various target gains or specific resistors (by inputting R1  and R2) at various frequencies in terms of both voltage gain and decibels.

## 3. Slew rate

- absolute value of slew rate=Aω=A2πf×10^(-6)  (V/us)

The slew rate is a measure of the ability of the op-amp to change the output voltage as a function of time. It defines the limit for the rate of change of output voltage with time. 

For sinusoidal signals, the slew rate determines the maximum product of output amplitude and frequency without producing distortion on the output waveform. High slew rate op-amps require low source-impedance power supplies in order to meet the slew rate specification and they can also introduce noise on the power supply rails.

For this calculator, we can check whether user’s input signal frequency and its corresponding voltage amplitude will constitute a distorted output or not for the op-amp chosen by user from the op-amp menu.

## 4. Common Mode Rejection Ratio

- CMRR=20log⁡(A_diff/A_comm ) (dB)

where Adiff and Acom are the differential and common-mode voltage gains of the op-amp.

Due to imperfections within the op-amp circuitry, there will also be an output which is proportional to the average value of the two inputs. This unwanted response is the common-mode gain.

CMRR is a figure of merit for the op-amp which indicates to what extent the op-amp ‘rejects’ common-mode signals (by not amplifying them).

For this calculator, we can find the differential input signal, common-mode input signal, open-loop differential gain, open-loop common-mode gain and an output voltage due to the differential input plus an additional output due to the common-mode gain.







