// Program to find Dijkstra's shortest path using
// priority_queue in STL
#include<iostream>
#include<limits.h>
#include<map>
#include<list>
#include<queue>

using namespace std;

# define INF INT_MAX

// This class represents a directed graph using
// adjacency list representation
class Graf
{
public:
	Graf(int V);  // Constructor

				   // function to add an edge to graph
	void adaugaMuchie(int u, int v, int cost);

	// prints shortest path from s
	void Dijsktra(const int& nodSursa = 0);

private:
	int nrNoduri;    // No. of vertices

			  // In a weighted graph, we need to store vertex
			  // and weight pair for every edge
	list<pair<int, int>> *listaAdiacenta;
};

// Allocates memory for adjacency list
Graf::Graf(int nrNoduri)
{
	this->nrNoduri = nrNoduri;
	listaAdiacenta = new list<pair<int, int>>[nrNoduri];
}

void Graf::adaugaMuchie(int u, int v, int cost)
{
	listaAdiacenta[u].push_back(make_pair(v, cost));
	listaAdiacenta[v].push_back(make_pair(u, cost));
}

// Prints shortest paths from src to all other vertices
void Graf::Dijsktra(const int& nodSursa)
{
	// Create a priority queue to store vertices that
	// are being preprocessed. This is weird syntax in C++.
	// Refer below link for details of this syntax
	// http://geeksquiz.com/implement-min-heap-using-stl/
	priority_queue< pair<int, int>, vector <pair<int, int>>, greater<pair<int, int>> > distanta;
	
	// Create a vector for distances and initialize all
	// distances as infinite (INF)
	vector<int> nodDestiantie(nrNoduri, INF);

	// Insert source itself in priority queue and initialize
	// its distance as 0.
	distanta.push(make_pair(0, nodSursa));
	nodDestiantie[nodSursa] = 0;

	/* Looping till priority queue becomes empty (or all
	distances are not finalized) */
	while (!distanta.empty())
	{
		// The first vertex in pair is the minimum distance
		// vertex, extract it from priority queue.
		// vertex label is stored in second of pair (it
		// has to be done this way to keep the vertices
		// sorted distance (distance must be first item
		// in pair)
		int u = distanta.top().second;
		distanta.pop();

		// 'i' is used to get all adjacent vertices of a vertex
		list< pair<int, int> >::iterator i;
		for (i = listaAdiacenta[u].begin(); i != listaAdiacenta[u].end(); ++i)
		{
			// Get vertex label and weight of current adjacent
			// of u.
			int v = (*i).first;
			int weight = (*i).second;

			//  If there is shorted path to v through u.
			if (nodDestiantie[v] > nodDestiantie[u] + weight)
			{
				// Updating distance of v
				nodDestiantie[v] = nodDestiantie[u] + weight;
				distanta.push(make_pair(nodDestiantie[v], v));
			}
		}
	}

	// Print shortest distances stored in dist[]
	cout << "Vertex   Distance from Source\n";
	for (int i = 0; i < nrNoduri; ++i) {
		cout << "  " << i << "\t\t " << nodDestiantie[i] << endl;
	}
}

// Driver program to test methods of graph class
int main()
{
	// create the graph given in above fugure
	int nrNoduri = 9;
	Graf g(nrNoduri);

	//  making above shown graph
	g.adaugaMuchie(0, 1, 4);
	g.adaugaMuchie(0, 7, 8);
	g.adaugaMuchie(1, 2, 8);
	g.adaugaMuchie(1, 7, 11);
	g.adaugaMuchie(2, 3, 7);
	g.adaugaMuchie(2, 8, 2);
	g.adaugaMuchie(2, 5, 4);
	g.adaugaMuchie(3, 4, 9);
	g.adaugaMuchie(3, 5, 14);
	g.adaugaMuchie(4, 5, 10);
	g.adaugaMuchie(5, 6, 2);
	g.adaugaMuchie(6, 7, 1);
	g.adaugaMuchie(6, 8, 6);
	g.adaugaMuchie(7, 8, 7);

	g.Dijsktra();

	system("pause");
	return 0;
}