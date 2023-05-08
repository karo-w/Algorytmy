#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void tablicaPrzesuniec(string wzorzec, int dlw, int* p, int pocz, int kon);
void bm(string wzorzec, string tekst, int dlw, int dlt, int*p, int pocz);


int main(){
    string wzorzec, tekst;
    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, wzorzec);
    cout<<"Podaj tekst: "<<endl;
    getline(cin, tekst);
    int dlw = wzorzec.length();
    int dlt = tekst.length();

    int *tab = new int[dlt+1];
    int pocz = wzorzec[0];
    int kon = wzorzec[wzorzec.length()-1]; 
    tablicaPrzesuniec(wzorzec, dlw,tab, pocz, kon);
    bm(wzorzec, tekst, dlw, dlt, tab, pocz);


    return 0;
}

void tablicaPrzesuniec(string wzorzec, int dlw, int* p, int pocz, int kon){
    int n_pocz=(int)pocz;
    int n_kon=(int)kon;
    int i=0;
    while (i<=n_kon-n_pocz){
        p[i]=-1;
        i=i+1;
    }
    i=0;
    while (i<dlw){
        p[wzorzec[i]-n_pocz]=i;
        i++;
    }
}
void bm(string wzorzec, string tekst, int dlw, int dlt, int*p, int pocz){
    int n_pocz=(int)pocz;
    int j, i=0;
    while (i<=dlt-dlw){
        j=dlw-1;
        while (j>-1 && wzorzec[j]==tekst[i+j]) j=j-1;
        if (j==-1){
            cout<<i<<"\t";
            i+=1;
        }
        else i=i+max(1, j-p[tekst[i+j]-n_pocz]);
    }
}