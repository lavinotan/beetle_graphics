// TurtleGraphics.cpp
// Construct class TurtleGraphics and process Turtle moves
// Include BeetleGraphics.h class interface file
// Author: Lavino Wei-Chung Chen 
// Date: June 18, 2020


#include "BeetleGraphics.h"
#include <iostream>
#include <array>

using namespace std;

//BeetleGraphics ctor - floor to all "true" values, as well as initialization of other data members
BeetleGraphics::BeetleGraphics(void)
	:current_row(STARTING_ROW), current_col(STARTING_COL), // initialize current location of pen and beetle to starting position
	current_direction(STARTING_DIRECTION), current_pen_position(STARTING_PEN_POSITION), // initialize current direction  and pen position
	m_Floor()
{
	// initialize true to entire m_Floor array
	for (unsigned int row = 0; row < NROWS; ++row) 
	{
		for (unsigned int col = 0; col < NCOLS; ++col)
		{
			m_Floor[row][col] = true;
		}
	}
}

// function to process the commands (cmds) contained in array "commands"
void BeetleGraphics::processBeetleMoves(const std::array< int, ARRAY_SIZE>& cmdArray)
{	
	bool isMove = false; // create a local variable to determine if beetle location is moving based on Cmds::MOVE call

	// read the commands in cmds array
	for (auto cmdCall = 0; cmdCall < ARRAY_SIZE; ++cmdCall)
	{
		// if command is not move forward
		if (!isMove) 
		{
			// check if command is one of the following cases
			switch (static_cast<Cmds>(cmdArray[cmdCall]))
			{
			case Cmds::PEN_UP: 
				current_pen_position = STARTING_PEN_POSITION; // set current_pen_position false - pen up
				break;

			case Cmds::PEN_DWN:
				current_pen_position = true; // set current_pen_position true - pen down
				break;

			case Cmds::TURN_RIGHT:
				if (current_direction == Directions::WEST) // if current_direction is WEST, set current_direction to NORTH
				{
					current_direction = Directions::NORTH;
				}
				else
				{
					// if current_direction is not WEST, set current_direction to the next direction based on Directions enum
					current_direction = static_cast<Directions>(static_cast<int>(current_direction) + 1);
				}
				break;

			case Cmds::TURN_LEFT:				
				if (current_direction == Directions::NORTH) // if current_direction is NORTH, set current_direction to WEST
				{
					current_direction = Directions::WEST;
				}
				else
				{
					// if current_direction is not NORTH, set current_direction to the next direction based on Directions enum
					current_direction = static_cast<Directions>(static_cast<int>(current_direction) - 1);
				}
				break;

			case Cmds::MOVE:
				isMove = true; // if command is MOVE, set isMove to true
				break;

			case Cmds::DISPLAY: 
				displayFloor(); // if command is DISPLAY, call function displayFloor() to draw the BeetleGraph			
				break;

			case Cmds::END_OF_DATA:
				cmdCall = ARRAY_SIZE; // if command is END_OF_DATA, set the cmdCall to the ARRAY_SIZE to end the for loop			
				break;

			default:
				cerr << "Error - Invalid Command Value" << endl; // print error if something goes wrong in this switch code
			}
		}
		else
		{
			// if the previous command is MOVE, call trackTurtleMoves function
			trackBeetleMoves(m_Floor, cmdArray[cmdCall]);

			// after moving and tracking the beetle location, set isMove back to false
			isMove = false;
		}		
	}
}

// trackBeetleMoves function to track and move beetle and pen locations and moves
void BeetleGraphics::trackBeetleMoves(std::array <std::array <bool, NCOLS>, NROWS>& floor, int moveNum)
{
	// if current_pen_position is true - pen down, track and mark beetle locations to false
	if (current_pen_position)
	{
		int next_location; // create variable for the next/future location where beetle moves to
				
		// check current_direction to determine beetle movement
		switch (current_direction)
		{
		case Directions::NORTH:
			next_location = current_row - moveNum;

			if (next_location < 0) // check if the future location is out of the floor boundary 
			{
				next_location = 0; // if future location is out of the boundary, set future location to the boundary
			}

			for (; current_row > next_location; --current_row)
			{
				floor[current_row][current_col] = false; // set beetle tracks to false
			}

			current_row = next_location; // set the current location to the future location
			break;

		case Directions::SOUTH:
			next_location = current_row + moveNum;

			if (next_location > NROWS) // check if the future location is out of the floor boundary
			{
				next_location = NROWS - 1; // if future location is out of the boundary, set future location to the boundary
			}

			for (; current_row < next_location; ++current_row)
			{
				floor[current_row][current_col] = false; // set beetle tracks to false
			}
			current_row = next_location; // set the current location to the future location
			break;

		case Directions::EAST:
			next_location = current_col + moveNum;
			
			if (next_location > NCOLS) // check if the future location is out of the floor boundary
			{
				next_location = NCOLS - 1; // if future location is out of the boundary, set future location to the boundary
			}
			
			for (; current_col < next_location; ++current_col)
			{
				floor[current_row][current_col] = false; // set beetle tracks to false
			}
			current_col = next_location; // set the current location to the future location
			break;
		
		case Directions::WEST:
			next_location = current_col - moveNum;

			if (next_location < 0) // check if the future location is out of the floor boundary
			{
				next_location = 0; // if future location is out of the boundary, set future location to the boundary
			}

			for (; current_col > next_location; --current_col)
			{
				floor[current_row][current_col] = false; // set beetle tracks to false
			}

			current_col = next_location; // set the current location to the future location
			break;

		default:
			cerr << "Error: Invalid Direction Value" << endl; // print error if something goes wrong in this switch code
		}		
	}
	else // track pen location when pen is up
	{
		switch (current_direction)
		{
		case Directions::NORTH:
			current_row -= moveNum; // move pen based on the number of move command
			if (current_row < 0) // check if the pen location is out of the floor boundary
			{
				current_row = 0;  // if pen location is out of the boundary, set future location to the boundary
			}
			break;
		
		case Directions::SOUTH:
			current_row += moveNum;
			if (current_row > NROWS) // check if the pen location is out of the floor boundary
			{
				current_row = NROWS - 1; // if pen location is out of the boundary, set future location to the boundary
			}
			break;

		case Directions::EAST:
			current_col += moveNum;
			if (current_col > NCOLS) // check if the pen location is out of the floor boundary
			{
				current_col = NCOLS - 1; // if pen location is out of the boundary, set future location to the boundary
			}
			break;

		case Directions::WEST:
			current_col -= moveNum;
			if (current_col < 0) // check if the pen location is out of the floor boundary
			{
				current_col = 0; // if pen location is out of the boundary, set future location to the boundary
			}
			break;

		default:
			cerr << "Error: Invalid Direction Value" << endl; // print error if something goes wrong in this switch code
		}
	}	
}

// displayFloor function to draw the floor and beetlegraph
void BeetleGraphics::displayFloor() const
{
	for (auto const &row: m_Floor)
	{
		for (auto const& floorCell : row)
		{
			if (!floorCell) // if the cell value is false, print out *
			{
				cout << "*";
			}
			else // if the cell value is true, print out blank
			{
				cout << " ";
			}
		}

		cout << "\n"; // change row
	}

	cout << "\n\n";
}

