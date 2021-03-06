## Graf orientat
O pereche de multimi `G = (V, E)` unde `V` este multimea varfurilor
si `E ⊆ VxV` este multimea arcelor (multime de perechi ordonate).

## Graf neorientat
O pereche de multimi `G = (V, E)` unde `V` este multimea varfurilor
si `E ⊆ VxV` este multimea muchiilor (multime de perechi neordonate).

## Multiset
Multime in care se pot repeta elementele.<br/>
Fie `S` o multime finita nevida, fiecarui element din `S` ii atasam un ordin de multiplicitate.<br/>
`M = (S, r)` unde `r:S->N` este functia de multiplicitate.<br/>
_Notatie_: <code>R = (x<sup>r</sup>|x∊S)</code><br/>
_Exemplu_:
<pre>
<code>S = {2, 3, 5, 7}
R = {2<sup>3</sup>, 3<sup>1</sup>, 5<sup>2</sup>, 7<sup>4</sup>}
|R| = 10 Suma multiplicitatilor(3 + 1 + 2 + 4)
</code>
</pre>

## Adiacenta
Doua varfuri `a` si `b` sunt adiacente daca
sunt extremitati ale aceleiasi muchii.

## Incidenta
Doua muchii sunt incidente daca daca au
o extremitate (nod) comun.

## Graf partial
Un graf partial al unui graf `G` se obtine
prin eliminarea unor muchii din `G`.

## Subgraf
Un subgraf al unui graf `G` se obtine prin
eliminarea unor noduri, si muchiilor adiacente acestora,
din `G`.

## Grad
Gradul unui nod este egal cu numarul muchiilor
incidente cu acesta.

## Grad interior
Gradul interior unui nod este egal cu 
numarul muchiilor care vin spre acesta. <code>d<sub>G</sub><sup>-</sup>(nod)</code>

## Grad exterior
Gradul exterior unui nod este egal cu
numarul muchiilor care pleaca din acesta. <code>d<sub>G</sub><sup>+</sup>(nod)</code>

## Multisetul gradelor interioare
<code>s<sup>-</sup>(G) = {d<sub>G</sub><sup>-</sup>(v<sub>1</sub>), d<sub>G</sub><sup>-</sup>(v<sub>2</sub>), d<sub>G</sub><sup>-</sup>(v<sub>3</sub>), ..., d<sub>G</sub><sup>-</sup>(vn)}</code><br/>
_Exemplu_:
<code>s<sup>-</sup>(G) = {3, 2, 1, 1, 1, 2} = {1<sup>3</sup>, 2<sup>2</sup>, 3}</code>

## Multisetul gradelor exterioare
<code>s<sup>+</sup>(G) = {d<sub>G</sub><sup>+</sup>(v<sub>1</sub>), d<sub>G</sub><sup>+</sup>(v<sub>2</sub>), d<sub>G</sub><sup>+</sup>(v<sub>3</sub>), ..., d<sub>G</sub><sup>+</sup>(vn)}</code><br/>
_Exemplu_:
<code>s<sup>+</sup>(G) = {1, 2, 2, 1, 2, 2} = {1<sup>2</sup>, 2<sup>4</sup>}</code>

## Nod izolat
Nod cu gradul `0`.

## Nod terminal
Nod cu gradul `1`.

## Graf complet
Graf in care oricare doua noduri sunt
adiacente.

## Drum
O succesiune de noduri cu proprietatea ca intre oricare
doua noduri exista un arc.

## Drum elementar
Drum in care toate varfurile sunt distincte.

## Circuit
Drum in care unul sau mai multe noduri nod apar
de mai multe ori.

## Circuit elementar
Circuit in care toate nodurile sunt distincte
cu exceptia primului si a ultimului.

## Lant
O succesiune de noduri cu proprietatea ca oricare
doua sunt adiacente.

## Lant elementar
Lant in care toate varfurile sunt distincte.

## Ciclu
Lant in care unul sau mai multe noduri nod apar
de mai multe ori. Lant in care extremitatile lantului
au o muchie intre ele.

## Ciclu elementar
Ciclu in care toate nodurile sunt distincte
cu exceptia primului si a ultimului.

## Graf aciclic maximal
Graf in care prin adaugarea oricarei
muchii se obtine un graf cu cel putin un ciclu.

## Costul unei muchii
Valoarea asociata (parcurgerii)
unei muchii dintr-un graf.

## Graf ponderat
Graf in care fiecarei muchii ii este 
asociata un cost.

## Costul unui graf
Suma costurilor muchiilor sale.

## Grafuri izomorfe

## Definitie 1
Doua grafuri sunt izomorfe daca
au acelasi numar de varfuri si se pot obtine unul din
celalalt printr-o renumerotare a varfurilor.

## Definitie 2
Doua grafuri <code>G<sub>1</sub>(V<sub>1</sub>, E<sub>1</sub>)</code> si <code>G<sub>2</sub>(V<sub>2</sub>, E<sub>2</sub>)</code>
sunt izomorfe daca exista o functie bijectiva de la <code>V<sub>1</sub></code>
la <code>V<sub>2</sub></code> ai pentru orice pereche `(a, b)` din E1 exista o 
pereche `(f(a), f(b))` in <code>E<sub>2</sub></code>.

## Graf complementar
Un graf `G'` este complementar lui `G`
daca oricare doua varfuri din `G'` care sunt adiacente
ele nu sunt adiacente in `G`.

## Graf bipartit
Un graf in care multimea nodurilor (`V`)
poate fi impartita in doua submultimi disjuncte 
(<code>V<sub>1</sub></code> si <code>V<sub>2</sub></code>) cu proprietatea ca orice muchie din graf 
uneste un nod din prima multime (<code>V<sub>1</sub></code>) cu unul din a
doua multime (<code>V<sub>2</sub></code>).

## Graf conex
Graf in care intre oricare doua noduri
exista un lant.

## Graf conex minimal
Graf conex in care daca se
elimina orice muchie se obtine un graf neconex.

## Arbore
Un graf conex neorientat si fara cicluri.<br/>
_Prorietati:_
- un arbore este un graf conex minimal
- un arbore este un graf aciclic maximal
- un arbore cu `n` varfuri are `n-1` muchii

## Arbore partial
Graf partial care este si arbore.

## Arbore partial de cost minim
Arbore partial in care suma costurilor muchiilor care il formeaza sa fie minim posibila.

## Retea de transport
O structura `N = (G, S, T, I, c)` unde:
  - `G = (V, E)` este un graf orientat cu `V = S ∪ I ∪ T`, unde `S`, `I`, `T` sunt multimi disjuncte, nevide,
  cu semnificatia:
    * `S` - multimea surselor (intrarilor)
    * `T` - multimea destinatiilor (iesirilor)
    * `I` - multimea varfurilor intermediare
  - `c:E->N` este functia capacitate, cu semnificatia: `c(e)` = cantitatea maxima care poate fi
  transportata prin arcul `e`.
  
## Flux
Fie o retea de transport `N = (G, s, t, I, c)` cu prorietatea: <code>d<sup>−</sup>(s) = d<sup>+</sup>(t) = 0)</code>.
Un flux ın `N` este o functie `f : E -> N` cu proprietatile:
1. `0 <= f(e) <= c(e)`, `∀e ∈ E(G)` - conditia de marginire
2. pentru orice varf intermediar `v ∈ I`, fluxul (total) care intra ın varful `v` este egal cu fluxul (total)
care iese din varful `v` - conditia de conservare a fluxului:
<pre>
 &Sigma; f(uv) = &Sigma; f(vu),
<sup>uv∈E</sup>       <sup>vu∈E</sup>
</pre>
## Cuplaj
Un cuplaj ıntr-un graf neorientat `G(E, V)` este o multime de muchii `M ⊆ E` neadiacente doua
cate doua.
