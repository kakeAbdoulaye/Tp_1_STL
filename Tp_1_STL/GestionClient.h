#pragma once
#ifndef GESTIONClient_H
#define GESTIONClient_H

#include "Client.h"
#include "Ressource.h"
#include <vector>

using namespace std;

class GestionClient
{
private : 
	vector<Client> listeClient;
	vector<Ressource> listeRessource;
	
public:
	GestionClient();
	GestionClient(vector<Client> vec , vector<Ressource> ressource);
	~GestionClient();

	void ajouterClient(Client & pat);
	void supprimerClient(int entPosition);
	Client getClient(int entPosition);
	Client getClientById(int idClient);
	Ressource getRessourceById(int idRessouce);
	void setRessourceById(int idRessouce , Ressource newRessource);
	//Prioriser le client 
	void viderListeClient();
	void algoRDV();
	void affichageRessouce();
};

#endif // !GESTIONClient_H