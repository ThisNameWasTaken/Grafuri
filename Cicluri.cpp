#include <iostream>
#include <vector>

using namespace std;


class Graf
{
public:
	Graf(const vector<vector<int>>& listaAdiacenta, const int& nrNoduri = -1);
	~Graf();

	bool eCiclic();
	bool eCiclic_Implementare(const int& nod, vector<bool>& eVizitat, const int& parinte = -1);

private:
	vector<vector<int>> listaAdiacenta;
	int nrNoduri;
};

Graf::Graf(const vector<vector<int>>& listaAdiacenta, const int& nrNoduri) {
	nrNoduri != -1 ? this->nrNoduri = nrNoduri : this->nrNoduri = listaAdiacenta.size();
	this->listaAdiacenta = listaAdiacenta;
}

Graf::~Graf() {

}

bool Graf::eCiclic()
{
	vector<bool> eVizitat;
	eVizitat.resize(this->nrNoduri);
	for (int i = 0; i < this->nrNoduri; i++) {
		eVizitat[i] = false;
	}

	for (int i = 0; i < nrNoduri; i++) {
		if (!eVizitat[i]) {
			if (eCiclic_Implementare(i, eVizitat, -1)) {
				return true;
			}
		}
	}

	return false;
}

bool Graf::eCiclic_Implementare(const int& nod, vector<bool>& eVizitat, const int& parinte)
{
	eVizitat[nod] = true;

	for (const int& vecin : this->listaAdiacenta[nod]) {
		if (!eVizitat[vecin]) {
			if (eCiclic_Implementare(vecin, eVizitat, nod)) {
				return true;
			}
		}
		else if (vecin != parinte) {
			return true;
		}
	}

	return false;
}

int main() {
	int nrNoduri1 = 5;
	vector<vector<int>> listaAdiacenta1;
	listaAdiacenta1.resize(nrNoduri1);

	listaAdiacenta1[1].push_back(0);
	listaAdiacenta1[0].push_back(1);
	listaAdiacenta1[1].push_back(2);
	listaAdiacenta1[2].push_back(1);
	listaAdiacenta1[2].push_back(0);
	listaAdiacenta1[0].push_back(2);
	listaAdiacenta1[3].push_back(0);
	listaAdiacenta1[0].push_back(3);
	listaAdiacenta1[3].push_back(4);
	listaAdiacenta1[4].push_back(3);

	Graf graf1(listaAdiacenta1);

	graf1.eCiclic() ? cout << "E ciclic\n" : cout << "Nu e ciclic\n";

	int nrNoduri2 = 3;
	vector<vector<int>> listaAdiacenta2;
	listaAdiacenta2.resize(nrNoduri2);

	listaAdiacenta2[1].push_back(0);
	listaAdiacenta2[0].push_back(1);
	listaAdiacenta2[2].push_back(1);
	listaAdiacenta2[1].push_back(2);

	Graf graf2(listaAdiacenta2, nrNoduri2);

	graf2.eCiclic() ? cout << "E ciclic\n" : cout << "Nu e ciclic\n";

	system("pause");
	return 0;
}