#include <iostream>
#include <string>
#include <sstream>
#include <stdlib.h>
using namespace std;

void naiwny(string tekst, string wzorzec, int dlt, int dlw);
void zbudujTabliceDopasowan(string wzorzec, int dlw, int* p);
void kmp(string wzorzec, string tekst, int dlw, int dlt, int* p);
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
    int z;
    z=1;

    while (z==1 || z==2 || z==3){
        cout<<"\n"<<"Wybierz algorytm (1-naiwny, 2-KMP, 3-BM)";
        cin>>z; 
        switch(z){
            case 1:
            naiwny(tekst, wzorzec, dlt, dlw);
            break;
            case 2:
            int *p; 
            p= new int[dlw+1];
            zbudujTabliceDopasowan(wzorzec, dlw, p);
            kmp(wzorzec, tekst, dlw, dlt, p);
            delete []p;
            break;
            case 3:
            int *tab = new int[dlt+1];
            int pocz = wzorzec[0];
            int kon = wzorzec[wzorzec.length()-1]; 
            tablicaPrzesuniec(wzorzec, dlw,tab, pocz, kon);
            bm(wzorzec, tekst, dlw, dlt, tab, pocz);
            delete []tab;
            break;
        }
    }
    
   
    

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
        i+=1;
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
