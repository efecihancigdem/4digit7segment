#include "Arduino.h"
#include "Fdig7seg.h"
using namespace std;


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

Fdig7seg::Fdig7seg() //constructor: makes the first initialization for the storage array,show and pin initialization
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			show[i][j] = true;
	for (int k = 2; k < 14; k++)
		pinMode(k, OUTPUT);
}

void Fdig7seg::clear() //Clears the show array
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 7; j++)
			show[i][j] = true;
}

void Fdig7seg::showtime()
{
	for (int i = 0; i < 4; i++) //run on the digits
	{
		for (int j = 0; j < 7; j++) digitalWrite(j + 6, true); //clear the segment before writing new stuff
		digitalWrite(2 + i, true); //turn the actual number on
		digitalWrite(2 + (i + 1) % 4, false); //turn of the rest
		digitalWrite(2 + (i + 2) % 4, false); //turn of the rest
		digitalWrite(2 + (i + 3) % 4, false); //turn of the rest
		digitalWrite(13, true); //decimal switch

		for (int j = 0; j < 7; j++)
		{
			digitalWrite(j + 6, show[i][j]); 
		}
		delay(1);
	}
}

void Fdig7seg::initialize(int segment, char number) {
	int n = (segment-1);
	
	if (number == 'A') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == '0' || number == 'O') {
		show[n][0]=false;
		show[n][1]=false;
		show[n][2]=false;
		show[n][3]=false;
		show[n][4]=false;
		show[n][5]=false;
	}
	else if (number == '1') {
		show[n][1] = false;
		show[n][2] = false;
	}
	else if (number == '2' || number == 'Z') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][6] = false;
	}
	else if (number == '3') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][6] = false;
	}
	else if (number == '4' || number== 'y') {
		show[n][1] = false;
		show[n][2] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == '5' || number=='S') {
		show[n][0] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == '6') {
		show[n][0] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == '7') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
	}
	else if (number == '8' || number == 'B') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == '9') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == 'n') {
		show[n][2]=false;
		show[n][4]=false;
		show[n][6]=false;
	}
	else if (number == 'C') {
		show[n][0] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][5] = false;
	}
	else if (number == 'd') {
		show[n][0] = false;
		show[n][1] = false;
		show[n][2] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == 'E') {
		show[n][0]=false;
		show[n][3]=false;
		show[n][4]=false;
		show[n][5]=false;
		show[n][6]=false;
	}
	else if (number == 'F') {
		show[n][0] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == 'P') {
		show[n][0]=false;
		show[n][1]=false;
		show[n][4]=false;
		show[n][5]=false;
		show[n][6]=false;

	}
	else if (number == 'o') {
		show[n][2] = false;
		show[n][3] = false;
		show[n][4] = false;
		show[n][6] = false;
	}
	else if (number == 'u') {
		show[n][2] = false;
		show[n][3] = false;
		show[n][4] = false;
	}
	else if (number == 'r') {
		show[n][4] = false;
		show[n][6] = false;
	}
	else if (number == 'H') {
		show[n][1] = false;
		show[n][2] = false;
		show[n][4] = false;
		show[n][5] = false;
		show[n][6] = false;
	}
	else if (number == 'I') {
		show[n][4] = false;
		show[n][5] = false;
	}
	else if (number == 'j' || number == 'J') {
		show[n][1] = false;
		show[n][2] = false;
		show[n][3] = false;
	}
	else if (number == 'L') {
		show[n][3] = false;
		show[n][4] = false;
		show[n][5] = false;
	}


}