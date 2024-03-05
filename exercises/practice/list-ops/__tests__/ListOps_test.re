open Jest;
open Expect;
open ListOps;

describe("append entries to a list and return the new list", () => {
  test("empty lists", () =>
    expect(append([], [])) |> toEqual([])
  );
  test("list to empty list", () =>
    expect(append([], [1, 2, 3, 4])) |> toEqual([1, 2, 3, 4])
  );
  test("empty list to list", () =>
    expect(append([1, 2, 3, 4], [])) |> toEqual([1, 2, 3, 4])
  );
  test("non-empty list", () =>
    expect(append([1, 2], [2, 3, 4, 5])) |> toEqual([1, 2, 2, 3, 4, 5])
  );
});

describe("concatenate a list of lists", () => {
  test("empty list", () =>
    expect(concat([])) |> toEqual([])
  );
  test("list of lists", () =>
    expect(concat([[1, 2], [3], [], [4, 5, 6]]))
    |> toEqual([1, 2, 3, 4, 5, 6])
  );
  test("list of nested lists", () => {
    expect(concat([[[1], [2]], [[3]], [[]], [[4, 5, 6]]]))
    |> toEqual([[1], [2], [3], [], [4, 5, 6]])
  });
});

describe(
  "filter list returning only values that satisfy the filter function", () => {
  test("empty list", () => {
    expect(filter([], x => x mod 2 == 1)) |> toEqual([])
  });
  test("non-empty list", () => {
    expect(filter([1, 2, 3, 5], x => x mod 2 == 1)) |> toEqual([1, 3, 5])
  });
});

describe("returns the length of a list", () => {
  test("empty list", () => {
    expect(length([])) |> toEqual(0)
  });
  test("non-empty list", () => {
    expect(length([1, 2, 3, 4])) |> toEqual(4)
  });
});

describe(
  "return a list of elements whose values equal the list value transformed by the mapping function",
  () => {
    test("empty list", () => {
      expect(map([], x => x + 1)) |> toEqual([])
    });
    test("non-empty list", () => {
      expect(map([1, 3, 5, 7], x => x + 1)) |> toEqual([2, 4, 6, 8])
    });
  },
);

describe("folds (reduces) the given list from the left with a function", () => {
  test("empty list", () => {
    expect(foldl([], 2, (acc, elem) => elem * acc)) |> toEqual(2)
  });
  test("direction independent function applied to non-empty list", () => {
    expect(foldl([1, 2, 3, 4], 5, (acc, elem) => elem + acc))
    |> toEqual(15)
  });
  test("direction dependent function applied to non-empty list", () => {
    expect(foldl([1.0, 2.0, 3.0, 4.0], 24.0, (acc, elem) => elem /. acc))
    |> toEqual(64.0)
  });
});

describe("folds (reduces) the given list from the right with a function", () => {
  test("empty list", () => {
    expect(foldr([], 2, (acc, elem) => elem * acc)) |> toEqual(2)
  });
  test("direction independent function applied to non-empty list", () => {
    expect(foldr([1, 2, 3, 4], 5, (acc, elem) => elem + acc))
    |> toEqual(15)
  });
  test("direction dependent function applied to non-empty list", () => {
    expect(foldr([1.0, 2.0, 3.0, 4.0], 24.0, (acc, elem) => elem /. acc))
    |> toEqual(9.0)
  });
});

describe("reverse the elements of the list", () => {
  test("empty list", () => {
    expect(reverse([])) |> toEqual([])
  });
  test("non-empty list", () => {
    expect(reverse([1, 3, 5, 7])) |> toEqual([7, 5, 3, 1])
  });
  test("list of lists is not flattened", () => {
    expect(reverse([[1, 2], [3], [], [4, 5, 6]]))
    |> toEqual([[4, 5, 6], [], [3], [1, 2]])
  });
});
