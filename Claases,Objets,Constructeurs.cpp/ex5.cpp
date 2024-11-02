#include <iostream>
using namespace std;

class Test {
public:
    static int compteur;

    void call() {
        compteur++;
    cout << "La fonction call() a ete appelee "<<Test::compteur<<" fois."<<endl;
    }
};
int Test:: compteur = 0;
int main() {
    Test obj1, obj2;
    obj1.call(); 
    obj1.call(); 
    obj2.call(); 
    return 0;
}
