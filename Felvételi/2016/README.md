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
	1. a billentyűzetről beolvas két egész számot, és egy-egy üzenet kíséretében kiírja a képernyőre, hogy melyik a kisebb és melyik a nagyobb **(0,5 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat2/2i.cpp)
	2. a billentyűzetről beolvas három egész számot, és egy-egy üzenet kíséretében
kiírja a képernyőre, hogy melyik a legkisebb és melyik a legnagyobb! Írjunk és
használjunk saját függvényt két érték összehasonlítására! **(0,75 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat2/2ii.cpp)
	3. a billentyűzetről beolvas egy n értéket (n>2), majd egy n elemű egész számokból álló számsorozatot, és növekvő sorrendben kiírja a képernyőre a számsorozat három legkisebb elemét, tömbök használata nélkül. **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat2/2iii.cpp)
3. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely beolvas a billentyűzetről egy n természetes számot (n>0), majd egy n elemű, egész számokból álló számsorozatot! Számítsuk ki a számsorozat
	1. elemeinek összegét! **(0,75 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat3/3i.cpp)
	2. elemei számjegyeinek összegét! **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat3/3ii.cpp)
4. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely beolvas a billentyűzetről egy n természetes számot, és kiírja a képernyőre
	1. az 1, 2, 3, 4, …, n számsorozatot! **(0,5 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat4/4i.cpp)
	2. az 1, 1, 2, 1, 2, 3, 1, 2, 3, 4, … számsorozat első n elemét! **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat4/4ii.cpp)
5. **(maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely billentyűzetről beolvas egy n (1≤n≤100) természetes számot, majd n darab egész számpárt
	1. és kiírja a képernyőre azon számpárok számát, amelyek elemei azonosak! **(0,5 pont)**
	2. és egymás alatti sorokba, a beolvasás fordított sorrendjében kiírja a képernyőre azon számpárokat, amelyek relatív prímek! **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat5/5ii.cpp)
6. **(maximum 1 pont**) Egy bementi állományban adott az n (2≤n≤10) érték és egy n×n méretű természetes számokat tartalmazó mátrix. Írjunk Pascal vagy C/C++ programot, amely beolvassa a mátrixot, és
	1. kiírja a képernyőre a mátrixot táblázatos alakban! **(0,5 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat6/6i.cpp)
	2. végrehajtja a mátrixon az alábbi műveletsort:
		- első lépésben felépít egy (n–1)×(n–1) méretű mátrixot, amelynek elemei a következő képlettel számolhatók ki: új(i,j) = régi(i,j) + régi(i,j+1) + régi(i+1,j) + régi(i+1,j+1), bármely 1≤i,j<n;
		- ismételjük a fenti eljárást, míg 1×1 méretű mátrixhoz nem jutunk!
		- Írassuk ki a képernyőre a végső értéket! **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat6/6ii.cpp)
7. **(maximum 1 pont)** Egy kertész különböző színű virágokat rendelt, melyeket egy n×m (1≤n≤999, 1≤m≤999) méretű, mátrix alakú kertbe szeretne soronként elültetni. Írjunk Pascal vagy C/C++ programot, amely a billentyűzetről beolvassa az n és m értékét, valamint egy számsorozatot, amely a virágok színét kódolja érkezési sorrendjük szerint. A színkódok a 1..16 intervallumba esnek. A számsor végét egy nulla érték jelzi.
	1. A program döntse el, hogy megfelelő számú virág érkezett-e a teljes kert beültetéséhez! **(0,75 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat7/7i.cpp)
	2. A program írja ki a képernyőre, hogy a kert melyik oszlopában lesz a legtöbb egyszínű virág! Ha több megoldás van, akkor az elsőt kell kiírni! **(1 pont)** [(megoldás)](https://github.com/HbotondS/Segedanyagok/blob/master/Felv%C3%A9teli/2016/feladat7/7ii.cpp)
---
# Javítókulcs
## Elmélet
##### Változó **(0,75 pont)**
- definíció (cím/hely, név/azonosító, típus, érték)
- életciklus, érvényességi kör (lokális, globális)
- helyfoglalás (mikor, hol)
- kezdőérték
##### Típus **(0,75 p)**
- definíció (értékkészlet, műveletek)
- osztályozás (elemi/primitív, összetett, felhasználói)
##### Változó beolvasása és kiíratása **(0,5 p)**
## Gyakorlat
1. feladat
	1. 320 **(0,75 p)**
	2. egy helyes példa, például 857 **(1 p)**
2. feladat
	1. mindhárom eset kezelése (kisebb, nagyobb, egyenlő) **(0,5 p)**
	2. algoritmus helyessége **(0,5 p)**; függvény **(0,25 p)**
	3. algoritmus helyessége **(0,5 p)**; számsorozat eltárolása nélkül **(0,5 p)**
3. feladat
	1. változók helyes definiálása és inicializálása **(0,1 p)**; ciklus helyes használata **(0,1 p)**; változók beolvasása **(0,1 p)**; helyes algoritmus **(0,45 p)**
	2. változók helyes definiálása és inicializálása **(0,1 p)**; ciklusok helyes használata **(0,2 p)**; változók beolvasása **(0,1 p)**; helyes algoritmus **(0,6 p)**
4. feladat
	1. triviális **(0,5 p)**
	2. a számsorozat generálása **(0,75 p)**; csak az első n elem kiírása **(0,25 p)**
5. feladat
	1. beolvasás **(0,25 p)**; megszámlálás **(0,25 p)**
	2. beolvasás (0,25 p); kiírás fordított sorrendben **(0,25 p)**; relatív prím teszt **(0,5 p)**
6. feladat
	1. beolvasás **(0,25 p)**; kiírás **(0,25 p)**
	2. beolvasás **(0,2 p)**; algoritmus **(0,7 p)**; kiírás **(0,1 p)**
7. feladat
	1. méret beolvasás **(0,2 p)**; beolvasás végjelig **(0,25 p)**; egyenlőség vizsgálat **(0,3 p)**
	2. méret beolvasás **(0,1 p)**; beolvasás végjelig **(0,25 p)**; tömb inicializálása **(0,1 p)**; gyakoriság és maximum számlálás **(0,4 p)**; kiírás **(0,15 p)**
