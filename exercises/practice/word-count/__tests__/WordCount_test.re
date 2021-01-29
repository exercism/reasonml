open Jest;
open Expect;
open WordCount;

describe("Word Count", () => {
  test("count one word", () => {
    let expected = Js.Dict.fromArray([|("word", 1)|]);
    expect(wordCount("word")) |> toEqual(expected)
  });
  test("multiple occurrences of a word", () => {
    let expected = Js.Dict.fromArray([|
      ("one", 1),
      ("fish", 4),
      ("two", 1),
      ("red", 1),
      ("blue", 1),
    |]);

    expect(wordCount("one fish two fish red fish blue fish"))
    |> toEqual(expected);
  });
  test("handles expanded lists", () => {
    let expected = Js.Dict.fromArray([|("one", 1), ("two", 1), ("three", 1)|]);

    expect(wordCount("one,\ntwo,\nthree")) |> toEqual(expected);
  });
  test("ignore punctuation", () => {
    let expected = Js.Dict.fromArray([|
      ("car", 1),
      ("carpet", 1),
      ("as", 1),
      ("java", 1),
      ("javascript", 1),
    |]);

    expect(wordCount("car: carpet as java: javascript!!&@$%^&"))
    |> toEqual(expected);
  });
  test("include numbers", () => {
    let expected = Js.Dict.fromArray([|("1", 1), ("2", 1), ("testing", 2)|]);

    expect(wordCount("testing, 1, 2 testing")) |> toEqual(expected);
  });
  test("normalize case", () => {
    let expected = Js.Dict.fromArray([|("go", 3), ("stop", 2)|]);

    expect(wordCount("go Go GO Stop stop")) |> toEqual(expected);
  });
  test("with apostrophes", () => {
    let expected = Js.Dict.fromArray([|
      ("first", 1),
      ("don't", 2),
      ("laugh", 1),
      ("then", 1),
      ("cry", 1),
    |]);

    expect(wordCount("First: don't laugh. Then: don't cry."))
    |> toEqual(expected);
  });
  test("with quotations", () => {
    let expected = Js.Dict.fromArray([|
      ("joe", 1),
      ("can't", 1),
      ("tell", 1),
      ("between", 1),
      ("large", 2),
      ("and", 1),
    |]);

    expect(wordCount("Joe can't tell between 'large' and large."))
    |> toEqual(expected);
  });
  test("multiple spaces not detected as a word", () => {
    let expected = Js.Dict.fromArray([|("multiple", 1), ("whitespaces", 1)|]);

    expect(wordCount(" multiple   whitespaces")) |> toEqual(expected);
  });
});
