#include "C:\Users\eastpris\Desktop\palma\CharsStream\charsStream.h"
#include <iostream>
#include <string>

// TODO: make optimaze search indew of keyword, now O(n) # 1

const char space = ' ';
const char tab = '\t';
const char enter = '\n';

enum elex { lnone, lasg, lname, lnum, lconst, lvar, lif, lthen, lelse, ldot, lcomma, lcolon, lsemi, llpar, lrpar };

const size_t kwords_size = 10;
std::string kWords[kwords_size] = {};
elex kWordsLex[kwords_size] = {};

elex lex = lnone;
std::string name = {}; // name not lex

bool isLexInkWords(std::string_view lex);
int getIdLexInKw(std::string_view word);

void
number()
// translate number
{}

void
identLex()
// is next lex is kw or identif
{
	name = "";
	std::string word = {};
	size_t maxNameSize = 20;	
	while ( currCh == space ||  currCh == tab || currCh == enter )
	{
		word += currCh;
		std::cout << word << '\n';
		if ( isLexInkWords(word) ){
			lex = kWordsLex[getIdLexInKw(word)]; // hmm
			break;
		}
		nextChar();
	}
	name = word;
}

int
getIdLexInKw(std::string_view word){
	for ( size_t i = 0; i < kwords_size; ++i ){ // # 1
		if ( kWords[i] == word ){
			return i;
		}
	}
	return -1;
}

void enterKw(std::string_view strValue, elex lValue ){
	static size_t i = 0;
	kWords[i]    = strValue;
	kWordsLex[i] = lValue;
	++i;
}


bool isElementInRangeOfTable(const std::pair<short, short>& rangeIndx, const std::string_view& el){
	for (short i = rangeIndx.first; i <= rangeIndx.second; ++i){
		if ( kWords[i] == el){
			return true;
		}
	}
	return false;
}

std::pair<short, short>
findRangeWithLexInKW(const std::string_view& lx){
	unsigned short size  =  kwords_size;
	unsigned short left  = 0;
	unsigned short right = size - 1;

	while (left <= right){	
		unsigned short mid = (left + right) / 2;

		if ( kWords[mid][0] == lx[0])
			return std::pair<short, short> (left, right);

		if ( kWords[mid][0] < lx[0])
			left = mid + 1;

		if ( kWords[mid][0] > lx[0])
			right = mid - 1;
	} 
	return std::pair<short, short> (-1, -1); // did not found
}

// return index of lex
bool
isLexInkWords(std::string_view lex){
	std::pair<short, short> rangeWithCoincidence = findRangeWithLexInKW(lex);
	return isElementInRangeOfTable(rangeWithCoincidence, lex);
}

void
nextLex(){
	while ( currCh == space ||  currCh == tab || currCh == enter ) nextChar();
	
	if ( isalpha(currCh) )
		identLex();
	else if ( isdigit(currCh) )
		number();

	switch ( currCh ) {
		case '=':
			lex = elex::lasg;
			break;
	}
}
// elex { lnone, lasg, lname, lnum, lconst, lvar, lif, lthen, lelse, ldot, lcomma, lcolon, lsemi, llpar, lrpar };


void
initKw(){
	enterKw("var",   elex::lvar);
	enterKw("const", elex::lconst);
	enterKw("if",    elex::lif);
	enterKw("then",  elex::lthen);
	enterKw("else",  elex::lelse);
}

void
initLexStream(){
	initKw();
}

