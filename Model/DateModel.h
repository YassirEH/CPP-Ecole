#ifndef DATE_MODEL_H
#define DATE_MODEL_H

#include<iostream>

class Date {
public:
    int jour;
    int mois;
    int annee;
    int heure;

public:
    Date();
    Date(int jour, int mois, int annee, int heure);

    void afficher() const;
    void saisir();
};

#endif