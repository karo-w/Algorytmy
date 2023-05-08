#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void naiwny(string tekst, string wzorzec, int dlt, int dlw);

int main(){
    string wzorzec, tekst;
    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, wzorzec);
    cout<<"Podaj tekst: "<<endl;
    getline(cin, tekst);
    int dlw = wzorzec.length();
    int dlt = tekst.length();

    naiwny(tekst, wzorzec, dlt, dlw);


    return 0;

}

void naiwny(string tekst, string wzorzec, int dlt, int dlw){
    int i, j;
    i=0;
    while (i<=dlt-dlw){
        j=0;
        while (j<dlw && wzorzec[j]==tekst[i+j]) j+=1;
        if (j==dlw){
            cout<<i<<"\t";        //pozycja indeksu, od której zaczyna się wzorzec w tekście
        }
        i+=1;
    }
}