#include <iostream>
#include <string>
#include <math.h>
#include <fstream>
#include <sstream>
using namespace std;

int make_hash(int s, int off, int p, int exp);
int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp);
void karp_rabin(string pattern, string text, int lenP, int lenT, int p, int off);


int main(){
    string pattern;
    string text;
    int p=2, off=0;
    cout<<"Podaj wzorzec: "<<endl;
    getline(cin, pattern);
    cout<<"Podaj tekst: "<<endl;
    getline(cin, text);

    int lenP = pattern.length();
    int lenT=text.length();
    karp_rabin(pattern, text, lenP, lenT, p, off);

}

int make_hash(int s, int off, int p, int exp){
    int hash = ((int)s-off)*pow(p, exp);
    return hash;
}

int update_hash(int hash, char s_prev, char s_next, int off, int p, int exp){
    int u_hash=hash-((int)s_prev-off)*pow(p, exp);
    u_hash=u_hash*p;
    u_hash=u_hash+((int)s_next-off);
    return u_hash;
}

void karp_rabin(string pattern, string text, int lenP, int lenT, int p, int off){
    int hashP=0;
    int hashT=0;
    int i=0;
    while (i<lenP){
        hashP=hashP+make_hash(pattern[i], off, p, lenP-i-1);
        hashT=hashT+make_hash(text[i], off, p, lenP-i-1);
        i++;
    }
    i=lenP;
    int j=0;
    while (i<=lenT){
        if (hashP==hashT){
            int licz=0;
            for (int k=0; k<lenP; k++){
                if (pattern[k]==text[j+k]) licz++;
            }
            if (licz == lenP) {
                cout << j << " ";
            }
        }
        if (i<lenT){
            hashT=update_hash(hashT, text[j], text[i], off, p, lenP-1);
        }
        i++;
        j++;
    }
}