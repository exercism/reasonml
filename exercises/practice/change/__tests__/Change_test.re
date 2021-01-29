open Jest;
open Expect;
open Change;

describe("Change", () => {
  test("single coin change", () =>
    expect(makeChange(25, [1, 5, 10, 25, 100])) |> toEqual(Some([25]))
  );
  test("multiple coin change", () =>
    expect(makeChange(15, [1, 5, 10, 25, 100])) |> toEqual(Some([5, 10]))
  );
  test("change with Lilliputian Coins", () =>
    expect(makeChange(23, [1, 4, 15, 20, 50])) |> toEqual(Some([4, 4, 15]))
  );
  test("change with Lower Elbonia Coins", () =>
    expect(makeChange(63, [1, 5, 10, 21, 25])) |> toEqual(Some([21, 21, 21]))
  );
  test("large target values", () =>
    expect(makeChange(999, [1, 2, 5, 10, 20, 50, 100])) |> toEqual(Some([2, 2, 5, 20, 20, 50, 100, 100, 100, 100, 100, 100, 100, 100, 100]))
  );
  test("possible change without unit coins available", () =>
    expect(makeChange(21, [2, 5, 10, 20, 50])) |> toEqual(Some([2, 2, 2, 5, 10]))
  );
  test("another possible change without unit coins available", () =>
    expect(makeChange(27, [4, 5])) |> toEqual(Some([4, 4, 4, 5, 5, 5]))
  );
  test("no coins make 0 change", () =>
    expect(makeChange(0, [1, 5, 10, 21, 25])) |> toEqual(Some([]))
  );
  test("error testing for change smaller than the smallest of coins", () =>
    expect(makeChange(3, [5, 10])) |> toEqual(None)
  );
  test("error if no combination can add up to target", () =>
    expect(makeChange(94, [5, 10])) |> toEqual(None)
  );
  test("cannot find negative change values", () =>
    expect(makeChange((-5), [1, 2, 5])) |> toEqual(None)
  );
});