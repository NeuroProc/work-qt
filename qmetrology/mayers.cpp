#include "mayers.h"

Mayers::Mayers(Parser *parentParse)
{
    parse = parentParse;
}

Mayers::~Mayers()
{
}

void Mayers::calculate()
{
    search_result control = getCtrlStructs();
    parse->printResults(control);

    search_result predicates = getPredicates(control);
    parse->printResults(predicates);

    int countPredicates = 0;
    for (u_int i = 0; i < predicates.size(); i++)
    {
        for (u_int j = 1; j < predicates[i].size(); j++)
        {
            if (predicates[i][j].empty())
                continue;

            if (parse->match(R"raw([_a-zA-Z])raw", predicates[i][j]))
                countPredicates++;
        }
    }

    cout << "COUNT PREDICATES: " << countPredicates << endl;



}

search_result Mayers::getCtrlStructs()
{
    search_result res, tmp;

    tmp = parse->search(R"raw(\b(if|while)\s*\(((?:\n|.)*?)\)\s*(?=\;|\{|\w))raw");             //if/while
    parse->concatResults(res, tmp);

    tmp = parse->search(R"raw(\b(for)\s*\((?:[^;]*);([^;]*);(?:\n|.)*?\)\s*(?=\;|\{|\w))raw");   //for
    parse->concatResults(res, tmp);

    tmp = parse->search(R"raw(\b(case)([^:]*):)raw");   //case
    parse->concatResults(res, tmp);

    return res;
}

search_result Mayers::getPredicates(search_result target)
{
    search_result res, tmp;
    for (u_int i = 0; i < target.size(); i++)
    {
        if (target[i][2] == "")
        {
            cout << "WARNING: " << i << "control struct has been skipped. it's hole." << endl;
            continue;
        }

        tmp = parse->search(R"raw(^(?:((?:\n|.)*?)(?:\|\||&&|\^\^))|((?:\n|.)*)$)raw", target[i][2]);
        parse->concatResults(res, tmp);
    }

    return res;
}
