import System.IO
import Data.Char

helloWorld :: IO()
helloWorld = do
  putStrLn "Hello World!"

olvas :: IO()
olvas = do
  putStrLn "Irj be egy szamot:"
  sz <- getLine
  putStr $ "ezt irtad be: " ++ sz
  putStrLn ""

mainHatv :: IO ()
mainHatv = do
  putStr "Alap: "
  temp <- getLine
  -- let - a do blokkban kell hasznalni lokalis valtozok megadasara
  let x = read temp :: Integer
  putStr "Kitevo: "
  temp <- getLine
  let a = read temp :: Integer
  putStr "Eredmeny: "
  let res = x ^ a
  putStrLn $ show res

mainParos :: IO()
mainParos = do
  putStr "n= "
  temp <- getLine
  let n = read temp :: Int
  let lista = [i | i <- [2, 4.. n], mod n i == 0]
  putStrLn $ show lista

olvasInt :: IO Int
olvasInt = do
  str <- getLine
  return (read str :: Int)

olvasNSzam :: Int -> IO [Int]
olvasNSzam n = do
  k <- olvasInt
  if n == 1 then return [k]
  else do
    ve <- olvasNSzam $ n-1
    return (k: ve)

fileKiir :: String -> [Integer] -> IO()
fileKiir outf ls = do
  outf_ <- openFile outf WriteMode
  fileKiirSeged outf_ ls
  hClose outf_

fileKiirSeged :: Handle -> [Integer] -> IO()
fileKiirSeged outf [] = return ()
fileKiirSeged outf (k: ve) = do
  hPutStr outf $ (show k) ++ " "
  fileKiirSeged outf ve

fileOlvas :: String -> IO()
fileOlvas inf = do
  inf_ <- openFile inf ReadMode
  fileOlvasSeged inf_
  hClose inf_

fileOlvasSeged :: Handle -> IO()
fileOlvasSeged inf = do
  heof <- hIsEOF inf
  if heof then return()
  else do
    temp <- hGetLine inf
    putStrLn temp
    fileOlvasSeged inf

-- nagybetusitsuk az input.txt tartalmat es tegyuk az eredmenyt az output.txt-be
nagyBetusit1 :: IO()
nagyBetusit1 = do
  inf <- readFile "input.txt"
  writeFile "output.txt" $ map toUpper inf

nagyBetusit2 :: IO()
nagyBetusit2 = do
  inf <- openFile "input.txt" ReadMode
  outf <- openFile "output.txt" WriteMode
  feldolgoz inf outf
  hClose inf
  hClose outf

feldolgoz :: Handle -> Handle -> IO()
feldolgoz inf outf = do
  feof <- hIsEOF inf
  if feof then return()
  else do
    temp <- hGetLine inf
    hPutStrLn outf $ map toUpper temp
    feldolgoz inf outf

-- hatarozzuk meg egy fajl meretet bajtban
meret :: String -> IO()
meret inf = do
  inf_ <- openBinaryFile inf ReadMode
  size <- hFileSize inf_
  putStr "file size: "
  putStrLn $ show $ fromIntegral size
  hClose inf_

-- keszitsunk masolatot egy allomanyrol
masol :: IO()
masol = do
  inf <- openBinaryFile "input.txt" ReadMode
  outf <- openBinaryFile "input2.txt" WriteMode
  blista <- hGetContents inf
  hPutStr outf blista
  hClose inf
  hClose outf
