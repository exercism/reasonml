open Jest;
open Expect;

describe("Example", () => {
  test("basic", () =>
    expect(1 + 1) |> toEqual(2)
  )
});
