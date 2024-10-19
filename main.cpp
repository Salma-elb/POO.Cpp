#include <iostream>
#include <stdexcept>
#include <vector>
using namespace std;

void afficherTaille(const vector<int>& tableau) {
    cout << "Fonction appelee avec " << tableau.size() << " elements." << endl;
}
int main() {
    try {
        // Boucle qui crée des tableaux de plus en plus grands
        for (size_t taille = 1;; taille *= 3) {
            vector<int> tableau(taille, 1);
            afficherTaille(tableau);
        }
    } catch (const bad_alloc& erreur) {
        cout << "Erreur d'allocation de memoire : " << erreur.what() << endl;
    }

    return 0;
}
