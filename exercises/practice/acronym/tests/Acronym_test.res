open Test
open Acronym

let stringEqual = (~message=?, a: string, b: string) =>
  assertion(~message?, ~operator="stringEqual", (a, b) => a == b, a, b)

test("Acronym basic", () => {
  stringEqual(abbreviate("Portable Network Graphics"), "PNG")
})

test("Acronym for lowercase words", () => {
  stringEqual(abbreviate("Ruby on Rails"), "ROR")
})

test("Acronym with punctuation", () => {
  stringEqual(abbreviate("First In, First Out"), "FIFO")
})

test("Acronym with all caps word", () => {
  stringEqual(abbreviate("GNU Image Manipulation Program"), "GIMP")
})

test("Acronym for punctuation without whitespace", () => {
  stringEqual(abbreviate("Complementary metal-oxide semiconductor"), "CMOS")
})
