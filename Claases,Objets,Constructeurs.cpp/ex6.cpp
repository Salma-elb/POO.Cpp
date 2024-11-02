#include <iostream>
using namespace std;
class Point {
private:
    float x; 
    float y; 
public:
    Point(float x_coord,float y_coord):x(x_coord),y(y_coord) {}
    void deplace(float deltaX, float deltaY) {
        x += deltaX;
        y += deltaY;
    }
    void affiche() const {
        cout << "Point(" << x << ", " << y << ")" <<endl;
    }
};
int main() {
    float x_coord, y_coord;
    cout << "Entrez les coordonnees du point (x y) : ";
    cin >> x_coord >> y_coord;
    Point p(x_coord, y_coord);
    cout << "Coordonnees initiales du point : ";
    p.affiche();
    float deltaX, deltaY;
    cout << "Entrez les valeurs de déplacement (deltaX deltaY) : ";
    cin >> deltaX >> deltaY;
    p.deplace(deltaX, deltaY);
    cout << "Coordonnees apres deplacement : ";
    p.affiche();
    return 0;
}

