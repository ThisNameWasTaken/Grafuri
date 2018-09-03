__Input__: Un graf ponderat, fara ponderi negative, si un nod sursa.

__Ouput__: Cea mai scurta cale de la nodul sursa la celelalte noduri ale grafului.

__Descriere__: Fiecarui varf `i` se asociaza o valoare care reprezinta costul minim
de la nodul de start la nodul curent.

__Pseudocod__:
```python
    pentru_fiecare nod din graf.noduri:
        cost[nod] = INF
        tata[nod] = -1

    cost[nodSursa] = 0

    noduriDeVeizitat(graf.noduri) // min-heap

    cat_timp !noduriDeVeizitat.eGol():
        nod = noduriDeVeizitat.pop()
        pentru_fiecare vecin din graf.vecini(nod):
            daca cost[nod] + cost[nod][vecin] < cost[vecin]:
                cost[vecin] = cost[nod] + cost[nod][vecin]
                tata[vecin] = nod
                reheap(noduriDeVeizitat)
```

__Corectitudine__: La fiecare pas algoritmul selecteaza un drum optim, de la nodul
sursa la nodul curent, care este actualizat in cazul in care costul gasit pana
atunci este mai mare decat costul nodului curent + costul pana la tatal lui.

__Timp de rulare__: `O(m * log n)` cu `min-heap`
