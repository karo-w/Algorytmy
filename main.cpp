#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <stdlib.h>
#include <algorithm>

using namespace std;

struct student{
    string imie;
    string nazwisko;
    int punkty;
};

void QuickSort(struct student* tab, int lewy, int prawy, int tryb);
void wczytajStudentow(struct student*&tab, int *n);
void wyswietlStudentow(struct student *tab, int n);
void usunTabliceStudentow(struct student *tab, int n);

int main(){
    int n, lewy, prawy;
    struct student *tab;
    wczytajStudentow(tab, &n);
    wyswietlStudentow(tab, n);
    int tryb;
    cout<<"Podaj tryb: (1-rosnaco, 0-malejaco)";
    cin>>tryb;
    lewy = 0;
    prawy = n-1;
    QuickSort(tab, lewy, prawy, 0);
    //wyswietlStudentow(tab, n);
    //usunTabliceStudentow(tab, n);

    return 0;
}

void QuickSort(struct student *tab, int lewy, int prawy, int tryb){
    int srodek, i, granica;
    srodek = (lewy+prawy)/2;
    struct student piwot;
    piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    granica = lewy;
    i =lewy;
        while (i<prawy){
            if (tryb==1){
                if(tab[i].punkty<piwot.punkty){
                    swap(tab[granica], tab[i]);
                    granica = granica+1;
                }
            i++;
            }
            if (tryb==0){
                if(tab[i].punkty>piwot.punkty){
                    swap(tab[granica], tab[i]);
                   granica +=1;
                }
            i++;
            }
        }
        tab[prawy] = tab[granica];
        tab[granica] = piwot;
        if (lewy<granica-1) QuickSort(tab, lewy, granica-1, tryb);
        if (granica+1<prawy) QuickSort(tab, granica+1, prawy, tryb);
    }


void wczytajStudentow(struct student *&tab, int *n){
    string sciezka,linia;
    int liczbaStudentow;

    ifstream plik;
    char sredniki;
    sciezka="studenci.csv";
    plik.open(sciezka);
    plik >> liczbaStudentow;
    tab = new student[liczbaStudentow];
    //alokowanie pamieci w tab o dlugisci liczbaStudentow
    //elementem tablicy jest struktura
    for (int i=0; i<2; i++)
        plik >> sredniki;
    for (int i=0; i<liczbaStudentow; i++){
        plik >> linia;
        istringstream ss(linia);
        getline(ss, tab[i].imie, ';');
        getline(ss, tab[i].nazwisko, ';');
        ss>>tab[i].punkty;
    }
    plik.close();
    *n=liczbaStudentow;
}
void wyswietlStudentow(struct student *tab, int n){
    for(int i=0; i<n; i++){
        cout<<tab[i].punkty<<endl;
        cout<<tab[i].imie<<endl;
        cout<<tab[i].nazwisko<<endl;
    }
}
void usunTabliceStudentow(struct student *tab, int n){
    delete [] tab;
}
