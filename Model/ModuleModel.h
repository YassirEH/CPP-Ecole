#ifndef MODULE_MODEL_H
#define MODULE_MODEL_H

#include<iostream>
#include<vector>
#include"DateModel.h"
#include"EtudiantModel.h"
#include"ProfesseurModel.h"

using namespace std;

class Module{
private:
    int id;
    string nom;
    Professeur professeur;
    Date date;
    int nombre_etudiants;
    vector<Etudiant> etudiants;

public:
    Module();
    Module(int id, string nom, Professeur professeur, Date date, int nombre_etudiants, vector<Etudiant> etudiants);

    int getId() const { return id; }
    string getNom() const { return nom; }
    Date getDate() const { return date; }
    void getProfesseur() const { return professeur.afficher(); }



    void saisir();
    bool estEtudiantInscrit(const Etudiant etudiant) const;
    void ajouterEtudiant(const Etudiant etudiant);
    void modifierNomModule();
    void afficherEtudiantPlus20Ans() const;
    void supprimerEtudiant(const Etudiant& etudiant);
    void afficher() const;
    void modifierProfesseur(Professeur& nouveau_prof);
};
int chercherModule(const vector<Module>& modules, const Module& module_a_rechercher);
void ajouterModule(vector<Module>& modules, const Module& new_module);
void modifierModule(vector<Module>& modules, const Module& updated_module);
void supprimerModule(vector<Module>& modules, const Module& module_to_delete);
void afficherToutModules(vector<Module>& modules);
void retirerEtudiant(vector<Module>& modules, Etudiant etudiant);
#endif