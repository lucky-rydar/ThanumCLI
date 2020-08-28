#include <iostream>
#include "Parser.h"

using namespace std;

int main()
{
    Parser parser;
    auto res = parser.parse("Hello world I am Misha");

    for (int i = 0; i < res.size(); i++)
    {
        cout << res[i] << endl;
    }

    return 0;
}