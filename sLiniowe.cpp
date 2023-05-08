#include <iostream>
#include <string>
using namespace std;

void wyszukiwanieLinowe(struct student *tab, int n, int wartosc);

struct student
{
    string imie;
    string nazwisko;
    int punkty;
};


int main(){
    int n=3;
    student *tab = new student [n];
    for(int i=0; i<n; i++){
        cout<<"Imie: ";
        cin>>tab[i].imie;
        cout<<"Nazwisko: ";
        cin>>tab[i].nazwisko;
        cout<<"Punkty: ";
        cin>>tab[i].punkty;
    }
    for(int i=0; i<n; i++){
        cout<<tab[i].imie<<" "<<tab[i].nazwisko<<" "<<tab[i].punkty<<endl;
    }

    int wartosc;
    cout<<"czego szukasz? ";
    cin>>wartosc;
    wyszukiwanieLinowe(tab, n, wartosc);

    return 0;
}

void wyszukiwanieLinowe(struct student *tab, int n, int wartosc){
    int i=0;
    bool jest = 0;
    while (i<n){
        if (tab[i].punkty ==wartosc){
            cout<<"Pozycja to "<<i<<endl;
            jest = 1;
        }
        i += 1;
    }
    if (jest==0){
        cout<<"Nie ma takiej wartosci"<<endl;
    }
}