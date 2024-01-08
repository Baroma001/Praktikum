#include <iostream>
using namespace std;
#include "sort.h"
int main()
{
    const int N = 10;
    int a[] = {9, 3, 5, 2, 8, 6, 4, 3, 7, 8};
    // Ausgabe des "Vorher" Zustands des Arrays...
    cout << "Vorher: ";
    for (int k = 0; k < N; k++)
        cout << a[k] << (k < N - 1 ? ", " : "\n");
    // Aufruf der sortiere() Funktion...
    sortiere(a, N);
    // Ausgabe des "Nachher" Zustands des Arrays...
    cout << "Nachher: ";
    for (int k = 0; k < N; k++)
        cout << a[k] << (k < N - 1 ? ", " : "\n");
    return 0;
}