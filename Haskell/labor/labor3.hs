-- I. Könyvtárfüggvények használata nélkül 
-- implementáljuk azt a függvényt, amely
--  1. meghatározza egy lista elemszámát
my_lentgh [] = error "ures lista"
my_lentgh [k] = 1
my_lentgh (k: ve) = 1 + my_lentgh ve

--  2. összeszorozza a lista elemeit
my_product [] = 1
my_product (k: ve) = k * my_product ve

--  3. meghatározza egy lista legkisebb elemét
my_minimum (x: xs) = minhelper x xs where
    minhelper m [] = m
    minhelper m (y: ys)
        | y < m = minhelper y ys
        | otherwise = minhelper m ys
        
--  4. meghatározza egy lista legnagyobb elemét
my_maximum (x: xs) = maxhelper x xs where
    maxhelper m [] = m
    maxhelper m (y: ys)
        | y > m = maxhelper y ys
        | otherwise = maxhelper m ys
        
--  5. meghatározza egy lista n-ik elemét
my_index n (x: xs)
    | n <= 0 = x
    | otherwise = my_index (n-1) xs
    
--  6. egymásután fűzi a paraméterként megadott két listát
my_add :: [a] -> [a] -> [a]
my_add xs [] = xs
my_add [] ys = ys
my_add (x: xs) (y: ys) = x : y : my_add xs ys

--  7. a lista első elemét elköltözteti a lista végére.
my_move (k: ve) = reverse $ k : reverse ve 

--  8. meghatározza egy egész elemű lista
--  elemeinek átlagértékét
avg_list xs = my_sum xs / my_lentgh xs 
    where
        my_sum [] = 0
        my_sum (x: xs) = x + my_sum xs
        
--  9. megállapítja egy karakter listáról, 
--  hogy az palindrom-e vagy sem.
my_palindrom ls = if ls1 == ls2 then True else False
    where 
    ls1 = take (div (length ls) 2) ls
    ls2 = take (div (length ls) 2) (reverse ls)
    
-- 10. meghatározza egy szám p számrendszerbeli alakját.
pszamrendszer p n
    | n < p = [n]
    | otherwise = pszamrendszer p temp ++ [szam]
    where
        temp = div n p
        szam = mod n p

--  11. meghatározza egy egész elemű lista minden 
--  elemére külön-külön a számjegyek számát
elemszam 0 = 0
elemszam k = if k < 10 then 1 else 1 + elemszam (div k 10)

listaelemszam [] = []
listaelemszam (k: ve) = (k, elemszam k ) : listaelemszam ve

--  12. meghatározza egy egész elemű lista összes
--  elemének az össz-számjegyét
osszszamjegy [] = 0
osszszamjegy (k: ve) = elemszam k + osszszamjegy ve

--  13. meghatározza a P(x) = a0 + a1·x + a2·x2 +...
--  + an·xn polinom adott x0értékre való 
--  behelyettesítési értékét.
polinom x ve = segedpolinom x ve 0 where
    segedpolinom x [] p = error "a lista ures"
    segedpolinom x [k] p = k*x^p
    segedpolinom x (k: ve) p = k*x^p + segedpolinom x ve (p+1)
    
--  14. meghatározza egy p számrendszerben megadott 
--  szám számjegyei alapján a megfelelő 10-es 
--  számrendszerbeli számot.
pvissza ve p = seged ve p ((length ve)-1) where
    seged [] p n = error "ures lista"
    seged [k] p n = k*p^n
    seged (k: ve) p n = k*p^n + seged ve p (n-1)
    
-- II. Ha adva van egy P pont koordinátája a kétdimenziós 
-- síkban, és adott az lsP pontok egy listája, határozzuk 
-- meg azt az lsP-beli P1 pontot, amely a legközelebb van 
-- a P ponthoz.

--valami nem jo...
tavolsag :: (Int, Int) -> (Int, Int) -> Double
tavolsag x y = sqrt(fromIntegral (a^2 + b^2)) where
    a = (fst x - fst y)
    b = (snd x - snd y)
    
minInt = minBound::Int
maxInt = maxBound::Double
    
minTavolsag x xs = seged x xs maxInt (minInt, minInt) where
    seged x [] mintav minpont = error "ures lista"
    seged x [k] mintav minpont = 
        if mintav < tav then 
            minpont 
        else 
            k 
        where
            tav = tavolsag x k
    seged x (k: xs) mintav minpont =
        if mintav < tav then
            seged x xs mintav minpont
        else 
            seged x xs tav k
        where
            tav = tavolsag x k