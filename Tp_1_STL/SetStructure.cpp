#include "SetStructure.h"


void utilisationSetStructure()
{
	/*
	Les attributs
	*/
	S_Coord ensCoord[10];
	set<S_Coord> setEnsCoord;
	

	/*
	Creation des 10 coordonnées
	*/
	for (size_t index = 0; index < 10; index++)
	{
		ensCoord[index].d_X =(rand()%(100-1)+1) + 1;
		ensCoord[index].d_Y = (rand() % (100 - 1) + 1) + 2;
		setEnsCoord.insert(ensCoord[index]);
	}

	affichageCoord(setEnsCoord);
	affichageDistanceEucludienne(distanceEucludienne(setEnsCoord));
	saisieUtlisateur(distanceEucludienne(setEnsCoord));

}
bool operator<(const S_Coord & s1, const S_Coord & s2)
{
	return s1.d_X < s2.d_X;
}

void affichageCoord(set<S_Coord> & ens)
{
	set<S_Coord>::iterator myIterator;
	for (myIterator = ens.begin(); myIterator != ens.end(); myIterator++)
	{
		cout << "|| " << myIterator->d_X << " , " << myIterator->d_Y << " ||" << endl;
	}

}
vector<vector<double>> distanceEucludienne(set<S_Coord> & ens)
{
	vector<vector<double>> vector2D(ens.size());
	set<S_Coord>::iterator myIterator;
	set<S_Coord>::iterator myIterator2;
	set<S_Coord>::iterator myIteratorTmp;
	size_t index;
	for (myIterator = ens.begin(), index = 0 ; myIterator != ens.end() , index < ens.size() ; myIterator++ , index ++)
	{
		myIteratorTmp = myIterator; 
		myIteratorTmp++;
		for (myIterator2 = myIteratorTmp ; myIterator2 != ens.end(); myIterator2++)
		{
			double valeurCalcule = sqrt(pow((myIterator2->d_X - myIterator->d_X ),2)+pow((myIterator2->d_Y - myIterator->d_Y),2));
			vector2D[index].push_back(valeurCalcule);
		}
	}

	return vector2D;
}
void affichageDistanceEucludienne(vector<vector<double>> & distance)
{
	for (size_t index = 0; index < distance.size() ; index++)
	{
		for (size_t index2 = 0; index2 < distance[index].size(); index2++)
		{
			cout << distance[index][index2]<<" --- ";
		}
		cout << endl;
	}
}
void saisieUtlisateur(vector<vector<double>> & distance)
{
	int pointA;
	int pointB;
	int tempPoint;
	cout << "Calule de la distance eucludienne  entre deux Point saisie " << endl;
	cout << "Saisie du 1er point : ";
	cin >> pointA;
	cout << "Saisie du 2 eme point : ";
	cin >> pointB;
	
	if (pointA > pointB)
	{
		tempPoint = pointA;
		pointA = pointB;
		pointB = tempPoint;
	}
	
	cout << "La distance entre le Point " << pointA << " et " << pointB << " est : " << distance[pointA - 1][pointB - 2];
	
}
