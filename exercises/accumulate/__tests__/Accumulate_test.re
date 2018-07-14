open Jest;
open Expect;
open Accumulate;

let square = (x: int) : int => x * x;

let reverse = (x: string) : string =>
  x
  |> Js.String.split("")
  |> Js.Array.reverseInPlace
  |> Js.Array.joinWith("");



describe("Accumulate", () => {
  test("[] Accumulate", () =>
    expect(accumulate(square, [])) |> toEqual([])
  );
  test("square Accumulate", () =>
    expect(accumulate(square, [1, 2, 3])) |> toEqual([1, 4, 9])
  );
  test("toUpper Accumulate", () =>
    expect(accumulate(String.uppercase, ["hello", "world"]))
    |> toEqual(["HELLO", "WORLD"])
  );
  test("reverse Accumulate", () =>
    expect(accumulate(reverse, ["hello", "world"]))
    |> toEqual(["olleh", "dlrow"])
  );
});
