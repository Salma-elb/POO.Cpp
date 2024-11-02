#include <iostream>
#include <string>
using namespace std;
class Animal{
protected:
    string nom;
    int age;

public:
    void set_value(string n,int a) {
        nom=n;
        age=a;
    }
};
class Zebra : public Animal {
public:
    void display_info() const {
        cout<<"Nom du zebre : "<<nom<<endl;
        cout<<"Age du zebre : "<<age << " ans"<<endl;
        cout<<"Information supplementaire : Les zebres vivent en groupes dans les savanes africaines et se caracterisent par leurs rayures uniques."<<endl;
    }
};
class Dolphin : public Animal {
public:
    void display_info() const {
        cout<<"Nom du dauphin : "<<nom<<endl;
        cout<<"Age du dauphin : "<<age<<" ans"<<endl;
        cout<<"Information supplementaire : Les dauphins sont des mammiferes marins intelligents qui communiquent par des sons et vivent principalement dans les oceans tropicaux."<<endl;
    }
};
int main() {
    Zebra zebra;
    zebra.set_value("Stripes",6);
    cout<<"Informations sur le zebre :"<<endl;
    zebra.display_info();
    cout<<endl;
    Dolphin dolphin;
    dolphin.set_value("Wave",4);
    cout<<"Informations sur le dauphin :"<<endl;
    dolphin.display_info();
    return 0;
}
