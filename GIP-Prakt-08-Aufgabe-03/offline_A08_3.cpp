#include <iostream>
using namespace std;
char* my_strconcat(const char *, const char*);

int main() {
    char firstText[21];
    char secondText[21];
    cout<<"Bitte ersten Text eingeben (ggfs. mit Leerzeichen): ? ";
    cin.getline(firstText, 21);
    cout<<"Bitte zweiten Text eingeben (ggfs. mit Leerzeichen): ? ";
    cin.getline(secondText, 21);
    char* result =  my_strconcat(firstText, secondText);
    cout<<"Ergebnis my_strconcat(): "<<result<<endl;
    return 0;
}

char* my_strconcat(const char* ptr1, const char* ptr2){
    char* value = new char [41];
    int length_first_string = 0;
    for(int i = 0; i<20; i++){
        if(ptr1[i] == '\0'){
            break;
        }
        else{
            value[i] = ptr1[i];
        }
        length_first_string = i;
    }
    for(int i = 0; i<20; i++){//Frag nicht was hier passier...
        if(length_first_string==0 && ptr2[0]=='\0'){
            value[0] = '\0';
        }
        if(ptr2[i] == '\0' && length_first_string!=0){
            value[length_first_string+i+1] = '\0'; 
            break;
        }else if(ptr2[i]=='\0' && length_first_string == 0){
            value[length_first_string+i] = '\0';
        }
        else if(length_first_string!=0){
            value[length_first_string+i+1] = ptr2[i]; 
        }
        else{
            value[i] = ptr2[i];
        }
    }
    return value;
}