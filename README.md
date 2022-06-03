# PA-Tema2

# 1. Curatare:
    Creez un vector pentru toate spatiile murdare gasite in casa
    si unul pentru toate spatiile unde sunt roboti. Urmatorul pas este
    sa calculez pentru fiecare punct in care am un spatiu murdar
    distantele de la acel punct la toate celelalte puncte de pe harta prin
    bfs, algoritm folosit in functia calc_distances.
    Retin intr-un 3D array toate aceste distante pentru fiecare punct
    murdar. Dupa ce am calculat aceste distante, generez prin functia
    backtracking toate posibilitatile de alocare a unui robot unui spatiu
    murdar. Pentru fiecare solutie obtinuta prin backtracking, calculez timpii
    in care fiecare robot ajunge la spatiile murdare asociate lui, iar in final
    compar aceste rezultate obtinute cu un minim global care se reactualizeaza atunci
    cand gasesc o posibila solutie, in care as avea un timp mai bun.
    Complexitate temporala: O(n^3);
    Complexitate spatiala: O(n^2).

# 3. Beamdrone:
    Calculez brin bfs distantele minime intre punctul de pornire
    si orice alt punct de pe harta care nu e perete, iar apoi returnez
    distanta calculata prin acest algoritm de la punctul de pornire la
    punctul de finish. Aceasta va reprezenta costul minim care se produce
    atunci cand vreau sa ajung de la punctul de coordonate (xi, yi) la
    punctul de coordonate (xf, yf).
    Complexitate temporala: O(n^2);
    Complexitate spatiala: O(n^2).

# 4. Curse:
    La fiecare pas din parcurgerea matricei citite voi compara 2 cate 2 linii
    si voi crea un graf orientat, astfel: Daca elementul de pe linia i si coloana j
    este diferit de elementul de pe linia i + 1 si coloana j, atunci
    adaug arcul de la elementul de coordonate (i, j) la elementul de
    coordonate (i + 1, j). Voi creste indicele coloanei cat timp
    nu gasesc 2 elemente diferite.
    Dupa ce am creat matricea de adiacenta conform metodei prezentate mai sus
    voi face o sortare topologica pentru graful creat, iar rezultatul obtinut
    in urma sortarii va fi rezultatul dorit.
    Complexitate temporala: O(n^2);
    Complexitate spatiala: O(m).
