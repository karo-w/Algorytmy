#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void zbudujTabliceDopasowan(string wzorzec, int dlw, int* p);
void kmp(string wzorzec, string tekst, int dlw, int dlt, int* p);

int main(){
    string wzorzec, tekst;
    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, wzorzec);
    cout<<"Podaj tekst: "<<endl;
    getline(cin, tekst);
    int dlw = wzorzec.length();
    int dlt = tekst.length();

    int *p; 
    p= new int[dlw+1];
    zbudujTabliceDopasowan(wzorzec, dlw, p);
    kmp(wzorzec, tekst, dlw, dlt, p);


    return 0;
}

void zbudujTabliceDopasowan(string wzorzec, int dlw, int *p){
    p[0]=0;
    p[1]=0;
    int t=0;
    int i=1;
    while (i<dlw){
        while (t>0 && wzorzec[t]!=wzorzec[i]) t=p[t];
        if (wzorzec[t]==wzorzec[i]){
            t=t+1;
        }
        p[i+1]=t;
        i+=1;
    }
}

void kmp(string wzorzec, string tekst, int dlw, int dlt, int* p){
    int i=0, j=0;
    while (i<dlt-dlw+1){
        while (wzorzec[j]==tekst[i+j] && j<dlw) j+=1;
        if (j==dlw) cout<<i<<"\t"; 
        i=i+max(1, j-p[j]);
        j=p[j];
    }
}