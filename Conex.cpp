#include <iostream>
#include <vector>

using namespace std;

class Graf {
public:
	Graf(const vector<vector<int>>& listaAdiacenta) {
		this->listaAdiacenta = listaAdiacenta;
		this->nrNoduri = listaAdiacenta.size();
	}

	void DFS(const int& nod, vector<bool>& eVizitat, const vector<vector<int>>& listaAdiacenta) {
		eVizitat[nod] = true;

		for (const int& vecin : listaAdiacenta[nod]) {
			if (!eVizitat[vecin]) {
				DFS(vecin, eVizitat, listaAdiacenta);
			}
		}
	}

	bool eConnex() {
		vector<bool> eVizitat;

		eVizitat.resize(this->nrNoduri);
		for (int nod = 0; nod < this->nrNoduri; nod++) {
			eVizitat[nod] = false;
		}

		DFS(0, eVizitat, this->listaAdiacenta);

		for (int nod = 0; nod < this->nrNoduri; nod++) {
			if(!eVizitat[nod]) {
				return false;
			}
		}

		eVizitat.resize(this->nrNoduri);
		for (int nod = 0; nod < this->nrNoduri; nod++) {
			eVizitat[nod] = false;
		}

		DFS(0, eVizitat, rastoarnaListaAdiacenta(this->listaAdiacenta));

		for (int nod = 0; nod < this->nrNoduri; nod++) {
			if (!eVizitat[nod]) {
				return false;
			}
		}

		return true;
	}

private:
	vector<vector<int>> rastoarnaListaAdiacenta(const vector<vector<int>>& listaAdiacenta) {
		vector<vector<int>> listaRasturanta;
		const int nrNoduri = listaAdiacenta.size();
		listaRasturanta.resize(nrNoduri);

		for (int nod = 0; nod < nrNoduri; nod++) {
			for (const int& vecin : listaAdiacenta[nod]) {
				listaRasturanta[vecin].push_back(nod);
			}
		}

		return listaRasturanta;
	}

	vector<vector<int>> listaAdiacenta;
	int nrNoduri;
};

int main() {
	const int nrNoduri1 = 5;
	vector<vector<int>> lista1;
	lista1.resize(nrNoduri1);

	lista1[0].push_back(1);
	lista1[1].push_back(2);
	lista1[2].push_back(3);
	lista1[3].push_back(0);
	lista1[2].push_back(4);
	lista1[4].push_back(2);

	Graf graf1(lista1);

	graf1.eConnex() ? cout << "E conex\n" : cout << "Nu e conex\n";

	const int nrNoduri2 = 4;
	vector<vector<int>> lista2;
	lista2.resize(nrNoduri2);

	lista2[0].push_back(1);
	lista2[1].push_back(2);
	lista2[2].push_back(3);

	Graf graf2(lista2);

	graf2.eConnex() ? cout << "E conex\n" : cout << "Nu e conex\n";

	system("pause");
	return 0;
}