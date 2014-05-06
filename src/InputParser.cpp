//============================================================================
// Name        : InputParser.cpp
// Author      : Lukasz Kresa
// Version     :
// Copyright   : ---
// Description : InputParser process the data that are input by console at startup.
//============================================================================

#include "InputParser.h"
#include <iostream>

InputParser::InputParser(std::vector<std::string>& strings) :
	m_width(1024), m_height(768), m_gameSize(3)
{
	for(unsigned i = 0; i < strings.size(); ++i)
	{
		if(strings[i] == "-r")
		{
			++i;
			if(strings[i] == "640")
			{
				m_width = 640;
				m_height = 480;
			}
			else if(strings[i] == "800")
			{
				m_width = 800;
				m_height = 600;
			}
			else if(strings[i] == "1024")
			{
				m_width = 1024;
				m_height = 768;
			}
			else if(strings[i] == "1280")
			{
				m_width = 1280;
				m_height = 1024;
			}
			else
			{
				std::cout << "ERROR: Resolution (" << strings[i] << ") is not supported. Using resolution: " << m_width << ".\n";
			}
		}
		if(strings[i] == "-s")
		{
			++i;
			bool validSize = true;
			for(auto ch = strings[i].begin(); ch != strings[i].end(); ++ch)
			{
				if(*ch < '0' || *ch > '9')
				{
					validSize = false;
					std::cout << "ERROR: Game size is not a number. Using game size: 3" << ".\n";
					break;
				}
			}
			if(validSize)
				m_gameSize = atoi(strings[i].c_str());
		}
	}
}

InputParser::~InputParser() {
	// TODO Auto-generated destructor stub
}

