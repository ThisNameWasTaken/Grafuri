#include <iostream>
#include <list>
#include <stack>
#include <vector>

using namespace std;

class Graf {
public:
	Graf(const int& nrNoduri, const vector<vector<int>>& listaAdiacenta) {
		this->nrNoduri = nrNoduri;
		this->listaAdiacenta = listaAdiacenta;
	}

	void sortareTopologica() {
		stack<int> noduriSortate;

		vector<bool> eVizitat;
		eVizitat.resize(nrNoduri);
		for (bool element : eVizitat) {
			element = false;
		}

		for (int i = 0; i < nrNoduri; i++) {
			if (!eVizitat[i]) {
				sortareTopologica_Implementare(i, eVizitat, noduriSortate);
			}
		}

		while (!noduriSortate.empty()) {
			cout << noduriSortate.top() << " ";
			noduriSortate.pop();
		}
	}

protected:
	void sortareTopologica_Implementare(const int& nod, vector<bool>& eVizitat, stack<int>& noduriSortate) {
		eVizitat[nod] = true;
		for (const int& vecin : listaAdiacenta[nod]) {
			if (!eVizitat[vecin]) {
				sortareTopologica_Implementare(vecin, eVizitat, noduriSortate);
			}
		}

		noduriSortate.push(nod);
	}

private:
	vector<vector<int>> listaAdiacenta;
	int nrNoduri;
};

int main() {
	int nrNoduri = 6;
	vector<vector<int>> listaAdiacenta;
	listaAdiacenta.resize(nrNoduri);

	listaAdiacenta[5].push_back(2);
	listaAdiacenta[5].push_back(0);
	listaAdiacenta[4].push_back(0);
	listaAdiacenta[4].push_back(1);
	listaAdiacenta[2].push_back(3);
	listaAdiacenta[3].push_back(1);

	Graf graf(nrNoduri, listaAdiacenta);

	graf.sortareTopologica();

	system("pause");
	return 0;
}