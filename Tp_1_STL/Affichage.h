#pragma once
#ifndef GestionPatient_H
#define GestionPatient_H

#include "Client.h"
#include <algorithm>

class Affichage
{
private:
	double sommePriorite;
	double sommeTotalConsul;
	ostream & fluxOs;

public:

	Affichage(ostream & out):fluxOs(out),sommePriorite(0.0),sommeTotalConsul(0.0){}
	~Affichage();
	void operator()(Client & p);

	double getSommePriorite() { return sommePriorite; }
	double getSommeTotalConsul() { return sommeTotalConsul; }

};

#endif


