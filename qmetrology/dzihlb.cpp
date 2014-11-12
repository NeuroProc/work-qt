#include "dzihlb.h"

Dzihlb::Dzihlb(Parser *parentParse)
{
    parse = parentParse;
}

void Dzihlb::calculate()
{
    search_result control = getCtrlStructs();
    search_result operators = getOperators();

    cout << "CONDITIONAL OPERATORS: " << control.size() << endl;
    cout << "OPERATORS: " << operators.size() << endl;
    cout << "DZIHLB: " << (float)control.size() / (float)operators.size() << endl;

    int nest = maxNesting(parse->getSource()) - 1;
    cout << "MAX NESTING: " << nest << endl;
}

search_result Dzihlb::getCtrlStructs()
{
    search_result res;

    res = parse->search(R"raw(\b(if|\?)\b)raw");

    return res;
}

search_result Dzihlb::getOperators()
{
    search_result res;

    res = parse->search(R"raw((\=|\=\=|\|\||!\=|\>\=|\<\=|\;|&&|\^\^|\+|-|\/|%|\*|!|\+\+|--|&|\||~))raw");

    return res;

}

int Dzihlb::maxNesting(string source)
{
    int max = 0;

    smatch find;
    while (parse->match(R"raw(\b(if)\s*\(((?:\n|.)*?)\)\s*(?=\;|\{|\w))raw", &source, &find))
    {
        source = find.suffix().str();
        //source.erase(0, find.position() + find.length());

        //cout << "NEW SOURCE" << endl << source << endl;
        
        string content;
        int i = 0;
        if (source[i] == '{')
        {
            i++;
            int multiline = 1;
            while (multiline > 0)
            {
                if (source[i] == '{')
                    multiline++;
                if (source[i] == '}')
                    multiline--;
                i++;
            }
            content = source.substr(1, i - 2);
        } else {
            while (source[i] != ';')
                i++;
            i++;
            content = source.substr(0, i);
        }
        //cout << "CONTENT\n" << content << endl;
        source.erase(0, i);
        //cout << "ERASE SOURCE\n" << source << endl;
        int tmp = 0;
        if ((tmp = maxNesting(content)) > max)
            max = tmp;
        //cout << tmp << endl;
        //cout << "SOURCE AFTER RECURSION\n" << source << endl;
    }
    return max + 1;

}
