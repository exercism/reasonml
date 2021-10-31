open Test
open ArmstrongNumbers

let boolEqual = (~message=?, a: bool, b: bool) =>
  assertion(~message?, ~operator="boolEqual", (a, b) => a == b, a, b)  
  
test("Single digit numbers are Armstrong numbers", () =>
  boolEqual(validate(5), true)
)

test("There are no 2 digit Armstrong numbers", () =>
  boolEqual(validate(10), false)
)

test("Three digit number that is an Armstrong number", () =>
  boolEqual(validate(153), true)
)

test("Three digit number that is not an Armstrong number", () =>
  boolEqual(validate(100), false)
)

test("Four digit number that is an Armstrong number", () =>
  boolEqual(validate(9474), true)
);

test("Four digit number that is not an Armstrong number", () =>
  boolEqual(validate(9475), false)
)

test("Seven digit number that is an Armstrong number", () =>
  boolEqual(validate(9926315), true)
)

test("Seven digit number that is not an Armstrong number", () =>
  boolEqual(validate(9926314), false)
)
