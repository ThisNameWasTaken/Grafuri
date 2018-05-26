#include <iostream>
#include <vector>
#include <queue>

using namespace std;

enum class Culoare { Necolorat, Rosu, Albastru };

class Graf
{
public:
	Graf(const vector<vector<int>>& listaAdiacenta);
	~Graf();

	bool eBipartit();
	bool eBipartit_Implementare(const int& nodSursa, vector<Culoare>& culoare);

private:
	vector<vector<int>> listaAdiacenta;
	int nrNoduri;
};

Graf::Graf(const vector<vector<int>>& listaAdiacenta) {
	this->nrNoduri = listaAdiacenta.size();
	this->listaAdiacenta = listaAdiacenta;
}

Graf::~Graf() {

}

bool Graf::eBipartit() {
	// Vector de culori in care, la inceput, nodurile nu sunt colorate
	vector<Culoare> culoare;
	culoare.resize(this->nrNoduri);
	for (int nod = 0; nod < this->nrNoduri; nod++) {
		culoare[nod] = Culoare::Necolorat;
	}

	// Trecem prin toate nodurile
	for (int nod = 0; nod < this->nrNoduri; nod++) {
		// Daca nodul nu a fost colorat
		if (culoare[nod] == Culoare::Necolorat) {
			if (!eBipartit_Implementare(nod, culoare)) {
				return false;
			}
		}
	}

	return true;
}

bool Graf::eBipartit_Implementare(const int & nodSursa, vector<Culoare>& culoare) {
	culoare[nodSursa] = Culoare::Albastru;

	queue<int> noduriDeVizitat;
	noduriDeVizitat.push(nodSursa);

	while (!noduriDeVizitat.empty()) {
		const int& nod = noduriDeVizitat.front();

		for (const int& vecin : listaAdiacenta[nod]) {
			// Daca vecinul nu a fost colorat
			if (culoare[vecin] == Culoare::Necolorat) {
				// Il coloram
				culoare[vecin] = culoare[nod] == Culoare::Albastru ? Culoare::Rosu : Culoare::Albastru;
				noduriDeVizitat.push(vecin);
			} else if (culoare[vecin] == culoare[nod] && vecin != nod) { // Daca vecinul este colorat si are aceeasi culoare ca si nodul curent
				return false; // Nu e bipartit
			}
			
		}

		noduriDeVizitat.pop(); // Treci la urmatorul nod
	}

	return true;
}

int main() {
	const int nrNoduri = 4;
	vector<vector<int>> listaAdiacenta;
	listaAdiacenta.resize(nrNoduri);

	listaAdiacenta[0].push_back(1);
	listaAdiacenta[0].push_back(3);
	listaAdiacenta[1].push_back(0);
	listaAdiacenta[1].push_back(2);
	listaAdiacenta[2].push_back(1);
	listaAdiacenta[2].push_back(3);
	listaAdiacenta[3].push_back(0);
	listaAdiacenta[3].push_back(1);

	Graf graf(listaAdiacenta);

	graf.eBipartit() ? cout << "E bipartit\n" : cout << "Nu e bipartit\n";

	system("pause");
	return 0;
}