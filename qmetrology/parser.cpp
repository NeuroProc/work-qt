#include "parser.h"
#include <fstream>

Parser::Parser(string fileName)
{
    ifstream sourceFile(fileName);

    source.assign(std::istreambuf_iterator<char>(sourceFile),
                  std::istreambuf_iterator<char>()
                 ); //get source
}

Parser::~Parser()
{
}

void Parser::setRegEx(string newExp)
{
    try
    {
        exp = newExp;
    }
    catch (...)
    {
        cout << "ERROR: not valid regex expression." << endl;
        return;
    }
}

void Parser::replace(string expression, string replacement, string *str)
{
    setRegEx(expression);

    if (str == 0)
        str = &source;

    string tmp;
    try
    {
        tmp = regex_replace(*str, exp, replacement);
    }
    catch (...)
    {
        cout << "ERROR: replace failed." << endl;
        return;
    }
    *str = tmp;
}

string Parser::getSource()
{
    return source;
}

void Parser::cleanSource()
{
    replace(R"raw((\/\*(\n|.)*?\*\/)|(\/\/.*))raw", "");              //delete comments
    replace(R"raw(("((\\")|[^"])*")|('((\\')|[^'])*'))raw", "\"\"");  //delete literals
}
