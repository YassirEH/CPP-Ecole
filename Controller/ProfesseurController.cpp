#include "../Model/ProfesseurModel.h"

using namespace std;

Professeur::Professeur() {
    this->id = 0;
    this->nom = "";
    this->prenom = "";
    this->adresse = "";
    this->niveau = "";
    this->date = 0;
}

Professeur::Professeur(int id, string nom, string prenom, string adresse, string niveau, int date) {
    this->id = id;
    this->nom = nom;
    this->prenom = prenom;
    this->adresse = adresse;
    this->niveau = niveau;
    this->date = date;
}

void Professeur::afficher() const {
    cout << "Id: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Prenom: " << prenom << endl;
    cout << "Adresse: " << adresse << endl;
    cout << "Niveau: " << niveau << endl;
    cout << "Date: " << date << endl;
}

void Professeur::saisir() {
    cout << "Id: ";
    cin >> id;
    cin.ignore();
    
    cout << "Nom: ";
    getline(cin, nom);
    cout << "Prenom: ";
    getline(cin, prenom);
    cout << "Adresse: ";
    getline(cin, adresse);
    cout << "Niveau: ";
    getline(cin, niveau);
    cout << "Date: ";
    cin >> date;
}