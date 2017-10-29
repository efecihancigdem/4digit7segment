/*
4dig7seg.h - Library for controlling 4 digit 7 segment display.
Created by Efe Cihan Cigdem, October 9, 2017.
Released into the public domain.
*/

/*
//DECLERATION OF THE PINS AND CONNECTIONS

digit1 => 2 - Pin 12 on 4 digit display to Arduino pin 2
digit2 => 3 - Pin 9 on 4 digit display to Arduino pin 3
digit3 => 4 - Pin 8 on 4 digit display to Arduino pin 4
digit4 = >5 - Pin 6 on 4 digit display to Arduino pin 5

//SEGMENT PINS

segA => 6 - Pin 11 on 4 digit display to Arduino pin 6
segB => 7 - Pin 7 on 4 digit display to Arduino pin 7
segC => 8 - Pin 4 on 4 digit display to Arduino pin 8
segD => 9 - Pin 2 on 4 digit display to Arduino pin 9
segE => 10 - Pin 1 on 4 digit display to Arduino pin 10
segF => 11 - Pin 10 on 4 digit display to Arduino pin 11
segG => 12 - Pin 5 on 4 digit display to Arduino pin 12
segH => 13 - Pin 3 on 4 digit display to Arduino pin 13
*/

#ifndef Fdig7seg_h
#define Fdig7seg_h
#include "Arduino.h"
using namespace std;


class Fdig7seg
{
public:
	Fdig7seg();
	bool show[3][7];
	void initialize(int segment, char number);
	void clear();
	void showtime(void);

};

#endif
