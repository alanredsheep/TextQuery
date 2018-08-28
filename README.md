# TextQuery.h & QueryResult.h <br>
#### Two header files for outputing lines which specific word appears on a file. <br>
## class TextQuery<br>

* include<br>
1. **"TextQuery.h"**<br>

* define<br>
1. typedef std::vector<std::string >::size_type **line_no**<br>

* friend member<br>
1. **class QueryResult**

* data member (private)<br>
1. **share_ptr<vector<string>> file**<br> 
filename<br>
2. **map<string,shared_ptr<set<line_no>>> wm**<br> 
maps each word to the set of the lines in which that word appears<br>
  
* constructor (public)<br>
1. **extQuery(ifstream& is):file (new vector<string>)**<br>

* member function (public)<br>
1. **void display_map()**<br>
print this file's words information<br>
2. **QueryResult query(const string&)const**<br>
to make a QueryResult with this specific string<br>
---
## class QueryResult<br>

* define<br>
1. **typedef vector<string>::size_type line_no**<br>
2. **typedef set<line_no>::const_iterator line_it**<br>
  
* data member (private)<br>
1. **string sought**<br>
the word you want to search<br>
2. **shared_ptr<set<line_no>> lines**<br>
lines it's on<br>
3. **shared_ptr<vector<string>> file**<br>
input file<br>

* constructor (public)<br>
1. **QueryResult(string s,
		std::shared_ptr<set<line_no>> p,
		std::shared_ptr<vector<string>> f) :
		sought(s), lines(p), file(f) {}**<br>

* member function (public)<br>
1. **set<line_no>::size_type size() const**<br>
return lines->size()<br>
2. **line_it begin() const**<br>
return lines->cbegin()<br>
3. **line_it end() const**<br>
return lines->cend()<br>
4. **shared_ptr<vector<string>> get_file**<br>
return file<br>

* non-member function (friend)<br>
1. **ostream& print(ostream&,const QueryResult)**<br>
print the result of this search<br>

* non-member function (non-friend)<br>
1. **inline string make_plural(size_t t,const string &word,const string &ending)**<br>
return the plural form or singular form<br>
---
## main.cpp<br>
#### A test program to show the two header files's function<br>

---
**Lastest update time:** 2018-8-27 19:48:19 <br>
**Editor:** Alan Redsheep

