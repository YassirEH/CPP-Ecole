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
    void afficherEtudiantPlus20Ans();
    void supprimerEtudiant(const Etudiant& etudiant);
    void afficher() const;

};

#endif