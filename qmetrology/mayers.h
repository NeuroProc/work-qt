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

    Parser *parse;
};

#endif // MAYERS_H
