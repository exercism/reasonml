open Jest;
open Expect;
open EliudsEggs;

describe("Eliud's Eggs", () => {
  test("0 eggs", () =>
    expect(eggCount(0)) |> toEqual(0)
  );
  test("1 egg", () =>
    expect(eggCount(16)) |> toEqual(1)
  );
  test("4 eggs", () =>
    expect(eggCount(89)) |> toEqual(4)
  );
  test("13 eggs", () =>
    expect(eggCount(2000000000)) |> toEqual(13)
  );
});
