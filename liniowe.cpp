#include <iostream>

using namespace std;

void wyszukiwanieLinowe(int *tab, int n, int wartosc);

int main(){
    int n=10;
    int *tab = new int[n];
    for (int i=0; i<n; i++){
        cout<<i<<": ";
        cin>>tab[i];
    }

    int wartosc;
    cout<<"Jakiej wartosci szukasz?"<<endl;
    cin>>wartosc;
    wyszukiwanieLinowe(tab, n, wartosc);

    return 0;
}




void wyszukiwanieLinowe(int *tab, int n, int wartosc){
    int i=0;
    bool jest = 0;
    while (i<n){
        if (tab[i] ==wartosc){
            cout<<"Pozycja to "<<i<<endl;
            jest = 1;
        }
        i += 1;
    }
    if (jest==0){
        cout<<"Nie ma takiej wartosci"<<endl;
    }
}