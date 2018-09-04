my_foldl :: (a -> b -> a) -> a -> [b] -> a
my_foldl op x [] = x
my_foldl op x (k: ve) = my_foldl op (op x k) ve
