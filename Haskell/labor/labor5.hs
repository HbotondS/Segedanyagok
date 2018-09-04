import Data.List
import Data.Ord

-- II.
data Fesztivalok = Fesztivalok{
    egyuttes :: String,
    fesztival :: String,
    ar :: Int,
    kod :: Int
    }deriving (Show)

-- Hozzunk létre egy fenti típusú konstans listát,
-- majd írjuk meg rendre az alábbi függvényeket:
szlista :: [Fesztivalok]
szlista = [Fesztivalok "Sarika" "Untold" 100 1,
            Fesztivalok "Pista" "Untold" 80 4,
            Fesztivalok "Sarika" "Told" 80 4,
            Fesztivalok "Ferike" "Doublerise" 150 2,
            Fesztivalok "Ferike" "Rise" 75 5,
            Fesztivalok "Lacika" "Metlica" 200 3,
            Fesztivalok "Lacika" "Metl" 1000 6]

--  1. határozzuk meg egy adott fesztiválon
--  szereplő eggyütteseket
egyuttesek x = seged x szlista where
    seged x [k] =
        if x == fesztival k then
           [egyuttes k]
        else
            []
    seged x (k: ls) =
        if x == fesztival k then
           egyuttes k : seged x ls
        else
            seged x ls

egyuttesek2 x [] = []
egyuttesek2 x (k: ve)
    | fesztival k == x = k : egyuttesek2 x ve
    | otherwise = egyuttesek2 x ve

--  2. határozzuk meg azokat az együtteseket,
--  melyek egy adott értéknél olcsóbban
--  árulják koncertjegyeiket
olcsoegyuttesek x = nub (seged x szlista) where
    seged x [k] =
        if ar k < x then
            [egyuttes k]
        else
            []
    seged x (k: ls) =
        if ar k < x then
            egyuttes k : seged x ls
        else
            seged x ls

olcsoegyuttesek2 :: Int -> [Fesztivalok] -> [String]
olcsoegyuttesek2 x ls = nub (seged x ls) where
    seged x [] = []
    seged x (k: ls)
        | ar k < x = egyuttes k : seged x ls
        | otherwise = seged x ls

--  3. határozzuk meg, hogy hány olyan együttes
--  szerepel a listában, mely egy adott értéknél
--  olcsóbban árulja koncertjegyét
csicskakszama x = length (olcsoegyuttesek x)

--  4. rendezzük a lista tartalmát az együttesek
--  nevei alapján ábécé sorrendbe (insertSort),
--  használjuk a következő típusdefiníciót
myins :: Fesztivalok -> [Fesztivalok] -> [Fesztivalok]
myins x [] = [x]
myins x (k: ve)
    | egyuttes x > egyuttes k = (k: myins x ve)
    | otherwise = (x: (k: ve))


insertSort :: [Fesztivalok] -> [Fesztivalok]
insertSort [] = []
insertSort (k: ve) = myins k (insertSort ve)

--  5. rendezzük a lista tartalmát a jegyárak
--  szerint csökkenő sorrendbe (qSort)
qSort :: [Fesztivalok] -> [Fesztivalok]
qSort [] = []
qSort (k: ve) = qSort kLista ++ [k] ++ qSort nLista
    where
    kLista = [x | x <- ve, ar x > ar k]
    nLista = [x | x <- ve, ar x <= ar k]

--  7. határozzuk, meg, hogy agy adott
--  fesztiválon mennyi a jegyek átlagértéke
avg [] = error "ures lista"
avg ls = div (sum ls) (genericLength ls)

fesztivalar x [] = error "ures lista"
fesztivalar x ls = avg (seged x ls) where
    seged :: String -> [Fesztivalok] -> [Int]
    seged x [] = []
    seged x (k: ve)
        | fesztival k == x = ar k: seged x ve
        | otherwise = seged x ve

-- II gyorshatvany
hatv :: (Integral a) => a -> a -> a
hatv x n
    | n < 0 = error "Negativ kitevo"
    | n == 0 = 1
    | mod n 2 == 0 = temp * temp
    | otherwise = x * temp * temp
    where
        temp = hatv x (div n 2)
