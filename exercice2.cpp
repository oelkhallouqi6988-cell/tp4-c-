
#include <iostream>
#include <string>
using namespace std;

class Universite {
private:
    string nom;

public:
    // Constructeur
    Universite(string n) {
        nom = n;
    }

    // Afficher le nom de l'universite
    void afficherNom() {
        cout << nom;
    }
};

class Etudiant {
private:
    string nom;
    int age;
    Universite* universite;

    static int nbEtudiants;

public:
    // Constructeur
    Etudiant(string n, int a, Universite* u) {
        nom = n;
        age = a;
        universite = u;
        nbEtudiants++;
    }

    // Afficher les informations de l'etudiant
    void afficher() {
        cout << "Nom : " << nom << endl;
        cout << "Age : " << age << endl;
        cout << "Universite : ";

        if (universite != nullptr) {
            universite->afficherNom();
        }

        cout << endl;
        cout << "----------------------" << endl;
    }

    // Methode statique
    static void afficherTotal() {
        cout << "Nombre total d'etudiants : "
             << nbEtudiants << endl;
    }
};

// Initialisation de l'attribut statique
int Etudiant::nbEtudiants = 0;

int main() {
    Universite u("Universite de Casablanca");

    Etudiant e1("Amine", 20, &u);
    Etudiant e2("Sara", 21, &u);

    e1.afficher();
    e2.afficher();

    Etudiant::afficherTotal();

    return 0;
}
