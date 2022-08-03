open Test
open Leap

let boolEqual = (~message=?, a: bool, b: bool) =>
  assertion(~message?, ~operator="boolEqual", (a, b) => a == b, a, b)

test("year not divisible by 4 in common year", () => boolEqual(isLeapYear(2015), false))
test("year divisible by 2, not divisible by 4 in common year", () =>
  boolEqual(isLeapYear(1970), false)
)
test("year divisible by 4, not divisible by 100 in leap year", () =>
  boolEqual(isLeapYear(1996), true)
)
test("year divisible by 4 and 5 is still a leap year", () => boolEqual(isLeapYear(1960), true))
test("year divisible by 100, not divisible by 400 in common year", () =>
  boolEqual(isLeapYear(2100), false)
)
test("year divisible by 100 but not by 3 is still not a leap year", () =>
  boolEqual(isLeapYear(1900), false)
)
test("year divisible by 400 in leap year", () => boolEqual(isLeapYear(2000), true))
test("year divisible by 400 but not by 125 is still a leap year", () =>
  boolEqual(isLeapYear(2400), true)
)
test("year divisible by 200, not divisible by 400 in common year", () =>
  boolEqual(isLeapYear(1800), false)
)
