#include <iostream>	
#include <vector>
#include <queue>

using namespace std;

class Graf {
public:
	Graf(const vector<vector<int>>& listaAdiacenta) {
		this->listaAdiacenta = listaAdiacenta;
		this->nrNoduri = listaAdiacenta.size();
	}

	void BFS(const int& nodSursa = 0) {
		// Vector de noduri vizitate (toate sunt nevizitate la inceput)
		vector<bool> eVizitat;
		eVizitat.resize(nrNoduri);
		for (int nod = 0; nod < nrNoduri; nod++) {
			eVizitat[nod] = false;
		}

		// Coada in care adaug nodurile care mai trebuie vizitate
		queue<int> noduriDeVizitat;
		noduriDeVizitat.push(nodSursa);
		eVizitat[nodSursa] = true;

		// Cat timp mai avem noduri de vizitat 
		while (!noduriDeVizitat.empty()) {
			const int nod = noduriDeVizitat.front();

			// Afisam nodul
			cout << nod + 1 << " ";

			// Vizitam toti vecinii nevizitati ai nodului curent
			for (const int& vecin : listaAdiacenta[nod]) {
				if (!eVizitat[vecin]) {
					noduriDeVizitat.push(vecin);
					eVizitat[vecin] = true;
				}
			}

			noduriDeVizitat.pop();
		}
	}

	void DFS(const int& nodSursa = 0) {
		vector<bool> eVizitat;
		eVizitat.resize(nrNoduri);
		for (int nod = 0; nod < nrNoduri; nod++) {
			eVizitat[nod] = false;
		}

		DFS_Implementare(nodSursa, eVizitat);
	}

private:
	void DFS_Implementare(const int& nod, vector<bool>& eVizitat) {
		cout << nod + 1 << " ";

		eVizitat[nod] = true;

		for (const int& vecin : listaAdiacenta[nod]) {
			if (!eVizitat[vecin]) {
				DFS_Implementare(vecin, eVizitat);
			}
		}
	}

	vector<vector<int>> listaAdiacenta;
	int nrNoduri;
};

int main() {
	const int nrNoduri = 5;
	vector<vector<int>> listaAdiacenta;
	listaAdiacenta.resize(nrNoduri);

	listaAdiacenta[0].push_back(1);
	listaAdiacenta[0].push_back(2);
	listaAdiacenta[1].push_back(2);
	listaAdiacenta[2].push_back(0);
	listaAdiacenta[2].push_back(3);
	listaAdiacenta[3].push_back(3);

	Graf graf(listaAdiacenta);

	graf.BFS(); cout << endl;
	graf.BFS(2); cout << endl;

	graf.DFS(); cout << endl;
	graf.DFS(2); cout << endl;

	system("pause");
	return 0;
}