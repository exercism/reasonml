open Jest;
open Expect;
open Acronym;

describe("Acronym", () => {
  test("basic", () =>
    expect(abbreviate("Portable Network Graphics")) |> toEqual("PNG")
  );
  test("lowercase words", () =>
    expect(abbreviate("Ruby on Rails")) |> toEqual("ROR")
  );
  test("punctuation", () =>
    expect(abbreviate("First In, First Out")) |> toEqual("FIFO")
  );
  test("all caps word", () =>
    expect(abbreviate("GNU Image Manipulation Program")) |> toEqual("GIMP")
  );
  test("punctuation without whitespace", () =>
    expect(abbreviate("Complementary metal-oxide semiconductor")) |> toEqual("CMOS")
  );
});
