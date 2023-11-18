#include <iostream>
#include "charD.h"
#include "syntax.h"

int main()
{
	icharStream::makeCharStream("book.txt");	
	iSyntax::SyntaxAnl a = {};
	a.startSyntaxAnl();
}
