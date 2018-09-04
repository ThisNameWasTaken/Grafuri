__Input__: Graf conex ponderat.

__Output__: Arbore partial de cost minim.

__Descriere__: Se porneste de la un nod `s`, la fiecare
pas este selectata o muchie de cost minim, de la nodul
deja existent in arbore la un nod care nu a fost inca adaugat. Se adauga nodul si muchia respectiva in arbore.

__Pseudocod__:
```python
    pentru_fiecare nod din noduri:
        cost[nod] = INF
        tata[nod] = 0

    cost[nodStart] = 0

    noduriDeVizitat = PriorityQueue(noduri)

    cat_timp !noduriDeVizitat.eGol():
        nod = noduriDeVizitat.pop() // extrage minimul
        pentru_fiecare vecin din vecini[nod]:
            daca cost[nod][vecin] < cost[vecin]:
                cost[vecin] = cost[nod][vecin]
                tata[vecin] = nod
    
    pentru_fiecare nod din noduri
        daca nod != nodStart:
            afiseaza nod, tata[nod]
```

__Corectitudine__: La fiecare pas se adauga o muchie de cost minim intre un nod din arbore si unul neinclus inca in arbore, astfel nu se formeaza cicluri, pana cand toate varfurile sunt atinse.

__Complexitate__: <code> O(m * log n)</code> - folosim `priority queue`

__Structura__:
- Memoram componentele conexe folosind un vector de tati.
- Retinem nodurile grafului intr-o coada de prioritati sortata dupa cost.