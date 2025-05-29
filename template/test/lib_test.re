open Fest;

test("1+1=2", () =>
  expect |> equal(1 + 1, 2)
);

test("Hello world", () =>
  expect |> equal("World", Lib.name)
);
