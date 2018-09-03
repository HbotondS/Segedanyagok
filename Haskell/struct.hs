data Szemely = Szemely {
  nev :: String,
  jegy :: Double,
  ev :: Int
} deriving (Show)

valaki = Szemely "Wincs Eszter" 10 1
szemelyLS = [Szemely "Wincs Eszter" 10 1, Szemely "Vicc Elek" 2 3, Szemely "Para Zita" 5 2, Szemely "Trab Antal" 4.5 1]

-- hany diaknak van atmeno szamjegye
szamol [] = 0
szamol (k: ve)
  | jegy k > 4.5 = 1 + szamol ve
  | otherwise = szamol ve
