open Jest;
open Expect;

describe("Leap", () => {
  test("year not divisible by 4: common year", () =>
    expect(Leap.is_leap_year(2015)) |> toBe(false)
  );
  test("year divisible by 4, not divisible by 100: leap year", () =>
    expect(Leap.is_leap_year(1996)) |> toBe(true)
  );
  test("year divisible by 100, not divisible by 400: common year", () =>
    expect(Leap.is_leap_year(2100)) |> toBe(false)
  );
  test("year divisible by 400: leap year", () =>
    expect(Leap.is_leap_year(2000)) |> toBe(true)
  );
})