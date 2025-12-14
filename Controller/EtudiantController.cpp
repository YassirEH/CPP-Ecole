#include"../Model/EtudiantModel.h"

using namespace std;

Etudiant::Etudiant() {
    this->id = 0;
    this->nom = "";
    this->prenom = "";
    this->adresse = "";
    this->age = 0;
}

Etudiant::Etudiant(int id, string nom, string prenom, string adresse, int age) {
	this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->age = age;
}

void Etudiant::afficher() const {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Age: " << age << endl;
}

void Etudiant::saisir() {
    cout << "ID: ";
    cin >> id;
    cin.ignore();
    
    cout << "Nom: ";
    getline(cin, nom);
    cout << "Prenom: ";
    getline(cin, prenom);
    cout << "Adresse: ";
    getline(cin, adresse);
    
    cout << "Age: ";
    cin >> age;
}

bool Etudiant::comparer(const Etudiant e) const {
    return this->id == e.id;
}