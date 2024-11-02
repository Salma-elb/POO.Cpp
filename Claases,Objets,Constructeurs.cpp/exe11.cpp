#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
class Traitement{
private:
    vector<int>vecteur; 
public:
    void Initialise() {
        int nombre;
        cout<<"Veuillez saisir 15 entiers pairs (non nuls) :"<<endl;
        while (vecteur.size()<15) {
            cout<<"Entier "<<vecteur.size() + 1<<": ";
            cin>>nombre;
            if (cin.fail()||nombre==0||nombre%2!=0){
                cin.clear();  
                cout<<"Veuillez entrer un entier pair non nul."<<endl;}
            else {
                vecteur.push_back(nombre); 
            }
        }
    }
    void show() const {
        for (int i = 0; i<vecteur.size();++i) {
            cout<<vecteur[i] << " "; 
        }
        cout<<endl;
    }
    friend double moyenne(const Traitement& t);
    friend double median(const Traitement& t);
};
double moyenne(const Traitement& t) {
    double somme = 0;
    for (int val:t.vecteur){
        somme +=val; 
    }
    return somme / t.vecteur.size(); 
}
double median(const Traitement& t) {
    vector<int>copie =t.vecteur;
    sort(copie.begin(), copie.end()); 
    if (copie.size() % 2 == 0) {
        return (copie[copie.size()/2-1]+copie[copie.size()/2])/2.0;
    } else {
        return copie[copie.size()/2];
    }
}
int main(){
    Traitement t; 
    t.Initialise(); 
    cout<<"Les elements du vecteur sont : ";
    t.show(); 
    cout<<"Moyenne : "<<moyenne(t)<<endl;
    cout<<"Mediane : "<<median(t)<<endl; 
    return 0;
}
