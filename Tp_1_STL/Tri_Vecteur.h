#pragma once
#ifndef TRIVECTEUR_H
#define TRIVECTEUR_H
#include "Client.h"
#include <algorithm>

using namespace std;
class Tri_Vecteur
{

public:
	Tri_Vecteur();
	~Tri_Vecteur();
	Client operator()(Client & p);
};

#endif // !TRIVECTEUR_H