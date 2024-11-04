#include<iostream>
using namespace std;
template<typename T>
class NombreComplexe{
private:
  T reel;
  T imaginaire;
public : 
NombreComplexe() reel(0),imaginaire(0){}
NombreComplexe(T r T i):reel(r),imaginaire(i){}
NombreComplexe(const NombreComplexe&other):reel(other.reel),imaginaire(other.imaginaire){}
void afficher() const{
    if(imaginaire<0){
      cout<<reel<<"-"<<-imaginaire<<"i"<<endl;
    }
    else{
        cout<<reel<<"+"<<imaginaire<<"i"<<endl;
    }
}
    NombreComplexe operator+(const NombreComplexe&other) const{
        return NombreComplexe(reel + other.reel,imaginaire+other.imaginaire);
    }
    NombreComplexe operator-(constNombreComplexe&other)const{
        return NombreComplexe(reel-other.reel,imaginaire-other.imaginaire);
    }
   NombreComplexe operator*(const NombreComplexe &other) const {
        T r = reel * other.reel - imaginaire * other.imaginaire;
        T i = reel * other.imaginaire + imaginaire * other.reel;
        return NombreComplexe(r, i);
    }
    NombreComplexe operator/(const NombreComplexe &other) const {
        T denominateur = other.reel * other.reel + other.imaginaire * other.imaginaire;
        T r = (reel * other.reel + imaginaire * other.imaginaire) / denominateur;
        T i = (imaginaire * other.reel - reel * other.imaginaire) / denominateur;
        return NombreComplexe(r, i);
    }
    bool operator==(const NombreComplexe&other)const{
        return reel==other.reel&&imaginaire==other.imaginaire;
    }
    bool operator!=(const NombreComplexe&other)const{
        return!(*this==other);
    }
   bool operator<(const NombreComplexe &other) const {
        return sqrt(reel * reel + imaginaire*imaginaire) < std::sqrt(other.reel * other.reel + other.imaginaire * other.imaginaire);
    }
    bool operator>(const NombreComplexe &other) const {
        return other < *this;
    }
    bool operator<=(const NombreComplexe &other) const {
        return !(other < *this);
    }
    bool operator>=(const NombreComplexe &other) const {
        return !(*this < other);
    }
    friend ostream& operator<<(ostream &os, const NombreComplexe &nombre) {
        if (nombre.imaginaire < 0) {
            os << nombre.reel << " - " << -nombre.imaginaire << "i";
        } else {
            os << nombre.reel << " + " << nombre.imaginaire << "i";
        }
        return os;
    }
};
int main() {
    NombreComplexe<int> c1(3, 4);
    NombreComplexe<int> c2(1, -2);
    cout << "c1: "; c1.afficher();
    cout << "c2: "; c2.afficher();
    cout << "\nOpérations arithmétiques:"<<endl;
    cout << "c1 + c2 = " << c1 + c2 <<endl;
    cout << "c1 - c2 = " << c1 - c2 <<endl;
    cout << "c1 * c2 = " << c1 * c2 <<endl;
    cout << "c1 / c2 = " << c1 / c2 <<endl;
    cout << "\nOpérateurs de comparaison:" <<endl;
    cout << "c1 == c2: " << (c1 == c2 ? "true" : "false")<<endl;
    cout << "c1 != c2: " << (c1 != c2 ? "true" : "false")<<endl;
    cout << "c1 < c2: " << (c1 < c2 ? "true" : "false")<<endl;
    cout << "c1 > c2: " << (c1 > c2 ? "true" : "false")<<endl;
    cout << "c1 <= c2: " << (c1 <= c2 ? "true" : "false")<<endl;
    cout << "c1 >= c2: " << (c1 >= c2 ? "true" : "false")<<endl;
    return 0;
}
