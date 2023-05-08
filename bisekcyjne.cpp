#include <iostream>

using namespace std;


struct student{
    string imie;
    string nazwisko;
    int punkty;
};


void sortowanieBabelkowe(struct student *tab, int n)
{
    int i, j;
    i = n-1;
    while (i>0){
        j=0;
        while (j<i){
            if (tab[j].punkty>tab[j+1].punkty){ swap(tab[j].punkty,tab[j+1].punkty); }
            j =j+1;        
        }
        i =i-1;
    }
}

int BiR(student *tab, int lewy, int prawy, int wartosc){
    int srodek=(int)(lewy+prawy)/2;
    if (lewy>prawy){
        return -1;
    }
    else if(tab[srodek].punkty==wartosc){
        return srodek;
    }
    else if(wartosc<tab[srodek].punkty){
        return BiR(tab, lewy, srodek-1,wartosc);
    }
    else return BiR(tab, srodek+1, prawy, wartosc);
}


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
    cout<<"Jakiej wartosci szukasz?"<<endl;
    cin>>wartosc;

    int lewy=0; 
    int prawy=n-1;
    sortowanieBabelkowe(tab, n);
    
    
    int B=BiR(tab, lewy, prawy, wartosc);
    cout<<B<<endl;

    int ind1=B-1;
    while (tab[ind1].punkty==wartosc){
        cout<<ind1<<" ";
        ind1--;
    }
    int ind2=B+1;
    while (tab[ind2].punkty==wartosc){
        cout<<ind2<<" ";
        ind2++;
    }
    

    
    return 0;
}


