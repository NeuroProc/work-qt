#include "parser.h"
#include "mayers.h"
#include "dzihlb.h"

int main()
{
    Parser parse("input.java");
    Mayers mayersMetric(&parse);
    Dzihlb dzihlbMetric(&parse);

    cout << parse.getSource();
    parse.cleanSource();
    //cout << parse.getSource();

    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! MAYERS !!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    mayersMetric.calculate();
    cout << "!!!!!!!!!!!!!!!!!!!!!!!!!!! DZIHLB !!!!!!!!!!!!!!!!!!!!!!!!!!!" << endl;
    dzihlbMetric.calculate();

    //cout << parse.getSource();

    return 0;
}

