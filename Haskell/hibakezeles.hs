import Control.Exception
import System.IO

myDiv1 :: Double -> Double -> Double
myDiv1 _ 0 = error "nullaval valo osztas"
myDiv1 x y = x / y

mainCatch :: Double -> Double -> IO()
mainCatch x y  = catch (print $ myDiv1 x y) kivetelKezelo
  where
    kivetelKezelo :: SomeException -> IO()
    kivetelKezelo err = putStr $ "Hiba jellege: " ++ show err

mainFileCatch = catch ( do
    inf <- openFile "prime.txt" ReadMode
    lista <- hGetContents inf
    putStrLn lista
    hClose inf
  ) kivetelKezelo
  where
    kivetelKezelo :: SomeException -> IO ()
    kivetelKezelo err = putStrLn $ "Hiba jellege: " ++ show err

myDiv2 :: Double -> Double -> Maybe Double
myDiv2 _ 0 = Nothing
myDiv2 x y = Just $ x / y

mainCase1 :: Double -> Double -> IO()
mainCase1 x y =
  case myDiv2 x y of
    Nothing -> putStrLn "nullaval valo osztas"
    Just k -> putStrLn $ show k

mainEither1 :: [a] -> Either String a
mainEither1 [] = Left ("ures lista")
mainEither1 ls = Right (head ls)

myDiv3 :: Double -> Double -> Either String Double
myDiv3 _ 0 = Left ("Nullaval valo osztas ")
myDiv3 x y = Right (x / y)

mainCase2 :: Double -> Double -> IO()
mainCase2 x y =
  case myDiv3 x y of
      Left str -> putStrLn str
      Right k -> putStrLn (show k)
