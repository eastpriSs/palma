#include <iostream>

#include "C:\Users\eastpris\Desktop\palma\CharsStream\charsStream.h"
#include "C:\Users\eastpris\Desktop\palma\lexStream\lexStream.cpp"


int main(){
	makeCharsStream("book.txt");
	std::cout << "Stream of chars --- done! Length = " << streamCh.size() << std::endl;
	initLexStream();
	lex = elex::lvar;
	nextLex();
	std::cout << lex;
}
