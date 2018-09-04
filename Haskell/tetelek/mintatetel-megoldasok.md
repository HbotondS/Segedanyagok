# Funkcionális programozás / mintatétel - megoldás

##### 1.
``` haskell
sDigit p nr
  | nr < p = nr
  | otherwise = digit + sDigit p temp
  where
      temp = div nr p
      digit = nr `rem` p
```

##### 2.
- típusdefiníció: `szamit :: Int -> [Int]`
- ha a függvény paramétere 5: `[1, 0, 1, 0, 1]`
- kezdeti kifejezést és a kiértékelés eredménye:
``` haskell
> sDigit 2
[1, 0]
```

##### 3.
- a lista elemein alkalmazza az első paraméterként megadott műveletet
- típusdefiníciók

``` haskell
fofugv :: [Int]

fugv :: (a -> Bool) -> [a] -> [a]
```
-  kezdeti kifejezést és a kiértékelés eredménye:

``` haskell
> fugv (\x -> x + 1) [1, 2, 3]
[2, 3, 4]
```
