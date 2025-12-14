#include<iostream>
#include<string>
#include<vector>
#include"../Model/EtudiantModel.h"
#include"../Model/ProfesseurModel.h"
#include"../Model/ModuleModel.h"
#include"../Model/DateModel.h"

using namespace std;

int main() {
    // Test afficherEtudiantPlus20Ans
    
    // Create some test students with different ages
    Etudiant e1(1, "Alice", "Dupont", "123 Rue Paris", 19);
    Etudiant e2(2, "Bob", "Martin", "456 Rue Lyon", 21);
    Etudiant e3(3, "Charlie", "Durand", "789 Rue Nice", 22);
    Etudiant e4(4, "Diana", "Leblanc", "321 Rue Lille", 20);
    
    // Create a module with these students
    vector<Etudiant> etudiants = {e1, e2, e3, e4};
    Date moduleDate(1, 9, 2024, 8);  // Date needs 4 arguments: jour, mois, annee, heure
    Module module(1, "Mathematiques", 101, moduleDate, 4, etudiants);
    
    cout << "Test de afficherEtudiantPlus20Ans:" << endl;
    cout << "======================================" << endl;
    module.afficherEtudiantPlus20Ans();

    return 0;
}