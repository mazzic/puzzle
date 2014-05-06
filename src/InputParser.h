//============================================================================
// Name        : InputParser.h
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : InputParser process the data that are input by console at starting the game.
//============================================================================

#ifndef INPUTPARSER_H_
#define INPUTPARSER_H_

#include <vector>
#include <string>

class InputParser {
public:
	InputParser(std::vector<std::string>& strings);
	virtual ~InputParser();
	unsigned getWidth() const
	{
		return m_width;
	}
	unsigned getHeight() const
	{
		return m_height;
	}
	unsigned getSize() const
	{
		return m_gameSize;
	}
private:
	InputParser();
	unsigned m_width;
	unsigned m_height;
	unsigned m_gameSize;
};

#endif /* INPUTPARSER_H_ */
