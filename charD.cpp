

void nextChar()
{
	currCh = streamCh[idCurrCh++];
}

void outStream()
{
	using std::cout;
	for (const char& i : streamCh)
		cout << i << ' '; 
}

makeCharStream::makeCharStream(std::string_view path)
{
	std::ifstream f( std::string{path} );
	std::string line = {};

	while (std::getline(f, line)){
		for (const char& ch : line){
			streamCh.push_back(ch);	
		}
	}
	streamCh.push_back('\0');
}
