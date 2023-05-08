#include <iostream>

using namespace std;

void QuickSort(int *tab, int lewy, int prawy, int tryb);

int main(){
    int n=10;
    int *tab = new int[10];
    for (int i=0; i<n; i++){
        cout<<i<<": ";
        cin>>tab[i];
    }
    int lewy=0;
    int prawy = n-1;
    int tryb;
    cout << "tryb (rosnaco/malejaco)" << endl;
    cin >> tryb;
    QuickSort(tab, lewy, prawy, tryb);
    cout<<"Posortowane"<<endl;;
    for (int i=0; i<n; i++){
        cout<<tab[i]<<" ";
    }

    return 0;
}
void QuickSort(int *tab, int lewy, int prawy, int tryb){
    int srodek, i, granica;
    srodek = (lewy+prawy)/2;
    int piwot;
    piwot = tab[srodek];
    tab[srodek] = tab[prawy];
    granica = lewy;
    
    for (int i = lewy; i < prawy; i++){
        if (tryb == 1){
            if (tab[i] < piwot){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
        else{
            if (tab[i] > piwot){
                swap(tab[granica], tab[i]);
                granica ++ ;
            }
        }
    }
    tab[prawy] = tab[granica];
    tab[granica] = piwot;

    if (lewy  < granica-1) QuickSort(tab, lewy, granica-1, tryb);
    if (prawy > granica+1) QuickSort(tab, granica+1, prawy, tryb);

    }