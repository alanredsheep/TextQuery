#pragma once
#ifndef _QUERYRESULT_
#define _QUERYRESULT_
#include<memory>
#include<string>
#include<vector>
#include<set>
#include<iostream>
#include"TextQuery.h"

inline
std::string make_plural(size_t t, const std::string &word, const std::string &ending)
{
	return (t == 1) ? word : word + ending;
}

class QueryResult {
	friend std::ostream& print(std::ostream&, const QueryResult&);
public:
	typedef std::vector<std::string>::size_type line_no;
	typedef std::set<line_no>::const_iterator line_it;
	QueryResult(std::string s,
		std::shared_ptr<std::set<line_no>> p,
		std::shared_ptr<std::vector<std::string>> f) :
		sought(s), lines(p), file(f) {}
	std::set<line_no>::size_type size() const { return lines->size(); }

	line_it begin() const { return lines->cbegin(); }
	line_it end() const { return lines->cend(); }

	std::shared_ptr<std::vector<std::string>> get_file() { return file; }


private:
	std::string sought;  //word this query reperesent
	std::shared_ptr<std::set<line_no>> lines; //lines it's on
	std::shared_ptr<std::vector<std::string>>  file; //input file
};


std::ostream &print(std::ostream& os, const QueryResult& qr)
{
	os << qr.sought << " occurs " << qr.lines->size() << " "
		<<make_plural(qr.lines->size(), "times","s") << std::endl;
	for (auto num:*qr.lines)
	{
		os << "\t( Line " <<  num+1 << ")" << "\t";
		os << *(qr.file->begin()+ num) << std::endl;
	}
	return os;
}



#endif // !_QUERYRESULT_
