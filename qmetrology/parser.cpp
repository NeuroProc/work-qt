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

bool Parser::match(string expression, string *ptarget, smatch *res)
{
    setRegEx(expression);

    string target;
    if (ptarget == 0)
        target = source;
    else
        target = *ptarget;

    //cout << "STR: " << target << endl;
    bool ret;
    if (res != 0)
        ret = regex_search(target, *res, exp);
    else
        ret = regex_search(target, exp);

    if (ret)
        return ret;


    return false;
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
    smatch match;
    while (!target.empty() && regex_search(target, match, exp))
    {
        vector<string> tmp;
        for (string x:match)
            tmp.push_back(x);
        res.push_back(tmp);
        target = match.suffix().str();
        //cout << "DEBUG: " << target << endl;
    }

    return res;
}

void Parser::concatResults(search_result &a, search_result b)
{
    for (u_int i = 0; i < b.size(); i++)
        a.push_back(b[i]);
}

void Parser::printResults(search_result target)
{
    for (u_int i = 0; i < target.size(); i++)
    {
        for (u_int j = 1; j < target[i].size(); j++)
            cout << "[" << target[i][j] << "] ";
        cout << endl << "---------------------------------------" << endl;
    }
}

string Parser::getSource()
{
    return source;
}

void Parser::cleanSource()
{
    replace(R"raw((\/\*(\n|.)*?\*\/)|(\/\/.*))raw", "");            //delete comments
    replace(R"raw(("((\\")|[^"])*")|('((\\')|[^'])*'))raw", "0");  //delete literals
    replace(R"raw(\b(true|false)\b)raw", "0");    //delete true/false
}
