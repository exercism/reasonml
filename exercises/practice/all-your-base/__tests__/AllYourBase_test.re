open Jest;
open Expect;
open AllYourBase;

describe("all-your-base", () => {
  test("single bit one to decimal", () =>
    expect(rebase(2, [1], 100)) |> toEqual(Some([1]))
  );
  test("binary to single decimal", () =>
    expect(rebase(2, [1, 0, 1], 10)) |> toEqual(Some([5]))
  );
  test("single decimal to binary", () =>
    expect(rebase(10, [5], 2)) |> toEqual(Some([1, 0, 1]))
  );
  test("binary to multiple decimal", () =>
    expect(rebase(2, [1, 0, 1, 0, 1, 0], 10)) |> toEqual(Some([4, 2]))
  );
  test("decimal to binary", () =>
    expect(rebase(10, [4, 2], 2)) |> toEqual(Some([1, 0, 1, 0, 1, 0]))
  );
  test("trinary to hexadecimal", () =>
    expect(rebase(3, [1, 1, 2, 0], 16)) |> toEqual(Some([2, 10]))
  );
  test("hexadecimal to trinary", () =>
    expect(rebase(16, [2, 10], 3)) |> toEqual(Some([1, 1, 2, 0]))
  );
  test("15-bit integer", () =>
    expect(rebase(97, [3, 46, 60], 73)) |> toEqual(Some([6, 10, 45]))
  );
  test("empty list", () =>
    expect(rebase(2, [], 10)) |> toEqual(None)
  );
  test("single zero", () =>
    expect(rebase(10, [0], 2)) |> toEqual(None)
  );
  test("multiple zeros", () =>
    expect(rebase(10, [0, 0, 0], 2)) |> toEqual(None)
  );
  test("leading zeros", () =>
    expect(rebase(7, [0, 6, 0], 10)) |> toEqual(Some([4, 2]))
  );
  test("first base is zero", () =>
    expect(rebase(0, [], 10)) |> toEqual(None)
  );
  test("first base is negative", () =>
    expect(rebase(-1, [], 10)) |> toEqual(None)
  );
  test("negative digit", () =>
    expect(rebase(2, [1, (-1), 1, 0, 1, 0], 10)) |> toEqual(None)
  );
  test("invalid positive digit", () =>
    expect(rebase(2, [1, 2, 1, 0, 1, 0], 10)) |> toEqual(None)
  );
  test("second base is one", () =>
    expect(rebase(10, [], 1)) |> toEqual(None)
  );
  test("second base is zero", () =>
    expect(rebase(10, [1], 0)) |> toEqual(None)
  );
  test("second base is negative", () =>
    expect(rebase(10, [1], -1)) |> toEqual(None)
  );
  test("both bases are negative", () =>
    expect(rebase(-1, [1], -1)) |> toEqual(None)
  );
});
