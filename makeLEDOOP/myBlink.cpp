#include<iostream>
#include<fstream>
#include<string>
#include<sstream>

#include "derek_LED.h"

using namespace std;


int main(int argc, char* argv[]){
   if(argc!=2){
	cout << "Usage is makeLEDs <command>" << endl;
	cout << "   command is one of: on, off, flash or status" << endl;
	cout << " e.g. makeLEDs flash" << endl;
   }
   cout << "Starting the makeLEDs program" << endl;
   string cmd(argv[1]);
   int oLED = atoi(argv[2]);
   int o = atoi(argv[3]);

   LED leds[4] = { LED(0), LED(1), LED(2), LED(3) };
   for(int i=oLED; i<=4; i++){
      if(cmd=="on")leds[oLED].turnOn();
      else if(cmd=="off")leds[oLED].turnOff();
      else if(cmd=="flash")leds[oLED].flash("100"); //default is "50"
      else if(cmd=="status")leds[oLED].outputState();
      else if(cmd=="blink")leds[oLED].blink(o);
      else{ cout << "Invalid command!" << endl; }
  }
   cout << "Finished the makeLEDs program" << endl;
   return 0;
}
