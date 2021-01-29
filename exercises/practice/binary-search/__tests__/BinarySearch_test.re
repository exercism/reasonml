open Jest;
open Expect;
open BinarySearch;

describe("Binary search", () => {
  test("finds a value in an array with one element", () =>
    expect(find([|6|], 6)) |> toEqual(Some(0))
  );
  test("finds a value in the middle of an array", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 6)) |> toEqual(Some(3))
  );
  test("finds a value at the beginning of an array", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 1)) |> toEqual(Some(0))
  );
  test("finds a value at the end of an array", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 11)) |> toEqual(Some(6))
  );
  test("finds a value in an array of odd length", () => 
    expect(find([|1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377, 634|], 144)) |> toEqual(Some(9))
  );
  test("finds a value in an array of even length", () => 
    expect(find([|1, 3, 5, 8, 13, 21, 34, 55, 89, 144, 233, 377|], 21)) |> toEqual(Some(5))
  );
  test("identifies that a value is not included in the array", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 7)) |> toEqual(None)
  );
  test("a value smaller than the array's smallest value is not included", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 0)) |> toEqual(None)
  );
  test("a value larger than the array's largest value is not included", () => 
    expect(find([|1, 3, 4, 6, 8, 9, 11|], 13)) |> toEqual(None)
  );
  test("nothing is included in an empty array", () => 
    expect(find([||], 1)) |> toEqual(None)
  );
});



