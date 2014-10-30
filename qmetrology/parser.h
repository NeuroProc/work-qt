#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

typedef regex_iterator<string::const_iterator> strreg_it;
typedef vector<smatch> search_result;

class Parser
{
public:
    Parser(string fileName);
    ~Parser();

    void setRegEx(string newExp, regex::flag_type flags = regex_constants::ECMAScript);
    string replace(string expression, string replacement, string target = "");
    search_result search(string expression, string target = "");
    string getSource();
    void cleanSource();

private:
    regex exp;
    string source;


};

#endif // PARSER_H
