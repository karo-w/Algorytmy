#include <iostream>
#include <algorithm>

using namespace std;

void flagaFrancuska(int *tab, int n, int granica1, int granica2, int &indGranicy1, int &indGranicy2);

int main(){
    int n, granica1, granica2;
    cout<<"Podaj liczbe elementow tablicy "<<endl;
    cin>>n;
    int *tab = new int[n];
    for (int i=0; i<n; i++){
        cout<<i+1<<": ";
        cin>>tab[i];
    }
    cout<<"Podaj granice1 ";
    cin>>granica1;
    cout<<"Podaj granice2 ";
    cin>>granica2;
    
    int indGranicy1, indGranicy2;
    flagaFrancuska(tab, n, granica1, granica2, indGranicy1, indGranicy2);
    cout<<"Przed granica1"<<endl;
    for(int i=0; i<indGranicy1; i++){
        cout<<tab[i]<<" ";
    }
    cout<<"\n";
    cout<<"Miedzy "<<endl;
    for(int i=indGranicy1; i<indGranicy2; i++){
        cout<<tab[i]<<" ";
    }
    cout<<"\n";
    cout<<"Po granicy2"<<endl;
    for(int i=indGranicy2; i<n; i++){
        cout<<tab[i]<<" ";
    }

    return 0;
}

void flagaFrancuska(int *tab, int n, int granica1, int granica2, int &indGranicy1, int &indGranicy2){
    int i=-1;
    int j=0;
    int k=n;
    while(j<k){
        if(tab[j] <= granica1){
            i++;
            swap(tab[i], tab[j]);
            j++;
        }
        else if (tab[j] > granica2){
            k--;
            swap(tab[k], tab[j]);
        }
        else j++;
    }
    indGranicy1 = i+1;
    indGranicy2 = k;

}
