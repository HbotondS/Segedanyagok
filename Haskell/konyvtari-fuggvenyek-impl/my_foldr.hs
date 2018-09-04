my_foldr :: (a -> b -> b) -> b -> [a] -> b
my_foldr op x [] = x
my_foldr op x (k: ve) = op k (my_foldr op x ve)
