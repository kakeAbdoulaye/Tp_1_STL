#pragma once
#include <iostream>
#include <vector>

using namespace std;

void utilisationVector();
void remplirVectorInt(vector <int> &listeInt, size_t nombreSaisie);
void affichageSansItera(vector <int> const& listeInt);
void affichageAvecItera(vector <int> & listeInt);
void supprimeElement(vector <int> & listeInt, int debut, int fin);
void insererElement(vector <int> & listeInt, int debut, int fin);
void viderliste(vector <int> & listeInt);
