#ifndef ETUDIANT_MODEL_H
#define ETUDIANT_MODEL_H

#include<iostream>
#include<string>

using namespace std;

class Etudiant {
private:
    int id;
    string nom;
    string prenom;
    string adresse;
    int age;

public:
    Etudiant(); 
    Etudiant(int id, string nom, string prenom, string adresse, int age);

    int getId() const { return id; }
    string getNom() const { return nom; }
    string getPrenom() const { return prenom; }
    string getAdresse() const { return adresse; }
    int getAge() const { return age; }

    void afficher() const;
    
    void saisir();
    
    bool comparer(const Etudiant e) const;
};

#endif