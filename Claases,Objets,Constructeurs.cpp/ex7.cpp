#include <iostream>
#include <vector>
using namespace std;
class Pile{
private:
    vector<int> elements; 
public:
    Pile(){}
    void push(int element){
        elements.push_back(element);
    }
    int pop() {
        if(elements.empty()) {
            cout << "La pile est vide. Impossible de depiler."<<endl;
            return -1; 
        }
        int element=elements.back();
        elements.pop_back();
        return element;
    }
    bool estVide()const {
        return elements.empty();
    }
};
int main() {
    Pile p1, p2;
    p1.push(10);
    p1.push(30);
    p1.push(50);
    cout<<"Depiler de la pile p1 : "<<p1.pop()<<endl; 
    cout<<"Depiler de la pile p1 : "<<p1.pop()<<endl;
    cout<<"Depiler de la pile p1 : "<<p1.pop()<<endl; 
    cout<<"Depiler de la pile p1 : "<<p1.pop()<<endl;  
    p2.push(70);
    p2.push(90);
    cout<<"Depiler de la pile p2 : "<<p2.pop()<<endl; 
    cout<<"Depiler de la pile p2 : "<<p2.pop()<<endl;
    cout<<"Depiler de la pile p2 : "<<p2.pop()<<endl;  
    return 0;
}
