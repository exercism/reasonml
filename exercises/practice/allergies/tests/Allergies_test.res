open Test;
open Allergies;

let boolEqual = (~message=?, a: bool, b: bool) =>
  assertion(~message?, ~operator="boolEqual", (a, b) => a == b, a, b)

let arrayEqual = (~message=?, a: array<'a>, b: array<'a>) =>
  assertion(~message?, ~operator="arrayEqual", (a, b) => a == b, a, b)

test("no allergies -> peanuts", () => boolEqual(isAllergicTo("peanuts", 0), false))
test("no allergies -> cats", () => boolEqual(isAllergicTo("cats", 0), false))
test("no allergies -> strawberries", () => boolEqual(isAllergicTo("strawberries", 0), false))

test("is allergic to eggs", () => boolEqual(isAllergicTo("eggs", 1), true))

test("has right allergies -> eggs", () => boolEqual(isAllergicTo("eggs", 5), true))
test("has right allergies -> shellfish", () => boolEqual(isAllergicTo("shellfish", 5), true))
test("has right allergies -> strawberries", () => boolEqual(isAllergicTo("strawberries", 5), false))

test("toList -> no allergies at all", () => arrayEqual(toList(0), []))
test("toList -> allergies to just peanuts", () => arrayEqual(toList(2), ["peanuts"]))
test("toList -> allergies to everything", () => {
  arrayEqual(toList(255), ["eggs", "peanuts", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"])
})
test("toList -> ignore non allergen score parts", () => arrayEqual(toList(257), ["eggs"]))
test("toList -> ignore all non allergen score parts", () => {
  arrayEqual(toList(509), ["eggs", "shellfish", "strawberries", "tomatoes", "chocolate", "pollen", "cats"])
})
