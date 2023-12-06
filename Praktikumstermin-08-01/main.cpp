#include <iostream>
using namespace std;

int main()
{
    //Eingabe
    int k = 0;
    int max = 0;
    int input[5] = {0};
    for (int i = 0; i < 5; i++)
    {
        while (k < 1 || k > 9)
        {
            cout << "Bitte geben Sie die " << i + 1 << ". Zahl ein: ? ";
            cin >> k;
        }
        input[i] = k;
        if (k > max)
        {
            max = k;
        }
        k = 0;
    }

    //Ausgabe
    int height = 9;
    for (int i = 0; i < 9;i++)
    {
        cout << height;
        for (int j = 0; j < 5; j++) //Ich lauf für jede Zeile durch das gesamte Array und vergleiche dann an der jeweiligen Stelle ob es größer ist als die Nummer der Zeile
        {
            if (input[j] > height) //Wenn es größer ist dann natürlich plus ausgeben
            {
                cout << "+";
            }
            else if (input[j] == height) //Bei gleich sind wir ganz am Start einer Säule
            {
                cout << "*";
            }
            else    //Bei allen anderen Fällen einen Punkt einfügen
            {
                cout << ".";
            }
        }

        cout << endl;
        height--;
    }
    cout << " "; //Um die letzte Zeile schön zu machen
    for (int i = 1; i <= 5; i++)
    {
        cout << i;
    }
    cout<<endl;
    return 0;
}