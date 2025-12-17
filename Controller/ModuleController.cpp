#include <iostream>
#include <string>
#include"../Model/ModuleModel.h"
#include"../Model/EtudiantModel.h"

using namespace std;

Module::Module() : id(0), nom(""), professeur(), date(), nombre_etudiants(0) {}

Module::Module(int id, string nom, Professeur professeur, Date date, int nombre_etudiants, vector<Etudiant> etudiants)
    : id(id), nom(nom), professeur(professeur), date(date), nombre_etudiants(nombre_etudiants), etudiants(etudiants) {}

void Module::saisir() {
    cout << "Entrez l'Id: ";
    cin >> id;
    cin.ignore();
    cout << "Entrez le nom: ";
    getline(cin, nom);
    
    cout << "Informations du professeur:" << endl;
    professeur.saisir();
    
    cout << "Date de lancement:" << endl;
    date.saisir();
    
    cout << "Entrez le nombre d'etudiants: ";
    cin >> nombre_etudiants;
    cin.ignore();
    
    etudiants.clear();
    for(int i = 0; i < nombre_etudiants; i++) {
        cout << "\nEtudiant " << (i+1) << ":" << endl;
        Etudiant etud;
        etud.saisir();
        etudiants.push_back(etud);
    }
    cout << "Etudiant ajoute avec success";
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

void Module::afficherEtudiantPlus20Ans() const {
    vector<Etudiant> etudiantsPlus20Ans;
    for (int i = 0; i < etudiants.size(); i++){
        if(etudiants[i].getAge() > 20){
            etudiantsPlus20Ans.push_back(etudiants[i]);
        }
    }

    cout<<"Les etudiants age de plus que 20 ans sont:"<<endl;
    if(etudiantsPlus20Ans.empty()) {
        cout << "Aucun etudiant de plus de 20 ans." << endl;
    } else {
        for(int i = 0; i < etudiantsPlus20Ans.size(); i++){
            etudiantsPlus20Ans[i].afficher();
        }
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

void Module::afficher() const {
    cout << "ID: " << id << endl;
    cout << "Nom: " << nom << endl;
    cout << "Date lancement module: ";
    date.afficher();
    cout << "Nombre d'etudiants: " << nombre_etudiants << endl << endl;
    cout << "les Etudiants: ";
    for(int i = 0; i < etudiants.size(); i++) {
        etudiants[i].afficher();
        if(i<etudiants.size()){
            cout<< endl;
        }
    }
    cout<<"Professeur du module " << nom << ":" << endl;
    this->getProfesseur();
    cout << endl;
}

int chercherModule(const vector<Module>& modules, int id) {
    for (int i = 0; i < modules.size(); i++) {
        if (modules[i].getId() == id) {
            return i;
        }
    }
    return -1;
}

void ajouterModule(vector<Module>& modules, const Module& new_module){
    if(chercherModule(modules, new_module.getId()) != -1){
        cout << "Erreur: Un module avec cet id existe deja" << endl;
        return;
    }
    modules.push_back(new_module);
}

void Module::modifierProfesseur(Professeur& nouveau_prof){
    this->professeur = nouveau_prof;
}

void modifierModule(vector<Module>& modules, int id){
    int index = chercherModule(modules, id);
    
    if (index == -1) {
        cout << "Erreur: Module non trouve." << endl;
        return;
    }
    
    int choix;
    cout << "Que voulez-vous modifier?" << endl;
    cout << "1. Nom du module" << endl;
    cout << "2. Professeur du module" << endl;
    cout << "3. Les deux" << endl;
    cout << "Votre choix: ";
    cin >> choix;
    cin.ignore();
    
    if (choix == 1 || choix == 3) {
        cout << "Entrez le nouveau nom du module: ";
        string nouveau_nom;
        getline(cin, nouveau_nom);
        modules[index].modifierNomModule();
        cout << "Nom du module modifie avec succes." << endl;
    }
    
    if (choix == 2 || choix == 3) {
        cout << "Entrez les informations du nouveau professeur:" << endl;
        Professeur nouveau_prof;
        nouveau_prof.saisir();
        modules[index].modifierProfesseur(nouveau_prof);
    }
}

void supprimerModule(vector<Module>& modules, int id) {
    int index = chercherModule(modules, id);
    if (index == -1) {
        cout << "Erreur: module non trouve" << endl;
        return;
    }
    
    modules.erase(modules.begin() + index);
    cout << "module supprime avec success" << endl;
}

void afficherToutModules(vector<Module>& modules){
    for (int i = 0; i < modules.size(); i++){
        modules[i].afficher();
        cout << endl;
    }
}

void retirerEtudiant(vector<Module>& modules, int module_id, int etudiant_id) {
    int index = chercherModule(modules, module_id);
    if (index == -1) {
        cout << "Erreur: module non trouve." << endl;
        return;
    }
    Etudiant etud_temp(etudiant_id, "", "", "", 0);
    modules[index].supprimerEtudiant(etud_temp);
}

void afficherModulesPlus10Ans(vector<Module>& modules) {
    cout << "Entrez la date de reference pour la comparaison:" << endl;
    Date date;
    date.saisir();
    
    bool trouve = false;
    
    cout << "\n========== MODULES DE PLUS DE 10 ANS ==========" << endl;
    
    for (int i = 0; i < modules.size(); i++) {
        Date date_lancement = modules[i].getDate();
        
        // Calculer la différence en années
        int diff_annees = date.annee - date_lancement.annee;
        
        // Ajuster si le mois/jour n'est pas encore passé
        if (date.mois < date_lancement.mois || 
            (date.mois == date_lancement.mois && date.jour < date_lancement.jour)) {
            diff_annees--;
        }
        
        if (diff_annees > 10) {
            modules[i].afficher();
            cout << "Anciennete: " << diff_annees << " ans" << endl;
            cout << "---------------------------------------" << endl;
            trouve = true;
        }
    }
    
    if (!trouve) {
        cout << "Aucun module de plus de 10 ans trouve." << endl;
    }
}