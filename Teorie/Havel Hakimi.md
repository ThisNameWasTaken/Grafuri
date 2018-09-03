__Input__: O secventa de grade, fiecare grad < nr de noduri.

__Output__: Verificare daca secventa data este sau nu un graf.

__Descriere__: Se ordoneaza secventa de grade descrescator. Din
valoarea maxima si din urmatoarele elemente ale 
vectorului se scade pe rand cate `1`, pana valoarea de pe prima
pozitie devine `0` sau pana se ajunge la finalul vectorului. Daca
valoarea primului element din vector ajunge sa fie `0` atunci
continuam pana cand toate elementele din vector sunt `0`, caz
in care secventa data poate forma un graf. Daca am ajuns la
finalul vectorului, iar pe prima pozitie valoarea este nevida,
atunci secventa data NU poate forma un graf. Daca in vector avem
elemente negative, atunci secventa data NU poate forma un graf.

__Pseudocod__:
```python
    pentru_fiecare grad din grade:
            daca gard >= nrNoduri:
                scrie "NU"
                returneaza 0
            sumaGrade += grad

        sorteaza(grade, descrescator)

        cat_timp !grade.eGol():
            pentru i = 1, grade[0] > 0 && i < grade.lungime, i++:
                grade[0]--
                grade[i]--
                daca grade[i] < 0:
                    scrie "NU"
                    returneaza 0
            grade.sort()
            cat_timp !grade[grade.lungime - 1]:
                grade.pop()
```

__Corectitudine__: Pentru un graf de `N` noduri daca se mai adauga
un nod de grad `N+1` si cresc gradul celorlalte noduri cu `1`,
secventa ramane grafica.

__Complexitate__:
    <code>O(n<sup>2</sup> * log n)</code>
    `n * log n` - sortare la fiecare pas
    `n` - sunt `n` elemente in lista de grade