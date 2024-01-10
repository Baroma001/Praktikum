#include <iostream>
using namespace std;
#define CATCH_CONFIG_RUNNER
#include "catch.h"

int main(int argc, char *const argv[])
{
    int result = Catch::Session().run(argc, argv);
    cout << "Resultatwert: " << result << endl;
    return result;
}