#include <iostream>
#include <string>
using namespace std;
class Personne{
private:
    string nom;
    string prenom;
    string dateNaissance;
public:
    Personne(string n,string p,string d):nom(n),prenom(p),dateNaissance(d){}
    virtual void Afficher() const {
        cout<<"Nom : "<<nom<<endl;
        cout<<"Prénom : "<<prenom<<endl;
        cout<<"Date de naissance : "<<dateNaissance<<endl;
    }
};
class Employe : public Personne {
private:
    double salaire;
public:
    Employe(string n,string p,string d,double s):Personne(n,p,d),salaire(s){}
    void Afficher()const override {
        Personne::Afficher();
        cout<<"Salaire :"<<salaire<<" MAD"<<endl;
    }
};
class Chef:public Employe {
private:
    string service;
public:
    Chef(string n,string p,string d,double s,string ser):Employe(n, p, d, s),service(ser) {}
    void Afficher() const override {
        Employe::Afficher();
        cout<<"Service : "<<service<<endl;
    }
};
class Directeur:public Chef {
private:
    string societe;
public:
    Directeur(string n, string p, string d, double s, string ser, string soc)
        : Chef(n,p,d,s,ser), societe(soc) {}
    void Afficher() const override {
        Chef::Afficher();
        cout<<"Société : "<<societe<<endl;
    }
};
int main() {
    Directeur directeur("El Bannoudi","Salma","16/05/2003",40000,"Informatique","Maroc IT Solutions");
    cout<<"Informations du directeur : " <<endl;
    directeur.Afficher();
    return 0;
}
