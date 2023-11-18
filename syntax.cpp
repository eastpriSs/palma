SyntaxAnl::SyntaxAnl()
: lx()
{		
}

void expected(elex lex_ex)
{
	std::cerr << "SyntaxError" << lex_ex << "\n";
}

void checkLexOrThrowExcept(elex expect)
{
	if (Lexer::lex != expect) expected(expect);
}

void SyntaxAnl::startSyntaxAnl()
{
	lx.nextLex();
	// VAR
	if (Lexer::lex == elex::lvar)
	{
		lx.nextLex();
		checkLexOrThrowExcept(elex::lname);		
		lx.nextLex();
		checkLexOrThrowExcept(elex::lasg);
		lx.nextLex();
		checkLexOrThrowExcept(elex::lnum);
		std::cout << "Syntx nice!";
	}	
}
