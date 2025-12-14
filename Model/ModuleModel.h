#ifndef MODULE_MODEL_H
#define MODULE_MODEL_H

#include<iostream>
#include<vector>
#include"DateModel.h"
#include"EtudiantModel.h"

using namespace std;

class Module{
private:
    int id;
    string nom;
    int professeur_id;
    Date date;
    int nombre_etudiants;
    vector<Etudiant> etudiants;

public:
    Module();
    Module(int id, string nom, int professeur_id, Date date, int nombre_etudiants, vector<Etudiant> etudiants);

    int getId() const { return id; }
    string getNom() const { return nom; }
    int getProfesseurId() const { return professeur_id; }
    Date getDate() const { return date; }



    void afficher() const;
    void saisir();
    bool estEtudiantInscrit(const Etudiant etudiant) const;
    void ajouterEtudiant(const Etudiant etudiant);
    void modifierNomModule();
    void afficherEtudiantPlus20Ans();
    void supprimerEtudiant(const Etudiant& etudiant);

};

#endif