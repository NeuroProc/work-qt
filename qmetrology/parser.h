#ifndef PARSER_H
#define PARSER_H

#include <iostream>
#include <string>
#include <regex>

using namespace std;

typedef match_results<const char *> cmatch;

class Parser
{
public:
    Parser(string fileName);
    ~Parser();

    void setRegEx(string newExp);
    void replace(string expression, string replacement, string *str = 0);
    string getSource();
    void cleanSource();

private:
    regex exp;
    string source;


};

#endif // PARSER_H
