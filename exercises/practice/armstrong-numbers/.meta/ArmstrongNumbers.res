open Js.Array2

let to_digits = (number: int): array<int> => {
  Belt.Int.toString(number) -> Js.String2.split("") -> map(Belt.Int.fromString) -> map(Belt.Option.getExn)
}

let validate = (number: int): bool => {
  let digits = to_digits(number)
  let len = length(digits)
  let total = digits -> reduce((acc, x) => acc + Js.Math.pow_int(~base=x, ~exp=len), 0)
  total == number
}
