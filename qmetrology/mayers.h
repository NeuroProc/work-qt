#ifndef MAYERS_H
#define MAYERS_H

#include "parser.h"

class Mayers
{
public:
    Mayers(Parser *parentParse);
    ~Mayers();

    void calculate();
private:
    search_result getCtrlStructs();
    search_result getPredicates(search_result target);

    Parser *parse;
};

#endif // MAYERS_H
