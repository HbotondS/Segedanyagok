-- elso n primszam
eSzita :: Int -> [Int]
eSzita n = take n (2: szita [3, 5..])

szita :: [Int] -> [Int]
szita (k: ve) = (k: szita [x | x <- ve, mod x k /= 0])

-- irjuk ki file-ba az elso n pimszamot
primFileIr :: IO()
primFileIr = do
  putStr "n= "
  temp <- getLine
  let n = read temp :: Int
  let lPrim = eSzita n
  writeFile "prim.txt" $ show lPrim

-- olvassuk be es irjuk ki a kepernyore a prim.txt tartalmat
primFileOlvas :: IO()
primFileOlvas = do
  inf <- readFile "prim.txt"
  let lPrim = read inf :: [Int]
  putStrLn $ show lPrim
