let fromBase = (base: int, digits: list(int)) : option(int) => {
  let toDecimal = (acc: option(int), digit: int) : option(int) =>
    switch (acc) {
    | None => None
    | Some(n) => digit >= 0 && digit < base ? Some(n * base + digit) : None
    };

  List.fold_left(toDecimal, Some(0), digits);
};

let rec toBase = (base: int, input: int) : list(int) =>
  input < base ? [input] : toBase(base, input / base) @ [input mod base];

let rebase =
    (inBase: int, digits: list(int), outBase: int)
    : option(list(int)) => {
  let length = List.length(digits);
  let numZeros = digits |> List.filter(digit => digit == 0) |> List.length;

  if (inBase <= 0 || outBase <= 0 || length == numZeros) {
    None;
  } else {
    switch (fromBase(inBase, digits)) {
    | Some(n) => Some(toBase(outBase, n))
    | _ => None
    };
  };
};
