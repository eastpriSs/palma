#include <iostream>
#include <string>
#include <vector>

#include "charD.h"

namespace iText
{
	const char space = ' ';
	const char tab   = '\t';
	const char enter = '\n';

};

namespace iLexer
{
	using namespace iText;
	using std::string;
	using std::string_view;
	using std::vector;

	enum elex { 
		lnone, lasg, lname, lnum, 
		lconst, lvar, lif, lthen, lelse, 
		ldot, lcomma, lcolon, lsemi, 
		llpar, lrpar, lout_fun, leof };

	class TableKWords
	{
		private:
			vector<string> kWords;
			vector<elex> kWordsLex;
		public:
			TableKWords();
			elex getLexInKw(std::string_view) const;
			void enterKw(std::string_view, elex);
	};

	
	class Lexer
	{
		private:
			TableKWords kw;
			void identLex();
			

		public:
			static elex lex;
			static string name;
			void nextLex();
	};
	
	#include "lexer.cpp"	
};

iLexer::elex iLexer::Lexer::lex    = lnone;
std::string iLexer::Lexer::name = {};


