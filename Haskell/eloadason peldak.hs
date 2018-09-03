import Data.Char

-- kivonasos modszer
lnko1 :: Int -> Int -> Int
lnko1 a b
    | a > b = lnko1 (a-b) b
    | a < b = lnko1 a (b-a)
    | otherwise = a

-- eukledeszi modszer
lnko2 :: Integral a => a -> a -> a
lnko2 a b
    | b == 0 = a
    | otherwise = lnko2 b (mod a b)

-- szamjegyek osszege
szOsszeg :: Int -> Int
szOsszeg 0 = 0
szOsszeg x = (mod x 10)
    + szOsszeg (div x 10)

-- szamjegyek szorzata
szSzorzat :: Int -> Int
szSzorzat x
    | x < 10 = x
    | otherwise = (mod x 10) * szSzorzat (div x 10)

-- szam osztoi
osztok :: Int -> [Int]
osztok n = [i | i <- [1..n], mod n i == 0]

-- noveljuk a parameterkent megadott szamokat egyel
l_inc :: (Num a) => [a] -> [a]
l_inc ls = map (\x -> x+1) ls

-- paros szamok szurese
parosLs :: (Integral a) => [a] -> [a]
parosLs ls = filter even ls

-- noveljuk a megadott parametert kettovel
duplaz :: (Num a) => (a -> a) -> a -> a
duplaz f x = f (f x)

my_inc :: (Num a) => a -> a
my_inc x = x + 1
-- hasznalat: duplaz my_inc [szam]

-- hatvanyozas maskepp
hatv :: (Integral a) => a -> a -> a
hatv x n
    | n < 0 = error "Negativ kitevo"
    | n == 0 = 1
    | mod n 2 == 0 = temp * temp
    | otherwise = x * temp * temp
    where
        temp = hatv x (div n 2)

-- listabol mi oszthato a parameterrel
oszthato :: (Integral a) => a -> a -> Bool
oszthato x y
    | mod y x == 0 = True
    | otherwise = False

oszthatok :: (Integral a) => a -> [a] -> [a]
oszthatok x ls = filter (oszthato x) ls

-- vizsgaljunk egy szamot: pozitiv es oszthato hattal, stb
fugvp :: Int -> [Char]
fugvp n
    | n > 0, mod n 2 == 0, mod n 3 == 0 = "pozitiv, oszthato 6-al"
    | n > 0, mod n 2 == 0, mod n 3 /= 0 = "pozitiv, nem oszthato 6-al"
    | n > 0, mod n 2 == 1 = "pozitiv, paratlan"
    | n < 0, mod n 2 == 0 = "negativ, paros"
    | otherwise = "negativ, paratlan"

-- hatarozzuk meg egy masodfoku egyenlet gyokeit
gyok :: (Fractional a, Floating a, Ord a) => a -> a -> a -> (a, a)
gyok a b c =
    let
      x1 = (-b + sqrt delta) / n
      x2 = (-b - sqrt delta) / n
      delta = b * b - 4 * a * c
      n = 2 * a
    in
      if delta < 0 then error "komplex gyok"
      else (x1, x2)

-- case of hasznalata | szamjegy 16-os szamrendszerbeli alakja
szimb :: Int -> Char
szimb c
    | c >= 0, c < 16 =
      case c of
        10 -> 'A'
        11 -> 'B'
        12 -> 'C'
        13 -> 'D'
        14 -> 'E'
        15 -> 'F'
        _ -> chr (c + 48)
    | otherwise = error "rossz bemenet"

paratlanLista :: (Integral a) => [a] -> [a]
paratlanLista ls = filter (not . even) ls

-- vagjuk le a parameterkent kapott lista elso es utolso karakteret
levag :: [a] -> [a]
levag = init.tail

-- Definiáljunk egy Pont típusú értéket és írjunk három függvényt:
-- definiáljuk a kezdőpontot, mozgassuk el a pontot, határozzuk meg két
-- pont között a távolságot.
type Szin = String
type Pont = (Double, Double, Szin)

kezdoP :: Szin -> Pont
kezdoP szin = (0, 0, szin)

mozgat :: Pont -> Double -> Double -> Pont
mozgat (x, y, szin) xTav yTav =
    (x + xTav, y + yTav, szin)

tavolsag :: Pont -> Pont -> Double
tavolsag (x1, y1, szin1) (x2, y2, szin2) =
    sqrt (dx * dx + dy * dy)
    where
      dx = x2 - x1
      dy = y2 - y1

-- head, tail, init, last, sum, reverse fuggveny a konyvtarfuggvenyek hasznalata nelkul
my_head [] = error "ures lista"
my_head (k: ve) = k

my_tail [] = error "ures lista"
my_tail (k: ve) = ve

my_init [] = error "ures lista"
my_init [k] = []
my_init (k: ve) = (k: my_init ve)

my_last [] = error "ures lista"
my_last [k] = k
my_last (k: ve) = my_last ve

my_sum1 [] = 0
my_sum1 (k: ve) = k + my_sum1 ve

my_sum2 [] = 0
my_sum2 ls = head ls + my_sum2 (tail ls)

my_reverse :: [a] -> [a]
my_reverse [] = []
my_reverse (k: ve) = my_reverse ve ++ [k]

-- paros osztok listaja
parosOsztok :: (Integral a) => a -> (a, [a])
parosOsztok n = (n, [i | i <- [2, 4.. (div n 2 + 1)], mod n i == 0])

-- adott elem beszurasa a listaba
ins x [] = [x]
ins x (k: ve)
  | x > k = (k: ins x ve)
  | otherwise = (x: k: ve)

-- beszurasos rendezes
insertS [] = []
insertS (k: ve) = ins k (insertS ve)
