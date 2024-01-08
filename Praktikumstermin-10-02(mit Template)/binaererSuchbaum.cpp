// Datei: binaerer_suchbaum.cpp

#include <iostream>
#include <string>
using namespace std;

#include "binaererSuchbaum.h"

const string einrueckung = "++";
void suchbaum::knoten_ausgeben(suchbaum::BaumKnoten *knoten, int tiefe)
{
    if (knoten == nullptr)
    {
        return;
    }
    // Rechter Teilbaum ausgeben
    knoten_ausgeben(knoten->rechts, tiefe + 1);
    // Aktuellen Knoten ausgeben
    for (int i = 0; i < tiefe; i++)
    {
        cout << einrueckung;
    }
    cout << knoten->wert << endl;
    // Linken Teilbaum ausgeben
    knoten_ausgeben(knoten->links, tiefe + 1);
}

void suchbaum::ausgeben(suchbaum::BaumKnoten *anker)
{
    if (anker == nullptr)
        cout << "Leerer Baum." << endl;
    else
        knoten_ausgeben(anker, 0);
}

void suchbaum::einfuegen(suchbaum::BaumKnoten *&anker, int wert)
{
    if (anker == nullptr) //Erst mal schauen ob anker ein Nullpointer ist, dann ist Baum nämlich leer
    {
        anker = new suchbaum::BaumKnoten;
        anker->wert = wert;
        anker->links = nullptr;
        anker->rechts = nullptr;
    }
    else
    {
        suchbaum::BaumKnoten *knoten = new suchbaum::BaumKnoten;
        knoten = anker;//Kopie vom Anker, damit der Original Anker nicht aus versehen verschoben wird
        while (true) //while(true) Schleifen sind nicht schön, ergeben in dem Fall aber Sinn
        {
            if (knoten->wert == wert) //Keine Duplikate im Baum
            {
                return;
            }
            if (knoten->links == nullptr && knoten->wert > wert) //Das ist der Fall 2. auf dem Übungsblatt
            {
                suchbaum::BaumKnoten *linkerKindKnoten = new suchbaum::BaumKnoten;
                linkerKindKnoten->wert = wert;
                knoten->links = linkerKindKnoten;
                return;
            }
            else if (knoten->wert > wert)//Das ist der Fall 3.
            {
                knoten = knoten->links;
                continue;
            }
            if (knoten->rechts == nullptr && knoten->wert < wert)//Das ist der Fall 4.
            {
                suchbaum::BaumKnoten *rechterKindKnoten = new suchbaum::BaumKnoten;
                rechterKindKnoten->wert = wert;
                knoten->rechts = rechterKindKnoten;
                return;
            }
            else if (knoten->wert < wert)//Das ist der Fall 5.
            {
                knoten = knoten->rechts;
                continue;
            }
        }
    }
}