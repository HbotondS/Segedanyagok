import Data.Char

-- I. Definiáljuk a következő függvényt mely meghatározza
--  1. egy szám számjegyeinek szorzatát
szamszor :: Int -> Int
szamszor x
    | (x < 10) && (x >= 0) = x
    | otherwise = szamszor(div x 10) * (mod x 10)

--  2. egy szám számjegyeinek összegét
szamossz :: Int -> Int
szamossz x
    | (x < 10) && (x >= 0) = x
    | otherwise = szamossz(div x 10) + (mod x 10)

--  3. egy szám számjegyeinek számát
szamjegy :: Int -> Int
szamjegy x
    | (x < 10) && (x >= 0) = 1
    | otherwise = szamjegy(div x 10) + 1

--  4. egy szám azon számjegyeinek összegét,
--  mely paraméterként van megadva
szamjegyn1 res x n
    | x == 0 = res
    | x `mod` 10 == n = szamjegyn1 (res+1) (x`div`10) n
    | otherwise = szamjegyn1 res (x`div`10) n

szamjegyn2 x n
    | x == 0 = 0
    | mod x 10 == n = 1 + szamjegyn2 (div x 10) n
    | otherwise = szamjegyn2 (div x 10) n

--  5. egy szám páros számjegyeinek számát
szamjegyparos1 res x
    | x == 0 = res
    | mod (mod x 10) 2 == 0 = szamjegyparos1 (res+1) (div x 10)
    | otherwise = szamjegyparos1 res (div x 10)

szamjegyparos2 x
    | x == 0 = 0
    | even (mod x 10) == True = 1 + szamjegyparos2 (div x 10)
    | otherwise = szamjegyparos2 (div x 10)

--  6. egy szám legnagyobb számjegyét
szamjegynagy res x
    | x == 0 = res
    | szj > res = szamjegynagy szj szam
    | otherwise = szamjegynagy res szam
    where
        szj = mod x 10
        szam = div x  10

--  7. egy szám kettes számrendszerbeli
--  alakjában az 1-esek számát
kettes x = length (filter (==1) (seged x))
    where
      seged 0 = []
      seged n = seged (div n 2) ++ [mod n 2]

--  8. az 1000-ik Fibonacci számot
fib1000 = sfib 0 1 1000
    where
      sfib a b n
          | n == 0 = a
          | otherwise = sfib b (a+b) (n-1)
-- III. Definiáljuk a következő függvényt, halmazműveleteket alkalmazva, ahol a függvény meghatározza
--  1. egy szám páros osztóinak listáját
parososztok n = [i | i <- [2, 4.. div n 2], mod n i == 0]

--  2. az első n természetes szám köbét
elsonkob n = map (\x -> x ^ 3) [1..n]

--  3. az első n természetes szám negyzetgyökét
elsongyok n = map (\x -> sqrt x) [1..n]

--  5. x hatványait, adott n-ig
hatvanyok x n = [x ^ i | i <- [1..n]]

--  6. a következő listát: [('a',0), ('b',1), ..., ('z', 25)]
betuszam1 = [(chr x, x - 97) | x <- [97..122]]

betuszam2 = zip ['a'..'z'] [0..25]
--  7. a következő listát: [(0, 5), (1, 4), (2, 3), (3, 2), (4, 1), (5, 0)], majd általánosítsuk a feladatot
szamok1 = zip [0..5] [5, 4..0]

szamok2 n = zip [0..n] [n, n-1..0]
