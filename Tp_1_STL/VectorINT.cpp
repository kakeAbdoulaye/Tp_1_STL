#include "VectorINT.h"

void utilisationVector()
{
	vector<int> listeInt(5);
	remplirVectorInt(listeInt, 5);
	affichageSansItera(listeInt);
	supprimeElement(listeInt, 0, 4);
	affichageSansItera(listeInt);
	insererElement(listeInt, 0, 3);
	affichageSansItera(listeInt);
	viderliste(listeInt);
	affichageSansItera(listeInt);

}

void remplirVectorInt(vector <int> &listeInt, size_t nombreSaisie)
{
	int valeur = 0;
	cout << "Entrez 5 elements dans la liste d'entier " << endl;
	for (size_t index = 0; index < nombreSaisie; index++)
	{
		cout << index + 1 << "  |--> ";
		cin >> listeInt[index];
	}
}
void affichageSansItera(vector <int> const& listeInt)
{
	for (size_t index = 0; index < listeInt.size(); index++)
	{
		cout << "-- " << listeInt[index];
	}
	cout << endl;
}
void supprimeElement(vector <int> & listeInt, int debut, int fin)
{
	vector<int>::iterator myIterator;
	int valeur = -1;
	do
	{
		cout << "Entrer un entier compris entre " << debut << " et " << fin << " --> : ";
		cin >> valeur;
	} while (valeur < debut || valeur > fin);
	if (valeur != -1)
	{
		myIterator = listeInt.begin() + valeur;
		listeInt.erase(myIterator);
	}

}
void insererElement(vector <int> & listeInt, int debut, int fin)
{
	vector<int>::iterator myIterator;
	int valeurA = -1;
	int valeurB = 0;
	do
	{
		cout << "Entrer un entier compris entre " << debut << " et " << fin << " --> : ";
		cin >> valeurA;
		cout << "Entrer une Nouvelle Valeur a inserer --> :";
		cin >> valeurB;
	} while (valeurA < debut || valeurA > fin);
	if (valeurA != -1)
	{
		myIterator = listeInt.begin() + valeurA;
		listeInt.insert(myIterator, valeurB);

	}
}
void viderliste(vector <int> & listeInt)
{
	listeInt.clear();
}

void affichageAvecItera(vector <int> & listeInt)
{
	vector<int>::iterator myIterator;
	for (myIterator = listeInt.begin(); myIterator != listeInt.end(); myIterator++)
	{
		cout << "|- " << *myIterator;
	}

}