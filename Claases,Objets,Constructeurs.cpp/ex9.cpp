#include <iostream>
using namespace std;
struct Element{
    int data;         
    Element*suivant; 
};
class Liste{
private:
    Element*premier; 
public:
    Liste():premier(nullptr) {}
    ~Liste() {
        while (premier!=nullptr) {
            supprimerDebut();
        }
    }
    void ajouterDebut(int n) {
        Element*nouvelElement=new Element;
        nouvelElement->data=n;
        nouvelElement->suivant=premier;
        premier=nouvelElement;
    }
    void supprimerDebut() {
        if (premier!=nullptr) {
            Element* aSupprimer=premier;
            premier=premier->suivant;
            delete aSupprimer; 
        } else {
            cout << "La liste est deja vide." << endl;
        }
    }
    void afficherListe() const {
        Element* courant=premier;
        while (courant!=nullptr) {
            cout<<courant->data << " ";
            courant=courant->suivant;
        }
        cout << endl;
    }
};
int main() {
    int m, valeur;
    Liste maListe;
    cout<<"Donnez le nombre des elements de la liste : ";
    cin>>m;
    for (int i = 1; i <= m; i++) {
        cout<<"Entrez la valeur de l'element " << i << " : ";
        cin>>valeur;
        maListe.ajouterDebut(valeur);
    }
    cout << "Contenu de la liste : ";
    maListe.afficherListe();
    cout<<"Contenu de la liste apres supression du premier element: ";
    maListe.supprimerDebut();
    maListe.afficherListe();
    return 0;
}
