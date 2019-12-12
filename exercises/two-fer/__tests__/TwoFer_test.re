open Jest;

describe("Two Fer", () => {
  open Expect;

  test("no name given", () =>
    expect(TwoFer.twoFer(None)) |> toEqual("One for you, one for me.")
  );

  test("a name given", () =>
    expect(TwoFer.twoFer(Some("Alice"))) |> toEqual("One for Alice, one for me.")
  );

  test("another name given", () =>
    expect(TwoFer.twoFer(Some("Bob"))) |> toEqual("One for Bob, one for me.")
  );

});
