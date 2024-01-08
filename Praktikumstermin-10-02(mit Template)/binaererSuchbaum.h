// Datei: binaerer_suchbaum.h

#pragma once

namespace suchbaum
{
    struct BaumKnoten
    {
        int wert;
        BaumKnoten *links, *rechts;
    };

    void ausgeben(BaumKnoten*  anker);
    void einfuegen(BaumKnoten* &anker, int wert);
    void knoten_ausgeben(BaumKnoten* knoten, int tiefe);
}