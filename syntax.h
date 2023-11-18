#include <iostream>
#include "lexer.h"

namespace iSyntax
{
	using namespace iLexer;

	// class Error
	void expected(elex);

	class SyntaxAnl
	{
		private:
			Lexer lx;
		public:
			SyntaxAnl();
			void startSyntaxAnl();
	}; 

	#include "syntax.cpp"
};
