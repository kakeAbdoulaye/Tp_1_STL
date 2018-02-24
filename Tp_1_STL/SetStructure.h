#pragma once
#include <iostream>
#include <set>
#include <vector>
#include <math.h>
#include <cstdlib>

using namespace std;


struct S_Coord
{
	double d_X;
	double d_Y;

};
bool operator<(const S_Coord & s1, const S_Coord & s2);

void utilisationSetStructure();
void affichageCoord(set<S_Coord> & ens);
vector<vector<double>> distanceEucludienne(set<S_Coord> & ens);
void affichageDistanceEucludienne(vector<vector<double>> & distance);
void saisieUtlisateur(vector<vector<double>> & distance);

