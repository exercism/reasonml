open Test
open WordCount

let dictEqual = (~message=?, a: Js.Dict.t<'a>, b: Js.Dict.t<'a>) =>
  assertion(~message?, ~operator="dictEqual", (a, b) => a == b, a, b)

test("count one word", () => {
  let expected = Js.Dict.fromArray([("word", 1)])
  dictEqual(wordCount("word"), expected)
})

test("multiple occurrences of a word", () => {
  let expected = Js.Dict.fromArray([("one", 1), ("fish", 4), ("two", 1), ("red", 1), ("blue", 1)])

  dictEqual(wordCount("one fish two fish red fish blue fish"), expected)
})

test("handles expanded lists", () => {
  let expected = Js.Dict.fromArray([("one", 1), ("two", 1), ("three", 1)])

  dictEqual(wordCount("one,\ntwo,\nthree"), expected)
})

test("ignore punctuation", () => {
  let expected = Js.Dict.fromArray([
    ("car", 1),
    ("carpet", 1),
    ("as", 1),
    ("java", 1),
    ("javascript", 1),
  ])

  dictEqual(wordCount("car: carpet as java: javascript!!&@$%^&"), expected)
})

test("include numbers", () => {
  let expected = Js.Dict.fromArray([("1", 1), ("2", 1), ("testing", 2)])

  dictEqual(wordCount("testing, 1, 2 testing"), expected)
})

test("normalize case", () => {
  let expected = Js.Dict.fromArray([("go", 3), ("stop", 2)])

  dictEqual(wordCount("go Go GO Stop stop"), expected)
})

test("with apostrophes", () => {
  let expected = Js.Dict.fromArray([
    ("first", 1),
    ("don't", 2),
    ("laugh", 1),
    ("then", 1),
    ("cry", 1),
  ])

  dictEqual(wordCount("First: don't laugh. Then: don't cry."), expected)
})

test("with quotations", () => {
  let expected = Js.Dict.fromArray([
    ("joe", 1),
    ("can't", 1),
    ("tell", 1),
    ("between", 1),
    ("large", 2),
    ("and", 1),
  ])

  dictEqual(wordCount("Joe can't tell between 'large' and large."), expected)
})

test("multiple spaces not detected as a word", () => {
  let expected = Js.Dict.fromArray([("multiple", 1), ("whitespaces", 1)])

  dictEqual(wordCount(" multiple   whitespaces"), expected)
})
