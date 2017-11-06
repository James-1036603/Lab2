// -------------------------------------------
//					Paragraph
// -------------------------------------------

#include "Paragraph.h"

void Paragraph::addLine(const Line& line)
{
	_paragraph.push_back(line);
}

bool Paragraph::contains(const Word& search_word, vector<int>& line_numbers) const
{
	bool found = false;
	for(auto i = 0u; i != _paragraph.size(); i++)
	{
		if(_paragraph[i].contains(search_word))
		{
			found = true;
			line_numbers.push_back(i+1);
		}
	}
	return found;
}