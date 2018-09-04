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

fibs :: Int -> [Int]
fibs 0 = []
fibs n = fibo n: fibs (n-1)

fibn :: Int -> [Int]
fibn n = reverse (fibs n)

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
    print (take n primes)
    
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