data Nat = Int | Succ Nat deriving(Eq, Ord, Read, Show)

natPlus:: Nat -> Nat -> Nat
natPlus (Int) x = x
natPlus x (Int a) = x
natPlus x (Succ ys) = Succ $ natPlus x ys

natMult :: Nat -> Nat -> Nat
natMult (Int a) _ = a
natMult _ (Int a) = a
natMult (Succ xs) y = natPlus y $ natMult xs y

main = do
    a  <-  getLine 
    b <-  getLine
    let nata = (read:: String -> Nat) a
    let natb = (read:: String -> Nat) b

    print (natMult nata natb)
