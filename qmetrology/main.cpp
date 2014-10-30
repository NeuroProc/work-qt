#include "parser.h"
#include "mayers.h"

int main()
{
    Parser parse("input.java");
    Mayers mayersMetric(&parse);

    cout << parse.getSource();
    parse.cleanSource();
    //cout << parse.getSource();

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! START !!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    mayersMetric.calculate();

    //cout << parse.getSource();

    return 0;
}

