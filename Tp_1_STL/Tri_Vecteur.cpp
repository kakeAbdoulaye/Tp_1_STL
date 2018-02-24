#include "Tri_Vecteur.h"



Tri_Vecteur::Tri_Vecteur()
{
}


Tri_Vecteur::~Tri_Vecteur()
{
}

Client Tri_Vecteur::operator()(Client & p)
{
	vector<int> identifiantRessource = p.getPATVecRessource();
	sort(identifiantRessource.begin(), identifiantRessource.end());
	p.setPATVecRessource(identifiantRessource);
	return p;
}
