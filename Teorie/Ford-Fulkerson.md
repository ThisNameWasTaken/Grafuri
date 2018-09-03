__Input__: O retea, un nod sursa si un nod destinatie.

__Output__: Fluxul maxim de la nodul sursa la nodul destinatie.

__Descriere__: La un pas oarecare este rezultat un flux (nesaturat) pe un
lant de la nodul sursa la nodul destinatie. Se repeta pasul precedent pana
se obtine un flux saturat.

__Pseudocod__:
```python
    flux(0) // flux gol

        cat_timp "exista lant nesaturat de la `nodSursa` la `nodDestiantie`":
            lant = gasesteLant(nodSursa, nodDestiantie)
            revizuieste(flux, lant)

        returneaza flux
```

__Corectitudine__: Daca la fiecare pas lanturile nesaturate se satureaza, se
realizeaza o impartire a nodurilor in doua multimi, in intesersectia lor
regasindu-se chiar muchiile staturate de trecere. 

__Complexitate__: `O(m * C)`
                   `C` - capacitatea taieturii minime