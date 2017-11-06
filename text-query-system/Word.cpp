// -------------------------------------------
//					Word
// -------------------------------------------

#include "Word.h"

Word::Word(const string& word): _word{word}
{
	transform(_word.begin(),_word.end(),_word.begin(),::tolower);
		string result;
        std::remove_copy_if(_word.begin(), _word.end(),
        std:: back_inserter(result), //Store output           
        std:: ptr_fun<int, int>(&std::ispunct)
        );
	_word=result;
	// throws an exception (in the form of WordContainsNoLetters object)
	// indicating that the word being constructed contains no letters
	if (_word.empty()) throw WordContainsNoLetters();
	if (Word::wordContainsSpaces()) throw WordContainsSpace();
	// Note, we will cover exceptions in more detail later on in the course.
	
	
}

// overloads the equivalence operator which allows to Words to be compared using ==
bool Word::operator==(const Word& rhs) const
{
	if (_word == rhs._word)
		return true;
	else
		return false;
}

bool Word::isQueryable() const
{
	if(_word.size() >= MIN_QUERY_LENGTH) return true;
	else return false;
}

bool Word::wordContainsSpaces()
{
	bool containsSpace = false;
	for(auto i = 0u; i != _word.size(); i++)
	{
		if(_word.at(i) == ' ') containsSpace = true;
	}
	return containsSpace;
}
