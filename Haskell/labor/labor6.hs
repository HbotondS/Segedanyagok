import System.IO
import Data.List
import Data.Char

-- I. Olvassuk be az n természetes számot a
-- billentyűzetről és írjuk ki a képernyőre
--  1. n-ig a Fibonacci számok listáját (n>50)
fibo :: Int -> Int
fibo 0 = 0
fibo 1 = 1
fibo n = fibo (n-1) + fibo (n-2)

fibn :: Int -> [Int]
fibn n = takeWhile (<n) (map fibo [1..])

fib = do
    line <- getLine
    let n = (read line :: Int)
    print (fibn n)


--  2. n-ig a prímszámok listáját
primes = primes' 2
    where
        primes' x = x  : filter(\i ->mod i x /= 0) (primes' $ x+1)

prime = do
    line <- getLine
    let n = (read line :: Int)
    print (takeWhile (<n) primes)

--  3. az n kettes számrendszerbeli alakját,
--  minden negyedik bit után tegyünk egy space-et
kettes 0 = ""
kettes n = kettes (div n 2) ++ [intToDigit(mod n 2)]

add4Spaces :: String -> String
add4Spaces xs@(_:_:_:_:[]) = xs
add4Spaces (a:b:c:d:xs) = a:b:c:d:' ':add4Spaces xs
add4Spaces xs = xs

ketu = do
    line <- getLine
    let n = (read line :: Int)
    print (add4Spaces (kettes n))

--  4. az n 16-os számrendszerbeli alakját, minden két
--  szimbólum után tegyünk egy space-et, használjuk
--  az a, b, c, d, e, f szimbólumokat
tizenhatos 0 = ""
tizenhatos sz = tizenhatos (div sz 16) ++ [digit16] where
    digit16
        | szamjegy < 10 = intToDigit szamjegy
        | szamjegy == 10 = 'a'
        | szamjegy == 11 = 'b'
        | szamjegy == 12 = 'c'
        | szamjegy == 13 = 'd'
        | szamjegy == 14 = 'e'
        | szamjegy == 15 = 'f'
        where
            szamjegy = mod sz 16

add2Spaces :: String -> String
add2Spaces xs@(_:_:[]) = xs
add2Spaces (a:b:xs) = a:b:' ':add2Spaces xs
add2Spaces xs = xs

tizhat = do
    line <- getLine
    let n = (read line :: Int)
    print (add2Spaces (tizenhatos n))

--  5. az n szám x hatványon való értékét, ahol x értékét szintén a billentyűzetről olvassuk be
hatvany x n
    | n == 0 = 1
    | mod n 2 == 0 = temp * temp
    | otherwise = x * temp * temp
    where
      temp = hatvany x (div n 2)

hatv = do
    line <- getLine
    let x = (read line :: Int)
    line <- getLine
    let n = (read line :: Int)
    print (hatvany x n)

--  6. a következő listát [(0,0), [(0,1),(1,0)], [(0,2),(1,1),(2,0)], ..., [(0,n),(1,n-1), ..., (n,0)]]
lista = do
    line <- getLine
    let n = (read line :: Int)
    print ([[(j-i, i) | i <- [j, j-1..0]] | j <- [0..n]])

-- 7. azt a listát, mely tartalmazza n-ig  az összes természetes szám kettes számrendszerbeli alakját
kettesLista 0 = []
kettesLista n = kettesLista (div n 2) ++ [mod n 2]

ketuLista = do
    line <- getLine
    let n = (read line :: Int)
    print (map kettesLista [1..n])

-- II  Olvassunk be adott végjelig adatokat (számokat, karakterláncokat, stb.) a billentyűzetről és
--  1. határozzuk meg a legnagyobbat
maxi max end = do
    line <- getLine
    let x = (read line :: Int)
    if x == end then return max
    else
      if max < x then maxi x end
      else maxi max end

--  2. határozzuk meg a legnagyobb elemek indexét, feltételezve, hogy több legnagyobb elem is szerepel a számok között
maxi2 max end n = do
    line <- getLine
    let x = (read line :: Int)
    if x == end then return n
    else
      if max < x then maxi2 x end (n+1)
      else maxi2 max end n

-- III Olvassunk be a billentyűzetről egész számokat egy listába, majd írjuk ki a képernyőre, hogy
--  1. hányszor szerepel egy adott elem a listában
hanyszor :: [Int] -> Int -> Int -> IO Int
hanyszor ls n end = do
    line <- getLine
    let x = (read line :: Int)
    if x == end then return (seged ls n)
    else hanyszor (ls ++ [x]) n end

seged [] n = 0
seged (k: ve) n
    | k == n = 1 + seged ve n
    | otherwise = seged ve n
