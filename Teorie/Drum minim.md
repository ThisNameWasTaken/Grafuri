__Input__: Graf orientat ponderat fara circuite.

__Output__: Drumuri minime in graf de la un nod sursa.

__Descriere__: Fiecarui nod ii este asociat o eticheta care
reprezinta costul minim de la nodul sursa la nodul
respectiv. Folosim sortarea topologica pentru a calcula
valoarea acestui cost.

__Pseudocod__:
```python
    pentru_fiecare nod din graf.noduri:
            cost[nod] = INF
            tata[nod] = -1

        cost[nodSursa] = 0

        noduriSortateTopologic = sorteazaTopolgic(graf.noduri)

        pentru_fiecare nod din noduriSortateTopologic:
            pentru_fiecare vecin din vecini[nod]:
                daca cost[nod] + cost[nod][vecin] < cost[vecin]:
                    cost[vecin] = cost[nod] + cost[nod][vecin]
                    tata[vecin] = nod
```

__Corectitudine__: Are loc un rezultat asemanator
algoritmului lui Dijsktra.

__Complexitate__: `O(m + n)`