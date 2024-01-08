#include <iostream>
using namespace std;
#include "sort.h"

void sortiere(int a[], const int N){
    for(int i = 1; i<=N-1; i++){
        int einzusortieren = a[i];
        unsigned int j = i;
        while((j>0) && (a[j-1]>einzusortieren)){
            a[j] = a[j-1];
            j = j-1;
        }
        a[j] = einzusortieren;
    }
}