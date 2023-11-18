#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include <vector>

namespace icharStream
{
	char 		  currCh   = ' ';
	size_t  	  idCurrCh = 0;
	std::vector<char> streamCh = {};
	
	void nextChar();
	void outStream();

	class makeCharStream{
	public:
		makeCharStream(std::string_view path);
		makeCharStream() = delete;
	};

	#include "charD.cpp"
};


