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

void Parser::setRegEx(string newExp, regex::flag_type flags)
{
    try
    {
        exp.assign(newExp, flags);
    }
    catch (...)
    {
        cout << "ERROR: not valid regex expression." << endl;
        return;
    }
}

string Parser::replace(string expression, string replacement, string target)
{
    string *tmp;

    setRegEx(expression);

    if (target.empty())
        tmp = &source;
    else
        tmp = &target;

    try
    {
        *tmp = regex_replace(*tmp, exp, replacement);
    }
    catch (...)
    {
        cout << "ERROR: replace failed." << endl;
        return 0;
    }


    return target;
}

search_result Parser::search(string expression, string target)
{
    setRegEx(expression);

    if (target.empty())
        target = source;

    search_result res;
    strreg_it rit, rend;    // start/end regex iterators
    try
    {
        for (rit = strreg_it(target.begin(), target.end(), exp); rit != rend; rit++)
            res.push_back(*rit);
    }
    catch (...)
    {
        cout << "ERROR: matching failed." << endl;
    }

    return res;
}

string Parser::getSource()
{
    return source;
}

void Parser::cleanSource()
{
    replace(R"raw((\/\*(\n|.)*?\*\/)|(\/\/.*))raw", "");            //delete comments
    replace(R"raw(("((\\")|[^"])*")|('((\\')|[^'])*'))raw", "''");  //delete literals
}
