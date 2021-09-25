open Belt;

let fromBase = (base: int, digits: list<int>) : option<int> => {
  let toDecimal = (acc: option<int>, digit: int) : option<int> =>
    switch (acc) {
    | None => None
    | Some(n) => digit >= 0 && digit < base ? Some(n * base + digit) : None
    }

  digits -> List.reduce(Some(0), toDecimal)
}

let rec toBase = (base: int, input: int) : list<int> =>
  input < base ? list{input} : list{mod(input, base), ...toBase(base, input / base)}

let rebase =
    (inBase: int, digits: list<int>, outBase: int)
    : option<list<int>> => {
  let length = digits -> List.length
  let numZeros = digits -> List.keep(digit => digit == 0) -> List.length

  if (inBase <= 0 || outBase <= 0 || length == numZeros) {
    None
  } else {
    switch (fromBase(inBase, digits)) {
    | Some(n) => Some(toBase(outBase, n) -> List.reverse)
    | _ => None
    }
  }
}
