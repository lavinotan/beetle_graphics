// BeetleGraphics.h
// Declaration of class BeetleGraphics.
// Member functions are defined in BeetleGraphics.cpp.
// Author: Lavino Wei-Chung Chen 
// Date: June 18, 2020

#pragma once
#include <array>

// Define some enum types that will be used in solution 
// commands enum types "Cmds" and "Directions" 
enum class Cmds : unsigned short { PEN_UP = 1, PEN_DWN = 2, TURN_RIGHT = 3, TURN_LEFT = 4, MOVE = 5, DISPLAY = 6, END_OF_DATA = 9 };
enum class Directions : unsigned short { NORTH, EAST, SOUTH, WEST };

class BeetleGraphics
{
private:
	const static size_t NROWS = 22;  // number of rows in floor
	const static size_t NCOLS = 70;  // number of colums in floor

	const static int STARTING_ROW = 0;    // row that beetle will start in
	const static int STARTING_COL = 0;    // column that beetle will start in

	int current_row; // row that beetle is currently at
	int current_col; // column that beetle is currently at

	const static Directions STARTING_DIRECTION = Directions::SOUTH; // direction 
	                      // that beetle will be facing at the start

	Directions current_direction; // direction that beetle is going to

	const static bool STARTING_PEN_POSITION = false; // Pen will be up when 
	                            // program starts
                                // false means pen up, true means pen down

	bool current_pen_position; // pen status - false means pen up, true means pen down

	void displayFloor() const;  // will display floor on the screen

	std::array <std::array <bool, NCOLS>, NROWS> m_Floor;   // floor on which beetle will draw

public:
	const static int ARRAY_SIZE = 1000; // beetle movement command size

	BeetleGraphics(void); //ctor will init. floor to all "true" values, 
	                      //     as well as initialization of other data members
	
	void processBeetleMoves( const std::array< int, ARRAY_SIZE> &);  // will process
	                   // the commands contained in array "commands"

	void trackBeetleMoves(std::array <std::array <bool, NCOLS>, NROWS> &, int); // will track and move pen and beetle locations

};


