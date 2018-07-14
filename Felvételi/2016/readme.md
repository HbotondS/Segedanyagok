# Felvételi, 2016 július
Hivatalból **1** pont jár. Munkaidő **3** óra.
## **Elmélet** (maximum 2 pont)
- Értelmezzük a típus és a változó fogalmát. Adjunk példákat! (Pascal vagy C/C++)
- Adjunk példákat változók értékeinek beolvasására és kiírására! (Pascal vagy C/C++)
---
## **Gyakorlat**
Megjegyzések:
 - A több alpontos feladatok esetén csak az egyik alpontot kell megoldani. Ha több alpontot is megoldana a felvételiző, akkor csak a legtöbbet érőre kapja meg a pontszámot.
 - A pszeudokód algoritmusban 
    - a "%" osztási maradékot jelent
    - a "-" osztási hányadost jelent
    - a "=" értékadást jelent
    - a "≠" különbözőségi vizsgálatot jelent
    - a "*" szorzást jelent
 - Minden egész érték eltárolható *integer/int* típusú változóban.
 - A programokat megjegyzésekkel kell ellátni!
1. **(maximum 1 pont)**
    1. Mit ír ki az alábbi pszeudokód algoritmus, ha az *n* értéke 18245? **(0,75 pont)**
        ````
         p = 1
        ┌amíg n ≠ 0 végezd
        │ m = n % 10
        │ n = n / 10
        │ p = p * m
        └■
         kiír p
        ````
    2. Adjunk példát olyan n értékre, melyre a fenti algoritmus eredménye 280! **(1 pont)**
2. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely
	1. a billentyűzetről beolvas két egész számot, és egy-egy üzenet kíséretében kiírja a képernyőre, hogy melyik a kisebb és melyik a nagyobb **(0,5 pont)**
	2. a billentyűzetről beolvas három egész számot, és egy-egy üzenet kíséretében
kiírja a képernyőre, hogy melyik a legkisebb és melyik a legnagyobb! Írjunk és
használjunk saját függvényt két érték összehasonlítására! **(0,75 pont)**
	3. a billentyűzetről beolvas egy n értéket (n>2), majd egy n elemű egész számokból álló számsorozatot, és növekvő sorrendben kiírja a képernyőre a számsorozat három legkisebb elemét, tömbök használata nélkül. **(1 pont)**
3. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely beolvas a billentyűzetről egy n természetes számot (n>0), majd egy n elemű, egész számokból álló számsorozatot! Számítsuk ki a számsorozat
	1. elemeinek összegét! **(0,75 pont)**
	2. elemei számjegyeinek összegét! **(1 pont)**
4. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely beolvas a billentyűzetről egy n természetes számot, és kiírja a képernyőre
	1. az 1, 2, 3, 4, …, n számsorozatot! **(0,5 pont)**
	2. az 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, … számsorozat első n elemét! **(1 pont)**
5. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely billentyűzetről beolvas egy n (1≤n≤100) természetes számot, majd n darab egész számpárt
	1. és kiírja a képernyőre azon számpárok számát, amelyek elemei azonosak! **(0,5 pont)**
	2. és egymás alatti sorokba, a beolvasás fordított sorrendjében kiírja a képernyőre azon számpárokat, amelyek relatív prímek! **(1 pont)**
6. **(maximum 1 pont**) Egy bementi állományban adott az n (2≤n≤10) érték és egy n×n méretű természetes számokat tartalmazó mátrix. Írjunk Pascal vagy C/C++ programot, amely beolvassa a mátrixot, és
	1. kiírja a képernyőre a mátrixot táblázatos alakban! **(0,5 pont)**
	2. végrehajtja a mátrixon az alábbi műveletsort:
		- első lépésben felépít egy (n–1)×(n–1) méretű mátrixot, amelynek elemei a következő képlettel számolhatók ki: új(i,j) = régi(i,j) + régi(i,j+1) + régi(i+1,j) + régi(i+1,j+1), bármely 1≤i,j<n;
		- ismételjük a fenti eljárást, míg 1×1 méretű mátrixhoz nem jutunk!
		- Írassuk ki a képernyőre a végső értéket! **(1 pont)**
7. **(maximum 1 pont)** Egy kertész különböző színű virágokat rendelt, melyeket egy n×m (1≤n≤999, 1≤m≤999) méretű, mátrix alakú kertbe szeretne soronként elültetni. Írjunk Pascal vagy C/C++ programot, amely a billentyűzetről beolvassa az n és m értékét, valamint egy számsorozatot, amely a virágok színét kódolja érkezési sorrendjük szerint. A színkódok a 1..16 intervallumba esnek. A számsor végét egy nulla érték jelzi.
	1. A program döntse el, hogy megfelel􀄘 számú virág érkezett-e a teljes kert beültetéséhez! **(0,75 pont)**
	2. A program írja ki a képernyőre, hogy a kert melyik oszlopában lesz a legtöbb egyszínű virág! Ha több megoldás van, akkor az elsőt kell kiírni! **(1 pont)**