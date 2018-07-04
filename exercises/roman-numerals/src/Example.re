let toRoman = (n) => {
  let rec go = (s) =>
    fun
    | n when n >= 1000 => go(s ++ "M", n - 1000)
    | n when n >= 900 => go(s ++ "CM", n - 900)
    | n when n >= 500 => go(s ++ "D", n - 500)
    | n when n >= 400 => go(s ++ "CD", n - 400)
    | n when n >= 100 => go(s ++ "C", n - 100)
    | n when n >= 90 => go(s ++ "XC", n - 90)
    | n when n >= 50 => go(s ++ "L", n - 50)
    | n when n >= 40 => go(s ++ "XL", n - 40)
    | n when n >= 10 => go(s ++ "X", n - 10)
    | n when n == 9 => go(s ++ "IX", n - 9)
    | n when n >= 5 => go(s ++ "V", n - 5)
    | n when n == 4 => go(s ++ "IV", n - 4)
    | n when n >= 1 => go(s ++ "I", n - 1)
    | _ => s;
  go("", n);
};
