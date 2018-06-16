open Jest;
open Expect;
open Leap;

describe("Leap", () => {
  test("year not divisible by 4: common year", () =>
    expect(isLeapYear(2015)) |> toBe(false)
  );
  test("year divisible by 4, not divisible by 100: leap year", () =>
    expect(isLeapYear(1996)) |> toBe(true)
  );
  test("year divisible by 100, not divisible by 400: common year", () =>
    expect(isLeapYear(2100)) |> toBe(false)
  );
  test("year divisible by 400: leap year", () =>
    expect(isLeapYear(2000)) |> toBe(true)
  );
})