#include <iostream>
#include <vector>     // std::vector<T>()
#include <functional> // std::greater<T>()
#include <algorithm>  // std::sort()

using namespace std;

bool eCeTrebe(vector<int> grade) {
	// Sortam vectorul de grade in ordine descrescatoare.
	sort(grade.begin(), grade.end(), greater<int>());

	// Cat timp avem elemente in vector.
	while (grade.size()) {
		// Incercam sa scadem cate `1` din valoarea primului nod (`grade[0]`)
		// si cate `1` din valoarea urmatoarelor `grade[0]` noduri.
		for (int i = 1; grade[0] && i < grade.size(); i++) {
			// Scadem `1` dintr-un grad numai daca acesta este diferit de `0`.
			if (grade[i]) {
				grade[i]--;
				grade[0]--;
			}
		}

		// Daca nu am reusit sa facem gradul primului element `0`,
		// secventa data nu poate forma un graf
		if (grade[0]) {
			return false;
		}

		// Sortam vectorul de grade in ordine descrescatoare. (in caz ca am stricat ordinea)
		sort(grade.begin(), grade.end(), greater<int>());

		// Eliminam toate elementele nule
		while (grade.size() && !grade[grade.size() - 1]) {
			grade.pop_back();
		}
	}

	return true;
}

int main() {
	vector<int> grade({ 5, 2, 4, 6, 5, 5, 4, 7 });
	vector<int> grade1({ 4, 2, 5, 1, 3 });
	vector<int> grade2({ 2, 1, 3, 3, 2, 3 });
	vector<int> grade3({ 5, 6, 1, 8, 3, 4, 5, 3, 4, 2 });
	vector<int> grade4({ 0, 0, 0, 0 });

	cout << eCeTrebe(grade) << endl;
	cout << eCeTrebe(grade1) << endl;
	cout << eCeTrebe(grade2) << endl;
	cout << eCeTrebe(grade3) << endl;
	cout << eCeTrebe(grade4) << endl;

	system("pause");
	return 0;
}