![](https://img.shields.io/badge/language-Haskell-blue.svg)

## Kapcsolodó tantárgy: Logikai és funkcionális programozás
A **Compiler**-t [ide kattintva](https://www.haskell.org/downloads) tudod letölteni.
Telepítés után a compiler-t a command ablakban tudod elínditani **Windows**-on a `ghci` parancs segítségével.
## Hasznosabb parancsok a fordításhoz
**Fotos**, ha be szeretnél tölteni egy fájlt akkor elöször a command ablakban be kell lépj abba a mappába ahol a fájl található. Máskülönben direkt elérési útvonalat kell megadni.<br />
Fájl betöltése:
```
:l filename
```
Fájl újratöltése:
```
:r filename
```
Függvények és változók típusdefiníciói:
```
:t variable/function
```
Aktuális munkakönyvtár lekérdezése:
```
:!cd
```
Munkakönyvtár változtatása:
```
:cd C:\Diak
```
Kilépés a compilerből:
```
:quit
```
## Én előre szóltam...
A feladatokat nemsokkal a vizsga előtti napon oldottam meg, szóval kisebb-nagyobb hibák előfordulhatnak, vagy esetleg hogy nincs meg egy-egy feladat.<br />
Igyekszem majd idővel javítani és bővíteni és szívesen fogadok bármi féle észrevételt. :smiley:

## Néhány példa
1. Határozzuk meg egy alap<sup>0</sup>, alap<sup>1</sup>...alap<sup>10</sup> (a kitevő változik, az alap állandó)
```
fugv :: (Integral a) => a -> [a]
fugv alap = map ((\x n -> x ^ n) alap) [0..10]
```
Az **x** paraméter megkapja az **alap** értékét és az **n** paraméter pedig megkapja rendre a lista elemienek értékét.

2. Határozzuk meg 0<sup>kit</sup>, 1<sup>kit</sup>...10<sup>kit</sup> (a kitevő állandó, az alap változik)
```
fugv :: (Integral a) => a -> [a]
fugv kit = map ((\n x -> x ^ n) kit) [0..10]
```
