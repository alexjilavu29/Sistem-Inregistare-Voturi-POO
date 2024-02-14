# Sistem de Votare în C++

## Descriere
Acest proiect C++ implementează un sistem de votare, demonstrând aplicarea principiilor Programării Orientate pe Obiect (POO) prin utilizarea mostenirii, abstractizării, polimorfismului și încărcării operatorilor.

## Caracteristici Principale
- **Clasa Abstractă `Partid`**: Servește drept bază pentru diferite tipuri de partide politice, folosind mostenirea și metode virtuale.
- **Citire și Afisare**: Implementate prin clase dedicate (`Citire`, `Afisare`) care suprascriu operatorii de input (`>>`) și output (`<<`).
- **Polimorfism**: Demonstrat prin metode virtuale care sunt suprascrise în clase derivate.
- **Încărcarea Operatorilor**: Exemplificată prin suprascrierea operatorilor de adunare pentru a adăuga voturi la partide.

## Utilizare
- Crearea instanțelor de partide și manipularea acestora prin metodele specificate.
- Interacțiunea cu utilizatorul pentru citirea datelor de la consolă și afișarea rezultatelor.

## Exemplu de Cod
```cpp
Partid* p1 = new Partid_definit1("PSD", 10000);
Partid* p2 = new Partid_definit2("PNL", 20000);
vector<Partid*> Partide{ p1,p2 };
afisare2(Partide);
```

## Contribuții
Contribuțiile sunt binevenite pentru extinderea și îmbunătățirea sistemului de votare.
