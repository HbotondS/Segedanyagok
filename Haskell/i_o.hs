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
