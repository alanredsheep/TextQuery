# TextQuery.h & QueryResult.h <br>
#### Two header files for outputing lines which specific word appears on a file. <br>
## class TextQuery<br>

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
1. **TextQuery::TextQuery(std::ifstream& is):file (new std::vector<std::string>)**<br>

* member function (public)<br>
1. **void display_map()**<br>
print this file's words information<br>
2. **QueryResult query(const std::string&)const**<br>
to make a QueryResult with this specific string<br>
---
## class QueryResult<br>

* define<br>
typedef vector<string>::size_type line_no;
typedef set<line_no>::const_iterator line_it;
  
  
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
<br>
