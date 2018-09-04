-- 1. meghatározza két szám összegét, különbségét, 
-- szorzatát, hányadosát, osztási maradékát
myadd x y = x + y
mysub x y = x - y
mymul x y = x * y
mydiv x y = x / y
mymod x y = mod x y

-- 2. meghatározza egy elsőfokú egyenlet gyökét
elsofoku a b
    | a==0 = error "0val osztas"
    | otherwise = (-b)/a
        
-- 3. meghatározza egy szám abszolút értékét
modulus a
    | a < 0 = (-a)
    | otherwise = a
    
-- 4. meghatározza egy szám előjelét
elojel a
    | a < 0 = "negative"
    | otherwise = "positive"
    
-- 5. meghatározza két argumentuma közül a maximumot
myMaximum a b 
    | a > b = a
    | otherwise = b
    
-- 6. meghatározza két argumentuma közül a minimumot
myMinimum a b
    | a < b = a
    | otherwise = b
    
-- 7. meghatározza egy másodfokú egyenlet gyökeit
masodfoku a b c
    | delta < 0 = error "komplex gyok"
    | otherwise = (x1, x2)
    where
        delta = b^2 - 4*a*c
        x1 = (-b + sqrt(delta))/(2*a)
        x2 = (-b - sqrt(delta))/(2*a)

-- 8. megvizsgálja, hogy két elempár értékei "majdnem" 
-- megegyeznek-e: akkor térít vissza True értéket a függvény, 
-- ha a két pár ugyanazokat az értékeket tartalmazza 
-- függetlenül az elemek sorrendjétől.
majdnem :: (Eq a)=>(a,a)->(a,a)->Bool
majdnem (a, b) (c, d)
    | num1 == num2 = True
    | num1 == num3 = True
    | otherwise = False
    where
        num1 = (a, b)
        num2 = (c, d)
        num3 = (d, c)
        
-- 9. meghatározza az n szám faktoriálisát
fakt1 n
    | n == 0 = 1
    | otherwise = n * fakt1(n-1)
    
-- 10. meghatározza az x szám n-ik hatványát, 
-- ha a kitevő pozitív szám
hatvany x n
    | n < 0 = error "negativ kitevo"
    | otherwise = x ^ n
