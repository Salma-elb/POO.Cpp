#include <iostream>
#include <string>

class Voiture {
private:
    std::string marque;
    std::string modele;
    int annee;
    float kilometrage;
    float vitesse;

public:
    // 1. Constructeur par défaut
    Voiture(): marque("Tesla"), modele("Inconnu"), annee(0), kilometrage(0.0), vitesse(0.0){}

    // 2. Constructeur avec paramètres
    Voiture(std::string m, std::string mod, int a, float km, float v)
        : marque(m), modele(mod), annee(a), kilometrage(km), vitesse(v) {}

        // 3. Méthode accelerer(float valeur)
    void accelerer(float valeur) {
        vitesse += valeur;
        std::cout << "La vitesse a augmente de " << valeur << " km/h. Vitesse actuelle: " << vitesse << " km/h." << std::endl;
    }

    // 4. Méthode freiner(float valeur)
    void freiner(float valeur) {
        if (vitesse - valeur < 0) {
            vitesse = 0;
        } else {
            vitesse -= valeur;
        }
        std::cout << "La vitesse a diminue de " << valeur << " km/h. Vitesse actuelle: " << vitesse << " km/h." << std::endl;
    }
   // 5. Méthode afficherInfo()
    void afficherInfo() const {
        std::cout << "Marque: " << marque << std::endl;
        std::cout << "Modele: " << modele << std::endl;
        std::cout << "Annee: " << annee << std::endl;
        std::cout << "Kilometrage: " << kilometrage << " km" << std::endl;
        std::cout << "Vitesse actuelle: " << vitesse << " km/h" << std::endl;}
    // 6. Méthode avancer(float distance)
    void avancer(float distance) {
        kilometrage += distance;
        std::cout << "La voiture a parcouru " << distance << " km. Kilometrage actuel: " << kilometrage << " km." << std::endl;
    }
    // 7. Destructeur
    ~Voiture() {
        std::cout << "La voiture " << marque << " " << modele << " est detruite." << std::endl;
    }
};

int main() {

    std::cout << "--- Le constructeur par defaut ---" << std::endl;
    Voiture voiture1;
    voiture1.afficherInfo();

    std::cout << "--- Le constructeur avec parametres ---" << std::endl;
    Voiture voiture2("Tesla", "Model S", 2021, 30000, 0);
    voiture2.afficherInfo();

    std::cout << "--- Methode accelerer ---" << std::endl;
    voiture2.accelerer(80);

    std::cout << "--- Methode freiner ---" << std::endl;
    voiture2.freiner(10);

    std::cout << "--- Methode afficherInfo ---" << std::endl;
    voiture2.afficherInfo();

    std::cout << "--- Methode avancer ---" << std::endl;
    voiture2.avancer(50);

    std::cout << "--- Destructeur ---" << std::endl;
    return 0;
}