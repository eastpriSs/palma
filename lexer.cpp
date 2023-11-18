



elex // elex
TableKWords::getLexInKw(std::string_view word) const{
	for ( int i = 0; i < kWords.size(); ++i ){ // # 1
		if ( kWords[i] == word ){
			return kWordsLex[i];
		}
	}
	return lnone; // did not found
}

void TableKWords::enterKw(std::string_view strValue, elex lValue ){
	kWords.push_back( string(strValue) );
	kWordsLex.push_back( lValue );

}


TableKWords::TableKWords()
: kWords(), kWordsLex()
{
	enterKw("const", elex::lconst);
	enterKw("else",  elex::lelse);
	enterKw("if",    elex::lif);
	enterKw("out",   elex::lout_fun);
	enterKw("then",  elex::lthen);
	enterKw("var",   elex::lvar);
	enterKw("=", 	 elex::lasg);
	enterKw(".", 	 elex::ldot);
	enterKw(",", 	 elex::lcomma);
	enterKw(":", 	 elex::lcolon);
	

}

void
Lexer::identLex()
// is next lex is kw or identif
{
	using namespace icharStream;

	name = "";
	std::string word = {};
	size_t maxNameSize = 20;

	while ( currCh != space 
			&&  currCh != tab 
			&& currCh != enter 
			&& word.size() < maxNameSize)
	{
		word += currCh;		
		nextChar();
		lex = kw.getLexInKw(word);
		if (lex != lnone){
			return;
		}
	}
	lex = elex::lname;
	name = word;
}

void
Lexer::nextLex(){
	using namespace icharStream;
	
	while ( currCh == space ||  currCh == tab || currCh == enter ) nextChar();	

	if (currCh == '\0'){
		lex = elex::leof;
		return;
	}

	if ( isdigit(currCh) ){
		lex = elex::lnum;
		return;
	}

	if ( isalpha(currCh) )
		identLex();

	switch ( currCh ) {
		case '=':
			lex = elex::lasg;
			break;
	}
	nextChar();
}
