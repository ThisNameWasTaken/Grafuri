__Input__: Un graf conex ponderat.

__Output__: Un arbore partial de cost minim.

__Descriere__: Se sorteaza descrescator muchiile dupa cost.
Se adauga muchia curenta din vectorul de muchii sortat
dupa cost, daca nu formeaza un ciclu, altfel se trece
la urmatoare muchie. Se repeta pasul precedent pana se
obtin `n-1` muchii.

__Pseudocod__:
```python
    sorteaza(muchii)
    pentru_fiecare muchie din muchii:
        daca !(arboreDeCostMinim + muchie).areCiclu():
            arbore += muchie
```

__Corectitudine__: 
    Pas initial: toate nodurile sunt izolate, fiecare
    formand co componenta conexa.

    Pas oarecare: muchiile deja selectate formeaza una
    sau mai multe componente conexe. Muchia selectata
    la pasul curent este muchia de cost minim care 
    uneste doua componente conexe diferite, motiv pentru
    care se va obtine un arbore partial de cost minim.

__Complexitate__:
    <code>O(m * log n + n<sup>2</sup>)</code>
    `m * log n` - sortarea muchiilor dupa cost
    <code>n<sup>2</sup></code> - concatenarea a doua componente conexe

__Structura__:
    Folosim un vector de reprezentanti.