#include "parser.h"

int main()
{
    Parser parse("input.java");

    cout << parse.getSource();
    parse.cleanSource();
    cout << parse.getSource();



    return 0;
}

