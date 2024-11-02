#include <iostream>
using namespace std;
class Fichier{
private:
    char* P;      
    size_t longueur; 
public:
    Fichier():P(nullptr),longueur(0) {}
    ~Fichier(){
        delete[] P;
    }
    void Creation(size_t taille) {
        longueur=taille; 
        P = new char[longueur]; 
    }
    void Remplit() {
        if (P != nullptr) {
            for (size_t i=0;i<longueur; ++i) {
                P[i] = 'A'; 
            }
        }
    }
    void Affiche() const {
        if (P!=nullptr) {
            cout<<"Contenu du fichier : ";
            for (size_t i=0;i<longueur;++i) {
                cout<<P[i]; 
            }
            cout<<endl;
        }
    }
};
int main() {
    Fichier* monFichier=new Fichier();
    monFichier->Creation(17); 
    monFichier->Remplit();     
    monFichier->Affiche();     
    delete monFichier; 
    return 0;
}

