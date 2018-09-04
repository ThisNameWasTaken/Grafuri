__Input__: Un graf conex ponderat.

__Output__: Un arbore partial de cost minim al grafului.

__Descriere__: La un pas este selectată o muchie de cost minim din G
care nu formează cicluri cu muchiile deja selectate (care
unește două componente conexe din graful deja
construit).

__Pseudocod__:
```python
    pentru_fiecare nod din noduri:
        initializeaza(nod)

    sorteaza(muchii)

    pentru_fiecare muchie din muchii:
        daca gasesteRadacina(muchie.u) != gasesteRadacina(muchie.v):
            reuneste(muchie.u, muchie.v)

    initializeaza(nod):
        tata[nod] = inaltime[nod] = 0

    gasesteRadacina(nod):
        cat_timp tata[nod] != 0:
            nod = tata[nod]
        returneaza nod

    reuneste(nod1, nod2):
        radacina1 = gasesteRadacina(nod1)
        radacina2 = gasesteRadacina(nod2)

        daca inaltime[radacina1] > inaltime[radacina2]:
            tata[radacina2] = radacina1
        altfel:
            tata[radacina1] = radacina2
            daca inaltime[radacina1] == inaltime[radacina2]
                inaltime[radacina1] = inaltime[radacina1] + 1
```
__Corectitudine__:
- Pas initial: toate nodurile sunt izolate, fiecare formand o componenta conexa.

- Pas oarecare: muchiile deja selectate formeaza una sau mai multe componente conexe. Muchia selectata la pasul curent este muchia de cost minim care uneste doua componente conexe diferite, motiv pentru care se va obtine un arbore partial de cost minim.

__Complexitate__:
- <code>O(m * log n)</code>
- `m * log n` - sortarea muchiilor dupa cost

__Structura__:
- Folosim structuri pentru mulțimi disjuncte Union/Find.
- Memoram componentele conexe folosind un vector de tati. Reprezentantul componentei conexe va fi radacina arborelui.
- Reuniunea a doi arbori: radacina unui arbore devine fiu al radacinii celuilat arbore. Reuniunea se va face în functie de inaltimea arborilor, arborele cu inaltimea ce mai mica devine subarbore radacinii celuilalt arbore.