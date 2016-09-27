/*
 * CharacterDisplay.h
 *
 *  Created on: Sep 7, 2016
 *      Author: bram
 */

#ifndef CHARACTERDISPLAY_H_
#define CHARACTERDISPLAY_H_
#include "SPIDevice.h"
#include <string>

namespace exploringBB {

/**
 * @class LCDCharacterDisplay
 * @brief A class that provides an interface to an LCD character module. It provices support
 * for multiple rows and columns and provides methods for formatting and printing text. You
 * should use a 4 wire interface and a 74XX595 to communicate with the display module.
 */
#define DEGREE_EUR_FONT 	0b10110010
	
class LCDCharacterDisplay {

private:
	SPIDevice *device;          //!< a pointer to the SPI device
	int width, height;          //!< the width and height of the module in characters
	void command(char i);
	void setup4bit();
	unsigned char cursorState;
	unsigned char displayState;
	unsigned char entryState;
	void writeCursorState();
	void writeDisplayState();
	void writeEntryState();

public:
	LCDCharacterDisplay(SPIDevice *device, int width, int height);

	virtual void write(char c);
	virtual void print(std::string message);

	virtual void clear();
	virtual void home();
	virtual int  setCursorPosition(int row, int column);
	virtual void setDisplayOff(bool displayOff);
	virtual void setCursorOff(bool cursorOff);
	virtual void setCursorBlink(bool isBlink);
	virtual void setCursorMoveOff(bool cursorMoveOff);
	virtual void setCursorMoveLeft(bool cursorMoveLeft);
	virtual void setAutoscroll(bool isAutoscroll);
	virtual void setScrollDisplayLeft(bool scrollLeft);

	virtual ~LCDCharacterDisplay();
};

} /* namespace exploringBB */




#endif /* CHARACTERDISPLAY_H_ */
