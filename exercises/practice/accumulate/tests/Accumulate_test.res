open Test;
open Accumulate;

let square = (x) => x * x

let reverse = (x) =>
    x
    -> Js.String2.split("")
    -> Js.Array2.reverseInPlace
    -> Js.Array2.joinWith("")

let arrayEqual = (~message=?, a: array<'a>, b: array<'a>) =>
  assertion(~message?, ~operator="Array equals", (a, b) => a == b, a, b)

test("[] Accumulate", () =>
  arrayEqual(~message="Returns empty array", accumulate(square, []), [])
);

test("square Accumulate", () =>
  arrayEqual(~message="Squares all elements", accumulate(square, [1, 2, 3]), [1, 4, 9])
);

test("toUpper Accumulate", () =>
  arrayEqual(~message="Converts all elements to uppercase", accumulate(String.uppercase_ascii, ["hello", "world"]), ["HELLO", "WORLD"])
);

test("reverse Accumulate", () =>
  arrayEqual(~message="Reverses all elements", accumulate(reverse, ["hello", "world"]), ["olleh", "dlrow"])
);
