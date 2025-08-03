open Jest;
open Expect;
open CollatzConjecture;

describe("Collatz Conjecture", () => {
  test("zero steps for one", () =>
    expect(collatzConjecture(1)) |> toEqual(Ok(0))
  );
  test("divide if even", () =>
    expect(collatzConjecture(16)) |> toEqual(Ok(4))
  );
  test("even and odd steps", () =>
    expect(collatzConjecture(12)) |> toEqual(Ok(9))
  );
  test("large number of even and odd steps", () =>
    expect(collatzConjecture(1000000)) |> toEqual(Ok(152))
  );
  test("zero is an error", () =>
    expect(collatzConjecture(0))
    |> toEqual(Error("Only positive integers are allowed"))
  );
  test("negative value is an error", () =>
    expect(collatzConjecture(-15))
    |> toEqual(Error("Only positive integers are allowed"))
  );
});
