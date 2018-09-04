__Input__: Un graf ponderat, fara ponderi negative, si un nod de start.

__Ouput__: Un vector de costuri, cu semnificatie `cost[x]` = costul de la `nodul de start` la nodul `x` si un vector de tati reprezentand un arbore al distantelor fata de `nodul de start`. Din vectorul de tati se poate determina drumul de cost minim la de `nodul de start`, la fiecare nod in parte.

__Descriere__: Fiecarui varf `u` se asociaza costul minim de la `nodul de start` pana la acel pas. La un pas este ales varful `u` care este estimat a fi cel mai aproape de `nodul de start` si se descopera noi drumuri catre vecinii lui 'u' actualizandu-se costurile acestora.

__Pseudocod__:
```python
    pentru_fiecare nod din noduri:
        cost[nod] = INF
        tata[nod] = 0

    cost[nodStart] = 0

    noduriDeVizitat = PriorityQueue(noduri) //  min-heap

    cat_timp !noduriDeVizitat.eGol():
        nod = noduriDeVizitat.pop() // extrage minimul
        pentru_fiecare vecin din vecini[nod]:
            daca cost[nod] + cost[nod][vecin] < cost[vecin]:
                cost[vecin] = cost[nod] + cost[nod][vecin]
                tata[vecin] = nod
    
    afiseaza cost, tata
```

__Corectitudine__:
1. Daca `P` este un drum minim de la `s` la `u`, atunci `P` este drum elementar.

2. Daca `P` este un drum minim de la `s` la `u` si `z` este un varf al lui `P`, atunci subdrumul lui `P` de la `s` la `z` este drum minim de la `s` la `z`. Mai general, daca `x` si `y` sunt doua varfuri din `P`, atunci subdrumul lui `P` de la `x` la `y` este drum minim de la `x` la `y`.

3. Fie `G = (V, E, w)` un graf orientat ponderat cu `w : E -> ℝ+` și `s ∈ V` fixat. La finalul algoritmul lui Dijkstra avem: <code>d[u] = &delta;(s, u)</code> pentru orice `u ∈ V` si `tata` memorează un arbore al distanțelor fata de `s`.

__Timp de rulare__: `O(m * log n)` cu `priority queue`

__Structura__:
- Memoram componentele conexe folosind un vector de tati.
- Retinem nodurile grafului intr-o coada de prioritati sortata dupa cost.
