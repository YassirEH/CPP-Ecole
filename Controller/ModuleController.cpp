#include <iostream>
#include <string>
#include"../Model/ModuleModel.h"
#include"../Model/EtudiantModel.h"

using namespace std;

Module::Module() : id(0), nom(""), professeur_id(0), date(), nombre_etudiants(0) {}

Module::Module(int id, string nom, int professeur_id, Date date, int nombre_etudiants, vector<Etudiant> etudiants)
    : id(id), nom(nom), professeur_id(professeur_id), date(date), nombre_etudiants(nombre_etudiants), etudiants(etudiants) {}

void Module::afficher() const {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Professeur Id: " << professeur_id << endl;
    cout << "Date: ";
    date.afficher();
    cout << "Nombre d'etudiants: " << nombre_etudiants << endl;
    cout << "IDs des etudiants: ";
    for(int i = 0; i < etudiants.size(); i++) {
        cout << etudiants[i].getId();
        if(i < etudiants.size() - 1) cout << ", ";
    }
    cout << endl;
}

void Module::saisir() {
    cout << "Entrez l'Id: ";
    cin >> id;
    cin.ignore();
    cout << "Entrez le nom: ";
    getline(cin, nom);
    cout << "Entrez l'Id du professeur: ";
    cin >> professeur_id;
    cout << "Entrez la date:" << endl;
    date.saisir();
    cout << "Entrez le nombre d'etudiants: ";
    cin >> nombre_etudiants;
}

bool Module::estEtudiantInscrit(Etudiant etudiant) const {
    for (int i = 0; i < nombre_etudiants; i++) {
        if (etudiants[i].comparer(etudiant)) {
            return true;
        }
    }
    return false;
}

void Module::ajouterEtudiant(const Etudiant etudiant) {
    if (etudiants.size() >= nombre_etudiants) {
        cout << "Le module est plein." << endl;
        return;
    }else if (estEtudiantInscrit(etudiant)) {
        cout << "L'etudiant est deja inscrit a ce module." << endl;
        return;
    } else {
        etudiants.push_back(etudiant);
        cout << "Etudiant ajoute avec succes." << endl;
    }
}

void Module::modifierNomModule(){
    string nouveau_nom;
    cin>>nouveau_nom;
    nom = nouveau_nom;
}

void Module::afficherEtudiantPlus20Ans(){
    vector<Etudiant> etudiantsPlus20Ans;
    for (int i = 0; i<nombre_etudiants; i++){
        if(etudiants[i].getAge() > 20){
            etudiantsPlus20Ans.push_back(etudiants[i]);
        }
    }

    cout<<"Les etudiants age de plus que 20 ans sont:"<<endl;
    for(int i = 0; i < etudiantsPlus20Ans.size(); i++){
        etudiantsPlus20Ans[i].afficher();
    }
    
}

void Module::supprimerEtudiant(const Etudiant& etudiant) {
    for (int i = 0; i < etudiants.size(); i++) {
        if (etudiants[i].comparer(etudiant)) {
            etudiants.erase(etudiants.begin() + i);
            cout << "Etudiant supprime avec succes." << endl;
            return;
        }
    }
    cout << "Erreur: L'etudiant ne fait pas partie du module." << endl;
}

