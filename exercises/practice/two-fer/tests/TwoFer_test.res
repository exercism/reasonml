open Test
open TwoFer

let stringEqual = (~message=?, a: string, b: string) =>
  assertion(~message?, ~operator="stringEqual", (a, b) => a == b, a, b)

test("no name given", () =>
  stringEqual(twoFer(None), "One for you, one for me.")
)

test("a name given", () =>
  stringEqual(twoFer(Some("Alice")), "One for Alice, one for me.")
);

test("another name given", () =>
  stringEqual(twoFer(Some("Bob")), "One for Bob, one for me.")
)
