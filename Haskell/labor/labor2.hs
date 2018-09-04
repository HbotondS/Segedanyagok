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
szamjegyn res x n
    | x == 0 = res
    | x `mod` 10 == n = szamjegyn (res+1) (x`div`10) n
    | otherwise = szamjegyn res (x`div`10) n
    
--  5. egy szám páros számjegyeinek számát
szamjegyparos res x
    | x == 0 = res
    | mod (mod x 10) 2 == 0 = szamjegyparos (res+1) (div x 10)
    | otherwise = szamjegyparos res (div x 10)

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
kettes 0 = []
kettes n = kettes (div n 2) ++ [mod n 2]

kettes2 x = length (filter (==1) (kettes x))

--  8. az 1000-ik Fibonacci számot
fib1000 = sfib 0 1 1000
    where
    sfib a b n
        |n==0 = a
        |otherwise = sfib b (a+b) (n-1)