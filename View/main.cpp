#include<iostream>
#include<string>
#include<vector>
#include"../Model/EtudiantModel.h"
#include"../Model/ProfesseurModel.h"
#include"../Model/ModuleModel.h"
#include"../Model/DateModel.h"

using namespace std;

int main() {
    // Test afficher method
    
    // Create some test students
    Etudiant e1(1, "Alice", "Dupont", "123 Rue Paris", 19);
    Etudiant e2(2, "Bob", "Martin", "456 Rue Lyon", 21);
    Etudiant e3(3, "Charlie", "Durand", "789 Rue Nice", 22);
    
    // Create a professor
    Professeur prof(101, "Moreau", "Paul", "10 Rue Sorbonne", "Mathematiques", 2020);
    
    // Create a module with these students
    vector<Etudiant> etudiants = {e1, e2, e3};
    Date moduleDate(1, 9, 2024, 8);
    Module module(1, "Mathematiques", prof, moduleDate, 3, etudiants);
    
    cout << "Test de Module::afficher():" << endl;
    cout << "======================================" << endl;
    module.afficher();

    return 0;
}