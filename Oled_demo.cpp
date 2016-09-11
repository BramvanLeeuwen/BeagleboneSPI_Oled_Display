#include <iostream>
#include <sstream>
#include "CharacterDisplay.h"
using namespace std;
using namespace exploringBB;

int main(){
   cout << "Starting EBB LCD Character Display Example" << endl;
   SPIDevice *busDevice = new SPIDevice(1,0); //Using first SPI bus (both loaded)
   busDevice->setSpeed(1000000);      // Have access to SPI Device object
   string s;                   // Using this to combine text and int data
   LCDCharacterDisplay display(busDevice, 20 , 4); // Construct 20x4 LCD Display
   display.clear();                   // Clear the character LCD module
   display.home();                    // Move the cursor to the (0,0) position
   display.print("OLEDDisplay van Bram"); // String to display on the first row
   display.setCursorPosition(1,3); // move the cursor to second row
   display.setCursorOff(false); // move the cursor to second row
  /*for (int r=0;r<4;r++)
   {  for (int c=0;c<20;c++)
	   display.setCursorPosition(r,c);
   }*/
   display.setCursorPosition(1,4);
   display.setCursorPosition(1,19);
   display.setCursorBlink(true);
   display.setCursorPosition(0,3);
   display.setCursorPosition(0,4);
   display.setCursorPosition(2,10);
   display.setCursorPosition(3,6);
         //s << "X=" << x;                 // construct a string that has an int value
   display.print("Temperatuur");         // print the string X=*** on the LCD module
   for(int x=0; x<=50; x++){       // Do this 10 times
      s="";                      // clear the ostringstream object s
      display.setCursorPosition(1,3); // move the cursor to second row
      //s << "X=" << x;                 // construct a string that has an int value
      display.print("Temperatuur");         // print the string X=*** on the LCD module
   }
   display.setCursorPosition(1,4);
   display.setDisplayOff(true);
   cout << "End of EBB LCD Character Display Example" << endl;



}
