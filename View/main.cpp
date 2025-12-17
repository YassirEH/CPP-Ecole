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
    cout << "10. Ajouter un etudiant" << endl;
    cout << "11. Afficher un etudiant" << endl;
    cout << "12. Ajouter un professeur" << endl;
    cout << "13. Afficher un professeur" << endl;
    cout << "14. Creer une date" << endl;
    cout << "15. Afficher une date" << endl;
    cout << "0. Quitter" << endl;
    cout << "====================================" << endl;
    cout << "Votre choix: ";
}

int main() {
    vector<Module> modules;
    vector<Etudiant> etudiants;
    vector<Professeur> professeurs;
    vector<Date> dates;
    int choix;
    
    // quelques données de test
    Etudiant e1(1, "Amina", "Alami", "123 Bd Mohammed V, Casablanca", 19);
    Etudiant e2(2, "Omar", "Bennani", "456 Av Hassan II, Rabat", 21);
    Etudiant e3(3, "Karim", "Idrissi", "789 Rue Fes, Marrakech", 22);
    Etudiant e4(4, "Hassan", "Tazi", "321 Bd Zerktouni, Casablanca", 25);
    
    Professeur prof1(101, "El Fassi", "Mohamed", "Rabat", "Mathematiques", 2020);
    Professeur prof2(102, "Berrada", "Fatima", " Fes", "Physique", 2015);
    Professeur prof3(103, "Amrani", "Youssef", "Casablanca", "Informatique", 2010);
    
    // quelques modules de test
    vector<Etudiant> etudiants1 = {e1, e2};
    vector<Etudiant> etudiants2 = {e3, e4};
    vector<Etudiant> etudiants3 = {e1, e3};
    
    Date date1(1, 9, 2024, 8);
    Date date2(15, 1, 2014, 10);  // Module ancien (plus de 10 ans)
    Date date3(10, 3, 2023, 14);
    
    Module module1(1, "Mathematiques Avancees", prof1, date1, 10, etudiants1);
    Module module2(2, "Physique Quantique", prof2, date2, 20, etudiants2);
    Module module3(3, "Programmation C++", prof3, date3, 18, etudiants3);
    
    // les modules initiaux
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
                Module nouveau_module;
                nouveau_module.saisir();
                ajouterModule(modules, nouveau_module);
                break;
            }
            
            case 2: { // Modifier un module
                cout << "\n--- MODIFIER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a modifier: ";
                cin >> id;
                cin.ignore();
                
                modifierModule(modules, id);
                break;
            }
            
            case 3: { // Supprimer un module
                cout << "\n--- SUPPRIMER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a supprimer: ";
                cin >> id;
                cin.ignore();
                
                supprimerModule(modules, id);
                break;
            }
            
            case 4: { // Chercher un module
                cout << "\n--- CHERCHER UN MODULE ---" << endl;
                int id;
                cout << "ID du module a chercher: ";
                cin >> id;
                cin.ignore();
                
                int index = chercherModule(modules, id);
                if(index != -1) {
                    modules[index].afficher();
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 5: { // tous les modules
                cout << "\n--- TOUS LES MODULES ---" << endl;
                if(modules.empty()) {
                    cout << "Aucun module disponible." << endl;
                } else {
                    afficherToutModules(modules);
                }
                break;
            }
            
            case 6: { // modules de plus de 10 ans
                cout << "\n";
                afficherModulesPlus10Ans(modules);
                break;
            }
            
            case 7: { // Ajouter un etudiant a un module
                cout << "\n--- AJOUTER UN ETUDIANT A UN MODULE ---" << endl;
                int id_module;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                
                int index = chercherModule(modules, id_module);
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
            
            case 8: { // retirer un etudiant d'un module
                cout << "\n--- RETIRER UN ETUDIANT D'UN MODULE ---" << endl;
                int id_module, id_etudiant;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                cout << "ID de l'etudiant a retirer: ";
                cin >> id_etudiant;
                cin.ignore();
                
                retirerEtudiant(modules, id_module, id_etudiant);
                break;
            }
            
            case 9: { // etudiants de plus de 20 ans
                cout << "\n--- ETUDIANTS DE PLUS DE 20 ANS ---" << endl;
                int id_module;
                cout << "ID du module: ";
                cin >> id_module;
                cin.ignore();
                
                int index = chercherModule(modules, id_module);
                if(index != -1) {
                    modules[index].afficherEtudiantPlus20Ans();
                } else {
                    cout << "Module non trouve." << endl;
                }
                break;
            }
            
            case 10: { // Ajouter un etudiant
                cout << "\n--- AJOUTER UN ETUDIANT ---" << endl;
                Etudiant etud;
                etud.saisir();
                etudiants.push_back(etud);
                cout << "Etudiant ajoute avec succes!" << endl;
                break;
            }
            
            case 11: { // Afficher un etudiant
                cout << "\n--- AFFICHER UN ETUDIANT ---" << endl;
                if(etudiants.empty()) {
                    cout << "Aucun etudiant disponible." << endl;
                } else {
                    int id;
                    cout << "ID de l'etudiant: ";
                    cin >> id;
                    cin.ignore();
                    
                    bool trouve = false;
                    for(const auto& e : etudiants) {
                        if(e.getId() == id) {
                            e.afficher();
                            trouve = true;
                            break;
                        }
                    }
                    if(!trouve) {
                        cout << "Etudiant non trouve." << endl;
                    }
                }
                break;
            }
            
            case 12: { // Ajouter un professeur
                cout << "\n--- AJOUTER UN PROFESSEUR ---" << endl;
                Professeur prof;
                prof.saisir();
                professeurs.push_back(prof);
                cout << "Professeur ajoute avec succes!" << endl;
                break;
            }
            
            case 13: { // Afficher un professeur
                cout << "\n--- AFFICHER UN PROFESSEUR ---" << endl;
                if(professeurs.empty()) {
                    cout << "Aucun professeur disponible." << endl;
                } else {
                    int id;
                    cout << "ID du professeur: ";
                    cin >> id;
                    cin.ignore();
                    
                    bool trouve = false;
                    for(const auto& p : professeurs) {
                        if(p.getId() == id) {
                            p.afficher();
                            trouve = true;
                            break;
                        }
                    }
                    if(!trouve) {
                        cout << "Professeur non trouve." << endl;
                    }
                }
                break;
            }
            
            case 14: { // Creer une date
                cout << "\n--- CREER UNE DATE ---" << endl;
                Date date;
                date.saisir();
                dates.push_back(date);
                cout << "Date creee avec succes!" << endl;
                break;
            }
            
            case 15: { // Afficher une date
                cout << "\n--- AFFICHER DATE ---" << endl;
                if(dates.empty()) {
                    cout << "Aucune date disponible." << endl;
                } else {
                    cout << "Dates disponibles:" << endl;
                    for(int i = 0; i < dates.size(); i++) {
                        cout << "Date " << (i+1) << ": ";
                        dates[i].afficher();
                    }
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