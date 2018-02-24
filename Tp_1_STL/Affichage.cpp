#include "Affichage.h"





Affichage::~Affichage()
{
}
void Affichage::operator()(Client & p)
{
	fluxOs <<"Nom : " <<p.getPATPersonne().getPERNom()<< "  Prenom : " << p.getPATPersonne().getPERPrenom() << endl;
	sommePriorite += p.getPATPriorite();
	sommeTotalConsul += p.getPATDureeConsultation();
}
