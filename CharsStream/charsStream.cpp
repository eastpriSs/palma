
char currCh = ' ';
size_t idCurrCh = 0;
std::vector<char> streamCh = {};


void
nextChar()
{ currCh = streamCh[idCurrCh++]; }

void
makeCharsStream(std::string_view path)
{
	std::ifstream f( std::string{path} );
	std::string line = {};

	while (std::getline(f, line)){
		for (const char& ch : line){
			streamCh.push_back(ch);	
		}
	}
	nextChar(); // first char	
}	
