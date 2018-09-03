__Input__: Graf conex ponderat.

__Output__: Arbore partial de cost minim.

__Descriere__: Se porneste de la un nod oarecare, la fiecare
pas este selectata o muchiie de cost minim, de la nodul
deja existent in arborele de cost minim la un nod care nu
a fost inca adaugat. Se adauga nodul si muchia respectiva
in arbore.

__Pseudocod__:
```python
    cat_timp !noduriDeAdaugat.eGol():
            nodDeAdaugat = noduriDeAdaugat[noduriDeAdaugat.lungime - 1]
            pentru_fiecare nod din arboreDeCostMinim.noduri:
                daca cost[nod][nodDeAdaugat] < costMin[nod][nodDeAdaugat]:
                    costMin[nod][nodDeAdaugat] = cost[nod][nodDeAdaugat]
            arboreDeCostMinim.adauga(costMin[nod][nodDeAdaugat])
            nodDeAdaugat.pop()
```

__Corectitudine__: La fiecare pas se adauga o muchie de cost minim intre
un nod din arbore si unul neinclus inca in arbore, astfel nu se formeaza
cicluri, pana cand toate varfurile sunt atinse.

__Complexitate__: <code> O(n<sup>2</sup>)</code> - `folosim Set`