#include <iostream>
using namespace std;
class Complex {
private:
    double real;
    double imag;
public:
    Complex(double r = 0, double i=0) :real(r),imag(i) {}
    Complex operator+(const Complex& other) const {
        return Complex(real+other.real,imag+other.imag);
    }
    Complex operator-(const Complex& other) const {
        return Complex(real-other.real, imag-other.imag);
    }
    Complex operator*(const Complex& other) const {
        return Complex(real * other.real-imag * other.imag,real*other.imag+imag*other.real);
    }
    Complex operator/(const Complex& other) const {
        double denominator = other.real*other.real+other.imag*other.imag;
        return Complex((real * other.real + imag * other.imag) / denominator,(imag*other.real-real*other.imag)/denominator);
    }
    bool operator==(const Complex& other) const {
        return (real==other.real) && (imag==other.imag);
    }
        void display() const {
        cout<<real<<(imag>=0? " + " : " - ")<<abs(imag)<<"i"<<endl;
    }
};
int main() {
    double real1,imag1,real2,imag2;
    int choix;
    cout << "Entrez la partie reelle du premier nombre complexe : ";
    cin >> real1;
    cout << "Entrez la partie imaginaire du premier nombre complexe : ";
    cin >> imag1;
    cout << "Entrez la partie reelle du deuxieme nombre complexe : ";
    cin >> real2;
    cout << "Entrez la partie imaginaire du deuxieme nombre complexe : ";
    cin >> imag2;
    Complex num1(real1, imag1), num2(real2, imag2), resultat;
    cout<<"Choisissez l'operation : "<<endl;
    cout<<"1. Addition"<<endl;
    cout<<"2. Soustraction"<<endl;
    cout<<"3. Multiplication"<<endl;
    cout<<"4. Division"<<endl;
    cout<<"5. Comparaison (egalite)"<<endl;
    cout<<"Votre choix : ";
    cin >> choix;
    switch (choix) {
        case 1:
            resultat=num1+num2;
            cout<<"Resultat de l'addition : ";
            resultat.display();
            break;
        case 2:
            resultat=num1-num2;
            cout<<"Resultat de la soustraction : ";
            resultat.display();
            break;
        case 3:
            resultat=num1*num2;
            cout<<"Resultat de la multiplication : ";
            resultat.display();
            break;
        case 4:
            resultat=num1/num2;
            cout<<"Resultat de la division : ";
            resultat.display();
            break;
        case 5:
            if (num1==num2)
                cout<<"Les deux nombres complexes sont egaux."<<endl;
            else
                cout<<"Les deux nombres complexes ne sont pas egaux."<<endl;
            break;
        default:
            cout<<"Choix invalide !"<<endl;
    }
    return 0;
}
