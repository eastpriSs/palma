#include <iostream>
#include <string>
#include <array>

const std::array<std::string, 10> STable = {"a", "b", "c", "d", "e","f", "gh" ,"ga","gz", "h"};

bool isElementInRangeOfTable(const std::pair<short, short>& rangeIndx, const std::string_view& el){
	for (short i = rangeIndx.first; i <= rangeIndx.second; ++i){
		if (STable[i] == el){
			return true;
		}
	}
	return false;
}

std::pair<short, short>
findRangeWithLexInST(const std::string_view& lx){
	unsigned short size  = STable.size();
	unsigned short left  = 0;
	unsigned short right = size - 1;

	while (left <= right){	
		unsigned short mid = (left + right) / 2;

		if (STable[mid][0] == lx[0])
			return std::pair<short, short> (left, right);

		if (STable[mid][0] < lx[0])
			left = mid + 1;

		if (STable[mid][0] > lx[0])
			right = mid - 1;
	}
	return std::pair<short, short> (-1, -1);
}


bool
isLexInSTable(std::string_view lex){
	std::pair<short, short> rangeWithCoincidence = findRangeWithLexInST(lex);
	return isElementInRangeOfTable(rangeWithCoincidence, lex);
}

int
main(){
	std::cout << isLexInSTable("gz");
}
