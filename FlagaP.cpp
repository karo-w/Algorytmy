#include <iostream>
#include <algorithm>

using namespace std;

int flagaPolska(int *tab, int n, int granica);


int main(){
    int n, granica;
    cout<<"Podaj liczbe elementow tablicy "<<endl;
    cin>>n;
    int *tab = new int[n];
    for (int i=0; i<n; i++){
        cout<<i+1<<": ";
        cin>>tab[i];
    }
    cout<<"Podaj granice ";
    cin>>granica;
    
    int algo = flagaPolska(tab, n, granica);
    cout<<"Przed granica "<<endl;
    for(int i=0; i<algo; i++){
        cout<<tab[i]<<" ";
    }
    cout<<"\n";
    cout<<"Po granicy "<<endl;
    for(int i=algo; i<n; i++){
        cout<<tab[i]<<" ";
    }
    
    return 0;

}


int flagaPolska(int *tab, int n, int granica){
    int i=0;
    int j=n-1;
    while(i<j){
        while(tab[i] <= granica && i<j){
            i++;
        }
        while(tab[j] > granica && i<j){
            j--;
        }
        if(i<j){
            swap(tab[i], tab[j]);
            i++;
            j--;
        }
    }
    if(tab[i] <= granica){
        return i+1;
    }
    return i;
}
