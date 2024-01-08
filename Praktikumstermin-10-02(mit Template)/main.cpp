#include <iostream>
using namespace std;

#include "binaererSuchbaum.h"


int main()
{
    suchbaum::BaumKnoten *anker = nullptr;
    suchbaum::ausgeben(anker);
    //Testcase 1
    suchbaum::einfuegen(anker, 10);
    suchbaum::einfuegen(anker, 4);
    suchbaum::einfuegen(anker, 6);
    suchbaum::einfuegen(anker, 15);
    suchbaum::einfuegen(anker, 13);
    suchbaum::einfuegen(anker, 12);
    suchbaum::einfuegen(anker, 15);
    suchbaum::einfuegen(anker, 20);
    suchbaum::einfuegen(anker, 11);
    suchbaum::einfuegen(anker, 15);


    //Testcase 2
    /*suchbaum::einfuegen(anker, 3);
    suchbaum::einfuegen(anker, 3);
    suchbaum::einfuegen(anker, 3);
    suchbaum::einfuegen(anker, 2);*/

    
    //Testcase 3

    suchbaum::ausgeben(anker);

    return 0;
}
