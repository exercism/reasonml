open Jest;
open Expect;
open ScrabbleScore;

describe("Scrabble-score", () => {
  test("lowercase letter", () =>
    expect(ScrabbleScore.score("a")) |> toEqual(1)
  );
  test("uppercase letter", () =>
    expect(ScrabbleScore.score("A")) |> toEqual(1)
  );
  test("valuable letter", () =>
      expect(ScrabbleScore.score("f")) |> toEqual(4)
  );
  test("short word", () =>
      expect(ScrabbleScore.score("at")) |> toEqual(2)
  );
  test("short, valuable word", () =>
      expect(ScrabbleScore.score("zoo")) |> toEqual(12)
  );
  test("medium word", () =>
      expect(ScrabbleScore.score("street")) |> toEqual(6)
  );
  test("medium, valuable word", () =>
      expect(ScrabbleScore.score("quirky")) |> toEqual(22)
  );
  test("long, mixed-case word", () =>
      expect(ScrabbleScore.score("OxyphenButazone")) |> toEqual(41)
  );
  test("english-like word", () =>
      expect(ScrabbleScore.score("pinata")) |> toEqual(8)
  );
  test("empty input", () =>
      expect(ScrabbleScore.score("")) |> toEqual(0)
  );
  test("entire alphabet available", () =>
      expect(ScrabbleScore.score("abcdefghijklmnopqrstuvwxyz")) |> toEqual(87)
  );
})
