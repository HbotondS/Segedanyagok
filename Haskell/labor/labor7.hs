import Data.Char
import System.IO
import Control.Monad

-- I.
--  1. Generáljuk ki az N-nél kisebb
--  négyzetszámokat egy szövegállományba
negyzetn n = takeWhile (<=n) (map (^2) [1..])

negyzetkiir = do
    putStr "n = "
    temp <- getLine
    let n = read temp :: Int
    outf <- openFile "negyzet.txt" WriteMode
    hPrint outf (negyzetn n)
    hClose outf

-- II.
--  1.Szövegállományban levő számokat olvassunk
--  ki egy listába, majd rendezve (tetszőleges
--  rendezési algoritmust írva) írjuk át egy
--  másik szövegállományba őket.
qSort :: [Int] -> [Int]
qSort [] = []
qSort (k: ve) = qSort kLista ++ [k] ++ qSort nLista
    where
    kLista = [x | x <- ve, x > k]
    nLista = [x | x <- ve, x <= k]

filesort be ki = do
    let list = []
    inf <- openFile be ReadMode
    contents <- hGetContents inf
    let singlewords = words contents
        list = f singlewords
    let slist = qSort list
    print slist
    hClose inf

filesort2 be = do
    inf <- openFile be ReadMode
    hLista <- beolvas inf
    putStrLn $ show hLista
    hClose inf

beolvas inf = do
    heof <- hIsEOF inf
    if heof then return []
    else do
        temp <- hGetLine inf
        let [i, k] = map (read :: String -> Integer ) $ words temp
        ve <- beolvas inf
        return (k: ve)

f :: [String] -> [Int]
f = map read
