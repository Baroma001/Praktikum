#include <iostream>
using namespace std;
struct TListenKnoten
{
    int data;
    TListenKnoten *next;
    TListenKnoten *prev;
};

void liste_ausgeben_rueckwaerts(TListenKnoten *anker)
{
    TListenKnoten *ptr = anker;
    if (ptr == nullptr)
    {
        cout << "Leere Liste." << endl;
        return;
    }
    else
    {
        while (ptr->next != nullptr) //Erst bis zum Ende durchlaufen
        {
            ptr = ptr->next;
        }
        cout << "[ "; 
        while (ptr != nullptr) //Druchlaufen bis wir wieder am Anfang sind
        {   
            if (ptr->prev == nullptr)
            {
                cout << ptr->data; //Wenn wir den letzten Eintrag haben wollen wir ja kein Komma mehr dahinter ausgeben
            }
            else
            {
                cout << ptr->data << " , ";
            }
            ptr = ptr->prev;
        }
        cout << " ]" << endl;
    }
}

void hinten_anfuegen(TListenKnoten *&anker, const int wert)
{
    TListenKnoten *neuer_eintrag = new TListenKnoten;
    neuer_eintrag->data = wert;
    neuer_eintrag->next = nullptr;
    if (anker == nullptr) //Wenn wir eine leere Liste haben wird der Anker das neue Element
    {
        anker = neuer_eintrag;
        anker->prev = nullptr;
    }
    else
    {
        TListenKnoten *ptr = anker;
        while (ptr->next != nullptr) //Durchlaufen bis zum Ende der Liste
        {
            ptr = ptr->next;
        }
        ptr->next = neuer_eintrag; //Neuen Eintrag hinzufügen
        neuer_eintrag->prev = ptr; //Nicht vergessen den prev Pointer zu aktualisieren
    }
}
string liste_als_string(TListenKnoten *anker)
{
    string resultat = "";
    if (anker == nullptr)
        return "Leere Liste."; // Zeile geändert !!!!!!!!!!!!!!
    else
    {
        resultat += "[ ";
        TListenKnoten *ptr = anker;
        do
        {
            resultat += std::to_string(ptr->data);
            if (ptr->next != nullptr)
                resultat += " , ";
            else
                resultat += " ";
            ptr = ptr->next;
        } while (ptr != nullptr);
        resultat += "]";
    }
    return resultat;
}
void liste_ausgeben(TListenKnoten *anker)
{
    cout << liste_als_string(anker) << endl;
}

void in_liste_einfuegen(TListenKnoten *&anker, int wert_neu, int vor_wert)
{
    if (anker == nullptr) //Wieder Szenario mit leerer Liste
    {
        TListenKnoten *neuerEintrag = new TListenKnoten;
        neuerEintrag->data = wert_neu;
        neuerEintrag->next = nullptr;
        neuerEintrag->prev = nullptr;
        anker = neuerEintrag;
        return;
    }
    TListenKnoten *ptr = anker;
    while (ptr->prev != nullptr) //Ganz an den Anfang der Liste laufen
    {
        ptr = ptr->prev;
    }
    bool found = true; //Boolean um zu schauen ob der Wert gefunden wurde oder die Liste ans Ende kam
    while ((ptr->data != vor_wert))
    {
        if (ptr->next == nullptr) //Fall das wir am Ende der Liste sind
        {
            found = false;
            break;
        }
        ptr = ptr->next;
    } // Suchen bis entweder Ende der Liste da ist oder Wert gefunden wurde

    if (found)
    {
        TListenKnoten *neuerEintrag = new TListenKnoten;
        neuerEintrag->data = wert_neu;
        neuerEintrag->prev = ptr->prev; //Dadurch dass hier der neueEintrag prev auf den ptr prev... 
        neuerEintrag->next = ptr;//...und der neuerEintrag next auf ptr zeigt, haben wir neuerEintrag "reingequetscht"

//Vorstellung: Erst den prev Pointer von dem Eintrag nach neueEintrag auf neueEintrag zeigen lassen
//Dann den neuerEintrag next auf den Eintrag nach neueEintrag
//Dann den neuerEintrag prev auf den Eintrag vor neueEintrag
//Und dann jenachdem ob der Eintrag vor neueEintrag null ist oder nicht, entweder den Eintrag von neueEintrag auf neueEintrag zeigen lassen
//Oder neueEintrag als anker speichern

        if (ptr->prev != nullptr)
        {
            ptr->prev->next = neuerEintrag; // Verweis auf den neuen Eintrag damit er in der Liste auch gefunden wird
        }
        else
        {
            anker = neuerEintrag; // Anker muss aktualisiert werden wenn es ganz am Anfang eingefügt wird, da wir dann einen neuen Einstiegspunkt haben
        }

        ptr->prev = neuerEintrag;
    }
    else if (ptr->next == nullptr)//wenn wir durch die Liste durch sind und der Vor-Wert nicht vorkommt dann hinten anfügen
    {
        hinten_anfuegen(anker, wert_neu);
    }
}

void liste_loeschen(TListenKnoten *&anker)
{
    if (anker == nullptr)
    {
        return;
    }
//Grundidee hier: Wir nehmen zunächst das Element nach dem Anker, und gehen dann eins weiter und löschen das Element davor

    TListenKnoten *helper = anker->next;
    anker = nullptr;
    while (helper->next != nullptr)
    {
        helper = helper->next;
        delete (helper->prev);
    }
}

int main()
{
    const int laenge = 10;
    TListenKnoten *anker = nullptr;
    liste_ausgeben(anker);
    liste_loeschen(anker);
    for (int i = 0; i < laenge; i++)
        in_liste_einfuegen(anker, i * i, 9999);
    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);
    in_liste_einfuegen(anker, 99, 0);
    in_liste_einfuegen(anker, 99, 25);
    in_liste_einfuegen(anker, 99, 81);
    in_liste_einfuegen(anker, 99, 9999); // Achtung: geändert 99 => 9999
    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);
    liste_loeschen(anker);
    liste_ausgeben(anker);
    liste_ausgeben_rueckwaerts(anker);
    system("PAUSE");
    return 0;
}