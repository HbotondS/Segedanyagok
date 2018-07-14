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
**1. (maximum 1 pont)**
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
**2. (maximum 1 pont)** Írjunk Pascal vagy C/C++ programot, amely