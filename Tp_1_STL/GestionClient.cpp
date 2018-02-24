#include "GestionClient.h"



GestionClient::GestionClient()
{
	this->listeClient = vector <Client>(1);
}

GestionClient::GestionClient(vector<Client> vec , vector<Ressource> ressource)
{
	this->listeClient = vec;
	this->listeRessource = ressource;
}


GestionClient::~GestionClient()
{
}

void GestionClient::ajouterClient(Client & pat)
{
	this->listeClient.push_back(pat);
}

void GestionClient::supprimerClient(int entPosition)
{
	vector<Client>::iterator myIterator;
	myIterator = this->listeClient.begin() + entPosition;
	this->listeClient.erase(myIterator);
}

Client GestionClient::getClient(int entPosition)
{
	vector<Client>::iterator myIterator;
	myIterator = this->listeClient.begin() + entPosition;
	return *myIterator;
}

Client GestionClient::getClientById(int idClient)
{
	vector<Client>::iterator myIterator;
	for (myIterator = this->listeClient.begin(); myIterator !=this->listeClient.end() ;myIterator++)
	{
		if (myIterator->getPATPersonne().getPERID() == idClient)
		{
			return *myIterator;
		}
	}
	return *myIterator;//correspond à null normalement
}
Ressource GestionClient::getRessourceById(int idRessouce)
{
	vector<Ressource>::iterator myIterator;
	for (myIterator = this->listeRessource.begin(); myIterator != this->listeRessource.end(); myIterator++)
	{
		if (myIterator->getRESidressource() == idRessouce)
		{
			return *myIterator;
		}
	}
	return *myIterator;//correspond à null normalement
}

void GestionClient::setRessourceById(int idRessouce, Ressource newRessource)
{
	vector<Ressource>::iterator myIterator;
	for (myIterator = this->listeRessource.begin(); myIterator != this->listeRessource.end(); myIterator++)
	{
		if (myIterator->getRESidressource() == idRessouce)
		{
				*myIterator = newRessource;
		}
	}
}

void GestionClient::viderListeClient()
{
	this->listeClient.clear();
}

void GestionClient::algoRDV()
{

	/*
		1er etape consiste de trier la liste des clients en fonction de leur priorité
	
	*/

	// On parcour tous les clients puis on calcule leur priorité
	map<int, int> ListePrioriteClient;
	vector <Client> ::iterator it;
	vector<int> ::iterator itEntier;
	int dureeConsultationClient;


	for (it = this->listeClient.begin(); it != this->listeClient.end(); it++)
	{
		ListePrioriteClient[it->getIndicePriorite()] = it->getPATPersonne().getPERID();
	}

	//Je cree une nouvelle liste 
	map<int, int> ::reverse_iterator it2;
	vector<Client> nouvelleListeTrier;
	for (it2 = ListePrioriteClient.rbegin(); it2 != ListePrioriteClient.rend(); it2++)
	{
		nouvelleListeTrier.push_back(this->getClientById(it2->second));
	}
	// et liste est trier
	this->listeClient = nouvelleListeTrier;

	vector<Ressource> nouvelleListeRessource;
	for (it = this->listeClient.begin(); it != this->listeClient.end(); it++)
	{
		Client myclient = *it;
		Ressource ressource;
		int comPossible = 0;
		dureeConsultationClient = myclient.dureeParExamen();
		vector<int> listRessource = myclient.getPATVecRessource();
		for (itEntier = listRessource.begin(); itEntier != listRessource.end(); itEntier++)
		{
			ressource = this->getRessourceById(*itEntier);
			comPossible = ressource.ajouterClient(dureeConsultationClient, comPossible, myclient.getPATPersonne().getPERID());
			this->setRessourceById(*itEntier, ressource);
		}

	}
	//this->listeRessource = nouvelleListeRessource;
}

void GestionClient::affichageRessouce()
{
	vector<Ressource> ::iterator it;
	for (it = listeRessource.begin(); it != listeRessource.end(); it++)
	{
		it->affichagePlanning();
	}
}
