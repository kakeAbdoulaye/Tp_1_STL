#include "GestionClient.h"
#include "Affichage.h"
#include "Tri_Vecteur.h"
#include <map>

using namespace std;

int main()
{
	Ressource r1 = Ressource(1);
	Ressource r2 = Ressource(2);
	
	Personne  p1 =  Personne(1,"Kake", "Abdoulaye", 783);
	Personne  p2 =  Personne(2,"Orel", "Michel", 786);
	Personne  p3 = Personne(3,"Konate", "Mariam", 787);
	Personne  p4 = Personne(4, "Ribeiro", "Catarina", 788);

	Adresse  a1 =  Adresse("allee bourdaisiere", "Tours", 37000);
	Adresse a2 =  Adresse("rue vache", "Tours", 37000);
	Adresse a3 =  Adresse("avenue Monsieur", "Tours", 37000);
	Adresse a4 = Adresse("rue Portugais", "Tours", 37000);

	Client pa1 = Client(p1, a1, 30, 1, "Doit être soigner au plus vite");
	pa1.ajouterIdenRessource(2);

	Client pa2 = Client(p2, a2, 60 , 1, "Douleur abdominale");
	pa2.ajouterIdenRessource(1);
	pa2.ajouterIdenRessource(2);


	Client pa3 = Client(p3, a3, 60, 1, "Femme enceinte ");
	pa3.ajouterIdenRessource(1);
	pa3.ajouterIdenRessource(2);

	Client pa4 = Client(p4, a4, 30, 1, "Femme marié  ");
	pa4.ajouterIdenRessource(1);
	pa4.ajouterIdenRessource(2);

	vector <Client> patients;
	patients.push_back(pa1);
	patients.push_back(pa2);
	patients.push_back(pa3);
	patients.push_back(pa4);

	vector<Ressource> ressource;
	ressource.push_back(r1);
	ressource.push_back(r2);

	GestionClient gestion = GestionClient(patients,ressource);
	gestion.algoRDV();
	gestion.affichageRessouce();

	//map<int, int> ListePrioritePatient;
	

	/*vector <Client> ::iterator it;
	for (it = patients.begin(); it != patients.end(); it++)
	{
		it->afficheClient();
		ListePrioritePatient[it->getIndicePriorite()]= it->getPATPersonne().getPERID();
	}
	map<int, int> ::iterator it2;
	for (it2 = ListePrioritePatient.begin(); it2 != ListePrioritePatient.end(); it2++)
	{
		cout << "Cle : " << it2->first << " Valeur : " << it2->second << endl;
	}
	
	*/
	/*Affichage aff = for_each(patients.begin(), patients.end(), Affichage(cout));
	cout << " Somme dure consultation : " << aff.getSommeTotalConsul() << endl;
	cout << " Somme Priorite : " << aff.getSommePriorite()/3 << endl;*/
	

	/*transform(patients.begin(), patients.end(),patients2.begin(), Tri_Vecteur());*/

	/*map<int, int> ListePrioritePatient;
	map<int, int>::reverse_iterator it;
	ListePrioritePatient[1] = 5;
	it = ListePrioritePatient.rbegin() ;
	cout <<it->second<< endl;
	*/
	

	return 0;
}
