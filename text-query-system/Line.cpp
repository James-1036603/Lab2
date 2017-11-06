// -------------------------------------------
//					Line
// -------------------------------------------

#include "Line.h"

Line::Line(const string& line)
{
	// Hint: some of string's member functions might come in handy here
	// for extracting words.
	Line::populateVectorWithWords(line);
	
}

bool Line::contains(const Word& search_word) const
{
	if(search_word.isQueryable())
	{
		return Line::searchForWordInLine(search_word);
	}
	
	else return false;
}

void Line::populateVectorWithWords(const string& line)
{
	auto tempStr = new char [line.length()+1];
        strcpy(tempStr,line.c_str());
        auto ch = strtok(tempStr," ");
        while(ch!=0){
                Word tmpWord(ch);
                _wordsInLine.push_back(tmpWord);
                ch = strtok(NULL," ");
}
}

bool Line::searchForWordInLine(const Word& searchWord) const
{
	bool found = false;
	for(auto i = 0u; i != _wordsInLine.size(); i++)
	{
		if(_wordsInLine[i]==searchWord) found = true;
	}
	return found;
}