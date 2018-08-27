#pragma once
#ifndef  _TEXTQUERY_
#define _TEXTQUERY_
#include<string>
#include<memory>
#include<fstream>
#include<vector>
#include<map>
#include<set>
#include<sstream>
#include "QueryResult.h"
class QueryResult;
class TextQuery
{
	friend class QueryResult;
public:
	typedef std::vector<std::string >::size_type line_no;

	TextQuery(std::ifstream&);
	QueryResult query(const std::string&)const;
	void display_map();
private:
	std::shared_ptr<std::vector<std::string>> file;
	//maps each word to the set of the lines in which that word appears
	std::map < std::string, 
					std::shared_ptr<std::set<line_no>>> wm;

	//canonicalizes text:removes punctuation and makes everything lower case
	//static std::string cleanup_str(const std::string&);
};

TextQuery::TextQuery(std::ifstream& is):file (new std::vector<std::string>)
{
	std::string text;
	while (getline(is, text)) {
		file->push_back(text);
		int n = file->size() - 1;
		std::istringstream line(text);
		std::string word;
		while (line >> word) {
			auto &lines = wm[word];
			if (!lines)
				lines.reset(new std::set<line_no>);
			lines->insert(n);
		}
	}
}
void TextQuery::display_map()
{
	auto iter = wm.cbegin(), iter_end = wm.cend();

	// for each word in the map
	for (; iter != iter_end; ++iter) {
		std::cout << "word: " << iter->first << " {";

		// fetch location vector as a const reference to avoid copying it
		auto text_locs = iter->second;
		auto loc_iter = text_locs->cbegin(),
			loc_iter_end = text_locs->cend();

		// print all line numbers for this word
		while (loc_iter != loc_iter_end)
		{
			std::cout << *loc_iter;

			if (++loc_iter != loc_iter_end)
				std::cout << ", ";

		}

		std::cout << "}\n";  // end list of output this word
	}
	std::cout << std::endl;  // finished printing entire map
}


#endif // !_TEXTQUERY_
