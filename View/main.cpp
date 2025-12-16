#include<iostream>
#include<string>
#include<vector>
#include"../Model/EtudiantModel.h"
#include"../Model/ProfesseurModel.h"
#include"../Model/ModuleModel.h"
#include"../Model/DateModel.h"

using namespace std;

void afficherMenu() {
    cout << "\n========== MENU PRINCIPAL ==========" << endl;
    cout << "1. Ajouter un module" << endl;
    cout << "2. Modifier un module" << endl;
    cout << "3. Supprimer un module" << endl;
    cout << "4. Chercher un module" << endl;
    cout << "5. Afficher tous les modules" << endl;
    cout << "6. Afficher modules de plus de 10 ans" << endl;
    cout << "7. Ajouter un etudiant a un module" << endl;
    cout << "8. Retirer un etudiant d'un module" << endl;
    cout << "9. Afficher etudiants de plus de 20 ans d'un module" << endl;
    cout << "0. Quitter" << endl;
    cout << "====================================" << endl;
    cout << "Votre choix: ";
}

int main() {
    vector<Module> modules;
    int choix;
    
    // Créer quelques données de test
    Etudiant e1(1, "Alice", "Dupont", "123 Rue Paris", 19);
    Etudiant e2(2, "Bob", "Martin", "456 Rue Lyon", 21);
    Etudiant e3(3, "Charlie", "Durand", "789 Rue Nice", 22);
    Etudiant e4(4, "David", "Bernard", "321 Rue Nice", 25);
    
    Professeur prof1(101, "Moreau", "Paul", "10 Rue Sorbonne", "Mathematiques", 2020);
    Professeur prof2(102, "Dubois", "Marie", "20 Rue Lyon", "Physique", 2015);
    Professeur prof3(103, "Lambert", "Jean", "30 Rue Paris", "Informatique", 2010);
    
    // Créer quelques modules de test
    vector<Etudiant> etudiants1 = {e1, e2};
    vector<Etudiant> etudiants2 = {e3, e4};
    vector<Etudiant> etudiants3 = {e1, e3};
    
    Date date1(1, 9, 2024, 8);
    Date date2(15, 1, 2014, 10);  // Module ancien (plus de 10 ans)
    Date date3(10, 3, 2023, 14);
    
    Module module1(1, "Mathematiques Avancees", prof1, date1, 3, etudiants1);
    Module module2(2, "Physique Quantique", prof2, date2, 3, etudiants2);
    Module module3(3, "Programmation C++", prof3, date3, 3, etudiants3);
    
    // Ajouter les modules initiaux
    modules.push_back(module1);
    modules.push_back(module2);
    modules.push_back(module3);
    
    cout << "========================================" << endl;
    cout << "   SYSTEME DE GESTION DES MODULES" << endl;
    cout << "========================================" << endl;
    cout << modules.size() << " module(s) charge(s) pour les tests.\n" << endl;
    
    do {
        afficherMenu();
        cin >> choix;
        cin.ignore();
        
        switch(choix) {
            case 1: { // Ajouter un module
                cout << "\n--- AJOUTER UN MODULE ---" << endl;
                int id;
                string nom;
                
                cout << "ID du module: ";
                cin >> id;
                cin.ignore();
                cout << "Nom du module: ";
                getline(cin, nom);
                
                cout << "Informations du professeur:" << endl;
                Professeur prof;
                prof.saisir();
                
                cout << "Date de lancement:" << endl;
                Date date;
                date.saisir();
                
                int nb_etudiants;
                cout << "Nombre d'etudiants: ";
                cin >> nb_etudiants;
                cin.ignore();
                
                vector<Etudiant> etudiants;
                for(int i = 0; i < nb_etudiants; i++) {
                    cout << "\nEtudiant " << (i+1) << ":" << endl;
                    Etudiant etud;
                    etud.saisir();
                    etudiants.push_back(etud);
                }
                
                Module nouveau_module(id, nom, prof, date, nb_etudiants, etudiants);
                ajouterModule(modules, nouveau_module);
                break;
            }
            
            case 2: { // Modifier un module
                cout << "\n--- MODIFIER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a modifier: ";
                cin >> id;
                cin.ignore();
                
                Module module_temp;
                bool trouve = false;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id) {
                        module_temp = modules[i];
                        trouve = true;
                        break;
                    }
                }
                
                if(trouve) {
                    modifierModule(modules, module_temp);
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 3: { // Supprimer un module
                cout << "\n--- SUPPRIMER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a supprimer: ";
                cin >> id;
                cin.ignore();
                
                Module module_temp;
                bool trouve = false;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id) {
                        module_temp = modules[i];
                        trouve = true;
                        break;
                    }
                }
                
                if(trouve) {
                    supprimerModule(modules, module_temp);
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 4: { // Chercher un module
                cout << "\n--- CHERCHER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a chercher: ";
                cin >> id;
                cin.ignore();
                
                Module module_temp;
                bool trouve = false;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id) {
                        module_temp = modules[i];
                        trouve = true;
                        break;
                    }
                }
                
                int index = chercherModule(modules, module_temp);
                if(index != -1) {
                    cout << "\nModule trouve a l'index " << index << ":" << endl;
                    modules[index].afficher();
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 5: { // Afficher tous les modules
                cout << "\n--- TOUS LES MODULES ---" << endl;
                if(modules.empty()) {
                    cout << "Aucun module disponible." << endl;
                } else {
                    afficherToutModules(modules);
                }
                break;
            }
            
            case 6: { // Afficher modules de plus de 10 ans
                cout << "\n";
                // afficherModulesPlus10Ans(modules);
                break;
            }
            
            case 7: { // Ajouter un etudiant a un module
                cout << "\n--- AJOUTER UN ETUDIANT A UN MODULE ---" << endl;
                int id_module;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                
                int index = -1;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id_module) {
                        index = i;
                        break;
                    }
                }
                
                if(index != -1) {
                    cout << "Informations de l'etudiant:" << endl;
                    Etudiant etud;
                    etud.saisir();
                    modules[index].ajouterEtudiant(etud);
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 8: { // Retirer un etudiant d'un module
                cout << "\n--- RETIRER UN ETUDIANT D'UN MODULE ---" << endl;
                int id_module, id_etudiant;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                
                Module module_temp;
                bool trouve = false;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id_module) {
                        module_temp = modules[i];
                        trouve = true;
                        break;
                    }
                }
                
                if(trouve) {
                    cout << "ID de l'etudiant a retirer: ";
                    cin >> id_etudiant;
                    cin.ignore();
                    
                    Etudiant etud_temp(id_etudiant, "", "", "", 0);
                    retirerEtudiant(modules, module_temp, etud_temp);
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 9: { // Afficher etudiants de plus de 20 ans
                cout << "\n--- ETUDIANTS DE PLUS DE 20 ANS ---" << endl;
                int id_module;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                
                int index = -1;
                for(int i = 0; i < modules.size(); i++) {
                    if(modules[i].getId() == id_module) {
                        index = i;
                        break;
                    }
                }
                
                if(index != -1) {
                    modules[index].afficherEtudiantPlus20Ans();
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 0:
                cout << "\nAu revoir!" << endl;
                break;
                
            default:
                cout << "\nChoix invalide. Veuillez reessayer." << endl;
        }
        
        if(choix != 0) {
            cout << "\nAppuyez sur Entree pour continuer...";
            cin.get();
        }
        
    } while(choix != 0);

    return 0;
}