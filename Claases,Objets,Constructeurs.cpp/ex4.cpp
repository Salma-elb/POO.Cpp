#include <iostream>
#include <cmath> 
using namespace std;
class Vecteur3D {
private:
    float x,y,z;
public:
    Vecteur3D(float x_val = 0,float y_val = 0,float z_val=0):x(x_val),y(y_val),z(z_val) {}
    void Afficher() const {
        cout<< "(" <<x<< "," <<y<< "," <<z<< ")"<<endl;
    }
    Vecteur3D Somme(const Vecteur3D&v)const {
        return Vecteur3D(x + v.x, y + v.y, z + v.z);
    }
    float ProduitScalaire(const Vecteur3D& v) const {
        return (x * v.x)+(y * v.y)+(z * v.z);
    }
    bool Coincide(const Vecteur3D& v) const {
        return (x==v.x&&y==v.y&&z==v.z);
    }
    float Norme() const {
        return sqrt(x * x + y * y + z * z);
    }
    static Vecteur3D*Norme(const Vecteur3D&v1,const Vecteur3D&v2) {
        return (v1.Norme()>=v2.Norme()) ? new Vecteur3D(v1):new Vecteur3D(v2);
    }
    static Vecteur3D* NormeAddress(Vecteur3D*v1,Vecteur3D*v2) {
        return (v1->Norme()>=v2->Norme()) ? v1 : v2;
    }
    static const Vecteur3D& NormeReference(const Vecteur3D&v1,const Vecteur3D&v2) {
        return (v1.Norme() >= v2.Norme()) ? v1 : v2;
    }
};
int main() {
    float x1, y1, z1;
    float x2, y2, z2;
    cout << "Entrez les composantes du Vecteur 1 (x, y, z) : ";
    cin >> x1 >> y1 >> z1;
    cout << "Entrez les composantes du Vecteur 2 (x, y, z) : ";
    cin >> x2 >> y2 >> z2;
    Vecteur3D v1(x1, y1, z1);
    Vecteur3D v2(x2, y2, z2);
    cout << "Vecteur 1: ";
    v1.Afficher();
    cout << "Vecteur 2: ";
    v2.Afficher();
    Vecteur3D somme = v1.Somme(v2);
    cout<<"Somme: ";
    somme.Afficher();
    float produitScalaire = v1.ProduitScalaire(v2);
    cout<<"Produit scalaire: "<<produitScalaire<<endl;
    cout<<"Coincide: " << (v1.Coincide(v2) ? "Oui" : "Non")<<endl;
    cout<<"Norme de Vecteur 1: " <<v1.Norme()<<endl;
    cout<<"Norme de Vecteur 2: " <<v2.Norme()<<endl;
    Vecteur3D* vecteurNorme = Vecteur3D::Norme(v1,v2);
    cout << "Vecteur avec la plus grande norme: ";
    vecteurNorme->Afficher();
    delete vecteurNorme;
    Vecteur3D* vecteurNormeAddress = Vecteur3D::NormeAddress(&v1,&v2);
    cout<<"Vecteur avec la plus grande norme (par adresse): ";
    vecteurNormeAddress->Afficher();
    const Vecteur3D& vecteurNormeReference = Vecteur3D::NormeReference(v1,v2);
    cout<<"Vecteur avec la plus grande norme (par référence):";
    vecteurNormeReference.Afficher();
    return 0;
}

