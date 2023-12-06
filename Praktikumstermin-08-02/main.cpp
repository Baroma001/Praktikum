#include <iostream>
using namespace std;

const int größeSudoku = 9; // Größe des Sudokus, aber leider nicht leicht skalierbar
void checkZeilen(bool (&)[größeSudoku], int, int sudoku[größeSudoku][größeSudoku]);
void checkSpalten(bool (&)[größeSudoku], int, int sudoku[größeSudoku][größeSudoku]);
void checkBloecke(bool (&contains)[größeSudoku], int sudoku[][größeSudoku], int, int, int, int, int);

void eingabe(int (&sudoku)[größeSudoku][größeSudoku])
{
    string eingabe[größeSudoku + 2] = {""}; // Die vorgegebene Eingabe, ein String Arrray der Länge 11, das die Zeilen darstellt
    cout << "Bitte geben Sie das Sudoku ein: " << endl;
    for (int k = 0; k < sizeof(eingabe) / sizeof(string); k++)
    { // Eine Schleife die 11 Mal iteriert um das Array zu befüllen mit User Eingaben
        getline(cin, eingabe[k]);
    }

    // Das ganze nachfolgende Konstrukt ist dafür da um was in dem Eingabe String Array steht in das Sudoku Array zu übertragen
    // Dabei wird eine verschachtelte for Schleife verwendet um dadurch über jede Zeile und dann über jeden Character in dem in der Zeile zu findenden String zu iterieren
    // Die zwei Index Variablen sind nötig, da bei dem Sudoku Array andere Indexe nötig sind als beim String Array

    int row = 0, collumn = 0; // Indexe des 2 dimensionalen Arrays Sudoku in dem die Integer Werte abgespeichert werden
    for (int i = 0; i < sizeof(eingabe) / sizeof(string); i++)
    { // erste for Schleife iteriert über alle Zeilen
        for (int j = 0; j < eingabe[i].length(); j++)
        { // zweite for Schleife iteriert über alle Charaktere in der Zeile
            if (eingabe[i].at(j) >= '1' && eingabe[i].at(j) <= '9')
            {                                                  // Hier wird geschaut ob der Wert im String Array eine Zahl zwischen 1 und 9 ist
                sudoku[row][collumn] = eingabe[i].at(j) - '0'; // Falls das der Fall ist wird der Wert in das Sudoku Array eingetragen
                collumn++;
                if (collumn > größeSudoku - 1)
                {
                    row++;
                    collumn = 0;
                }
                // Das hier drüber ist nur um über das Sudoku Array zu iterieren
            }
        }
    }
    cout << endl;
}

void ausgabe(const int (&sudoku)[größeSudoku][größeSudoku])
{
    cout << "Das Sudoku lautet:" << endl;
    // Wieder vernestete For Schleife um über alle Elemnte der For Schleife zu iterieren
    for (int i = 0; i < größeSudoku; i++)
    {
        if (i % 3 == 0 && i > 0)
        { // Wenn drei Zeilen abgearbeitet wurden soll so ein Trennungsding reinkommen
            cout << "=======//=======//=======" << endl;
        }
        for (int j = 0; j < größeSudoku; j++)
        {
            // Nach jeder dritten Zahl soll ein ";//;" eingefügt werden. Zwischen den einzelen Zahlen nur ein ";"
            if (j % 3 == 0 && j > 0)
            {
                cout << ";//;";
            }
            else
            {
                cout << ";";
            }
            cout << sudoku[i][j];
        }
        cout << endl;
    }
}

void checkSudoku(int sudoku[größeSudoku][größeSudoku])
{                                         // Drei Funktionen um das Sudoku zu überprüfen
    bool contains[größeSudoku] = {false}; // In diesem Bool Array wird gespeichert ob ein Wert bereits einmal vorgekommen ist
    checkSpalten(contains, größeSudoku, sudoku);
    checkZeilen(contains, größeSudoku, sudoku);
    for (int block = 0; block < 9; block++)
    {
        checkBloecke(contains, sudoku, block % 3 * 3, block % 3 * 3 + 2, block / 3 * 3, block / 3 * 3 + 2, block);
        // Die Argumente bedeuten folgendes: bool Array, das Sudoku, AnfangSpalte, EndeSpalte, AnfangZeile, EndeZeile, In welchem Block wir uns befinden
    }
}


void checkSpalten(bool (&contains)[größeSudoku], int maxSpalten, int sudoku[größeSudoku][größeSudoku])
{ // Funktion um die Spalten einzeln zu überprüfen
    // Die Grundidee ist in allen drei Funktionen die gleiche. Wir gehen alle Spalte/Zeilen/einzelne Blöcke durch und speichern wenn wir eine Zahl finden in einem Bool Array
    // Sollten wir während wir das tun auf einen Eintrag stoßen der true ist wissen wir dass wir diese Zahl schon mal davor gefundenhaben, also dass sie mehrfach vorkommt
    // Andersrum, wenn wir alles durchgelaufen sind und eine Stelle im Bool Array False ist, wissen wir dass diese Zahl nicht vorkommt
    for (int i = 0; i < maxSpalten; i++)
    {
        for (int j = 0; j < maxSpalten; j++)
        {
            if (contains[sudoku[j][i] - 1] == true)
            {
                cout << "Spalte " << i << ":";

                cout << "Die Zahl " << sudoku[j][i] << " kommt mehrfach vor." << endl;
            }
            else
            {
                contains[sudoku[j][i] - 1] = true;
            }
        }
        for (int k = 0; k < maxSpalten; k++)
        {
            if (contains[k] == false)
            {
                cout << "Spalte " << i << ":";
                cout << "Die Zahl " << k + 1 << " kommt nicht vor." << endl;
            }
            else
            {
                contains[k] = false;
            }
        }
    }
}


void checkZeilen(bool (&contains)[größeSudoku], int maxZeilen, int sudoku[größeSudoku][größeSudoku])
{
    // Gleucge Grundidee wie oben drüber
    for (int i = 0; i < maxZeilen; i++)
    {
        for (int j = 0; j < maxZeilen; j++)
        {
            if (contains[sudoku[i][j] - 1] == true)
            {
                cout << "Zeile " << i << ":";

                cout << "Die Zahl " << sudoku[i][j] << " kommt mehrfach vor." << endl;
            }
            else
            {
                contains[sudoku[i][j] - 1] = true;
            }
        }
        for (int k = 0; k < maxZeilen; k++)
        {
            if (contains[k] == false)
            {
                cout << "Zeile " << i << ":";
                cout << "Die Zahl " << k + 1 << " kommt nicht vor." << endl;
            }
            else
            {
                contains[k] = false;
            }
        }
    }
}

void checkBloecke(bool (&contains)[größeSudoku], int sudoku[][größeSudoku], int beginnSpalte, int endeSpalte, int beginnZeile, int endeZeile, int block)
{
    // Hier ist die Besonderheit dass wir unterschiedliche Anfänge und Ende haben für Zeilen und Spalten
    // Dabei fangen wir an in den Spalten alle Zeilen durch zu gehen
    int i = beginnZeile;
    for (beginnSpalte; beginnSpalte <= endeSpalte; beginnSpalte++)
    {
        for (i = beginnZeile; i <= endeZeile; i++)
        {
            // cout<<sudoku[i][anfangZeile]<<endl;
            if (contains[sudoku[i][beginnSpalte] - 1] == true)
            {
                cout << "Block " << block << ":";
                cout << "Die Zahl " << sudoku[i][beginnSpalte] << " kommt mehrfach vor." << endl;
            }
            else
            {
                contains[sudoku[i][beginnSpalte] - 1] = true;
            }
        }
        i = beginnZeile;
    }
    // cout<<"Ende der For Schleife"<<endl;
    for (int k = 0; k < 9; k++)
    {
        if (contains[k] == false)
        {
            cout << "Block " << block << ":";
            cout << "Die Zahl " << k + 1 << " kommt nicht vor." << endl;
        }
        else
        {
            contains[k] = false;
        }
    }
}



int main()
{
    int sudoku[größeSudoku][größeSudoku] = {0};
    eingabe(sudoku);
    ausgabe(sudoku);
    checkSudoku(sudoku);
    return 0;
}
