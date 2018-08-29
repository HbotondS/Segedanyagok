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