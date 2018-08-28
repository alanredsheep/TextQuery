#include <iostream>  
#include <string>  
#include <memory>  
#include <new>
#include<fstream>
#include"QueryResult.h"
#include"TextQuery.h"
using namespace std;

QueryResult TextQuery::query(const std::string &sought) const
{
	static std::shared_ptr<std::set<line_no>> nodata(new std::set<line_no>);
	auto loc = wm.find(sought);
	if (loc == wm.end())
		return QueryResult(sought, nodata, file);
	else
		return QueryResult(sought, loc->second, file);
}

int main()
{
	ifstream ifs("text1.txt");
	TextQuery text1(ifs);
	QueryResult w_hello = text1.query("good");
	text1.display_map();
	print(cout, w_hello);
	ifs.close();
	system("pause");
	return 0;
}
