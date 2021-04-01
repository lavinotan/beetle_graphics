// Main Program - used to "test drive" the BeetleGraphics class
// File Name: DrawGraphics.cpp
// Author: Lavino Wei-Chung Chen 
// Date: June 18, 2020

// This program implements Turtle Graphics

// include and using statments


#include "BeetleGraphics.h"
#include <iostream>
#include <array>
using namespace std;

int main()
{
   // Declarations

   array<int, BeetleGraphics::ARRAY_SIZE> cmds = cmds = { 5,3,4,5,20,3,2,5,7,4,4,5,4,3,5,3,3,5,4,4,4,5,7,3,5,1,1, //first letter

	   5,2,2,3,5,7,4,5,4,4,1,5,4,4,5,1,2,5,3,3,5,3,3,5,4,1, //second letter	   

	   5,2,2,3,5,7,4,5,4,1, //third letter

	   5,2,2,5,3,4,4,5,3,3,5,8,1,//fourth letter

	   3,5,6,3,5,1,2,5,7,4,5,3,4,5,7,4,5,3,//fifth letter

	   1,4,5,9,3,5,24,4,//go to next line

	   2,5,7,4,5,2,4,5,3,4,4,5,3,4,5,2,4,5,7,3,5,1,1,//sixth letter

	   5,2,2,3,5,7,4,5,3,4,5,7,4,5,3,1,//seventh letter

	   3,3,5,6,3,2,5,7,4,5,1,1,5,3,2,4,5,2,4,5,1,3,5,1,5,1,4,5,3,3,5,3,3,5,
	   4,3,5,4,1,//eighth letter

	   4,5,3,3,2,5,3,4,5,3,4,4,5,3,3,5,8,1, //nineth letter

	   3,5,6,3,5,1,2,5,7,4,5,2,1,4,5,1,3,2,5,1,1,4,5,1,2,5,1,5,3,1,4,5,1,2,3,
	   5,1,1,4,5,1,2,5,1,1, //tenth letter 	                 

	   1, 5, 100, 2, 4, 5, 100, 4, 5, 100, 4, 5, 100, 4, 5, 100,
	   4, 5, 100, //Display border

	   1, 6, 9 }; // finish off

   BeetleGraphics beetleOne;  // create a BeetleGraphics object

   beetleOne.processBeetleMoves(cmds); // have beetle process commands

   system("pause");
   return 0;  
}
