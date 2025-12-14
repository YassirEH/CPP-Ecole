#ifndef PROFESSEUR_MODEL_H
#define PROFESSEUR_MODEL_H

#include<iostream>
#include<string>

using namespace std;

class Professeur {
private:
    int id;
    string nom;
    string prenom;
    string adresse;
    string niveau;
    int date;

public:
    Professeur();
    Professeur(int id, string nom, string prenom, string adresse, string niveau, int date);

    int getId() const { return id; }
    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }
    string getAdresse() const { return adresse; }
    string getNiveau() const { return niveau; }
    int getDate() const { return date; }

    void afficher() const;
    
    void saisir();
    
};

#endif