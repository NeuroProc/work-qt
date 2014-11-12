#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <vector>
#include <regex>

using namespace std;

typedef vector<vector<string>> search_result;

class Parser
{
public:
    Parser(string fileName);
    ~Parser();

    void setRegEx(string newExp, regex::flag_type flags = regex_constants::ECMAScript);
    bool match(string expression, string *ptarget = 0, smatch *res = 0);
    string replace(string expression, string replacement, string target = "");
    search_result search(string expression, string target = "");
    void concatResults(search_result &a, search_result b);
    void printResults(search_result target);
    string getSource();
    void cleanSource();
private:
    regex exp;
    string source;


};

#endif // PARSER_H
