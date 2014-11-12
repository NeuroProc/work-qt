#ifndef DZIHLB_H
#define DZIHLB_H

#include "parser.h"

class Dzihlb
{
public:
    Dzihlb(Parser *parentParse);

    void calculate();
private:
    search_result getCtrlStructs();
    search_result getOperators();
    int maxNesting(string source);

    Parser *parse;
};

#endif // DZIHLB_H
