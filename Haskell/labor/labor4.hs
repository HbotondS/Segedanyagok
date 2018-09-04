import Data.List
import Data.Ord

-- I. Definiáljuk azt a listát, amely tartalmazza:
--  1. az első n páros szám négyzetét.
elsonnegyzet n = take n [ i*i | i <- [2,4..]]

--  2. [1, 2, 2, 3, 3, 3, 4, 4, 4, 4…]
foo1 n = [i | i <- [1..n], j <- [1..i]]

--  3. [2, 4, 4, 6, 6, 6, 8, 8, 8, 8…]
foo2 n = [i*2 | i <- [1..n], j <- [1..i]]

--  4. [n, n-1, … 2, 1, 1, 2, … , n-1, n]
foo3 n = [ abs (n-i)  | i <- [0..n*2]]

foo3_2 n = [n, n-1..1] ++ [1..n]

-- 5. Váltakozva tartalmazzon True és False értékeket.
foo4 n = take n (cycle [True, False])

-- 6. Váltakozva tartalmazza a 0, 1, -1 értékeket.
foo5 n = take n (cycle [0,1,-1])


-- II.
--  1. Határozzuk meg egy lista pozitív elemeinek átlagát.
avg ls = div ossz n
    where
    pos = filter even ls
    ossz = sum pos
    n = length pos

--  2. Határozzuk meg azt a listát, amely tartalmazza
--  az eredeti lista minden n-ik elemét.
newlist ls n = [ls!!i | i<- [n-1,n+n-1..(length(ls)-1)]]

--  3. Határozzuk meg egy lista leggyakrabban
--  előforduló elemét.
gyakori [] = error "ures lista"
gyakori xs = head . head . sortBy (flip $ comparing length) . group . sort $ xs

--  4. Tükrözzük egy lista elemeit.
tukroz xs = reverse xs ++ xs

--  5. Határozzuk meg egy lista legnagyobb
--  elemeinek pozícióit, úgy hogy a lista elemeit
--  kétszer járjuk be, illetve úgy hogy a lista
--  elemeit csak egyszer járjuk be
maxpos xs = seged max xs (length xs -1) where
    seged _ [] _ = error "ures lista"
    seged _ _ (-1) = []
    seged max [x] n =
        if max == x then [0] else []
    seged max xs n =
        if max == xs!!n then
            n : seged max xs (n-1)
        else
            seged max xs (n-1)
    max = maximum xs

--  6. Határozzuk meg azt a listát, amely
--  tartalmazza egy adott elem találati pozícióit
pos1 x ls = seged x ls (length ls -1) where
    seged _ [] _ = error "ures lista"
    seged _ _ (-1) = []
    seged x [l] n =
        if x == l then [0] else []
    seged x ls n =
        if x == ls!!n then
            n : seged x ls (n-1)
        else
            seged x ls (n-1)

--  7. Határozzuk meg egy (String, Int) értékpárokból
--  álló lista esetében, az értékpárok második
--  elemeiből képzett összeget.
tupleossz [] = error "ures lista"
tupleossz [x] = snd x
tupleossz (x: ls) = snd x + (tupleossz ls)

-- III.
--  1. Határozzuk meg egy adott szám osztóinak számát.
osztok1 0 = []
osztok1 x =
    seged osztok1 x where
        seged [] _ = []
        seged (o: osztok1) x =
            if mod x o == 0 then
                o : seged osztok1 x
            else
                seged osztok1 x
        osztok1 = [1..x]

osztokszama1 x = length (osztok1 x)

-- ez a verzio az 1-et es magat a szamot nem szamolja bele, de annyival gyorsabb is
osztok2 n = [i | i <- [2.. div n 2], mod n i == 0]

osztokszama2 x = length (osztok2 x)

--  2. Határozzuk meg egy adott szám legnagyobb
--  páratlan osztóját.
maxparoszt1 x = head voszt where
    oszt = filter odd (osztok1 x)
    voszt = reverse oszt

paratlanOsztok x = [i | i <- [3, 5.. div x 2], mod x i == 0]
maxparoszt2 x = last (paratlanOsztok x)

--  3. Határozzuk meg, hogy egy tízes számrendszerbeli szám p számrendszerben, hány számjegyet tartalmaz.
pszamrendszer p n
    | n < p = [n]
    | otherwise = pszamrendszer p temp ++ [szam]
    where
        temp = div n p
        szam = mod n p

pszamhossz p n = length (pszamrendszer p n)

--  5. Határozzuk meg, az a és b közötti Fibonacci számokat.
fib 0 = 0
fib 1 = 1
fib n = fib(n-1) + fib(n-2)

filterFib a b = dropWhile (\x -> x <= 2) (takeWhile (\x -> x <= b) (map fib [a..b]))
