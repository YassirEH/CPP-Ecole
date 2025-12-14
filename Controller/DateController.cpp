#include"../Model/DateModel.h"
#include <iostream>


using namespace std;

Date::Date() {
    jour = 0;
    mois = 0;
    annee = 0;
    heure = 0;
}

Date::Date(int jour, int mois, int annee, int heure) {
    if (annee < 0) {
        this->annee = 0;
    } else {
        this->annee = annee;
    }
    
    if (mois < 1 || mois > 12) {
        this->mois = 1;
    } else {
        this->mois = mois;
    }
    
    if (jour < 1 || jour > 31) {
        this->jour = 1;
    } else {
        this->jour = jour;
    }

    if (heure < 0 || heure > 23) {
        this->heure = 0;
    } else {
        this->heure = heure;
    }

}

void Date::afficher() const {
    cout << jour << "/" << mois << "/" << annee << " " << heure << "h" << endl;
}

void Date::saisir() {
    cout << "Jour: ";
    cin >> jour;
    cout << "Mois: ";
    cin >> mois;
    cout << "Annee: ";
    cin >> annee;
    cout << "Heure: ";
    cin >> heure;
}