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
    search_result result = getCtrlStructs();

    for (u_int i = 0; i < result.size(); i++)
    {
        for (u_int j = 1; j < result[i].size(); j++)
            cout << "[" << result[i][j] << "] ";
        cout << endl << "---------------------------------------" << endl;
    }

}

search_result Mayers::getCtrlStructs()
{
    return parse->search(R"raw(\b(if|while|for)\s*(\((?:\n|.)*?\))\s*(?=\;|\{|\w))raw");
}
