open Jest;
open Expect;
open Triangle;



describe("Triangle", () => {
  test("all sides are equal", () =>
    expect(is_equilateral(2, 2, 2)) |> toBe(true));

  test("any side is unequal", () =>
    expect(is_equilateral(2, 3, 2) |> toBe(false));

  test("no sides are equal", () =>
    expect(is_equilateral(5, 4, 6) |> toBe(false));

  test("all zero sides is not a triangle", () =>
    expect(is_equilateral(0, 0, 0) |> toBe(false));

  test("last two sides are equal", () =>
    expect(is_isosceles(4, 4, 3) |> toBe(true));

  test("first and last sides are equal", () =>
    expect(is_isosceles(4, 3, 4) |> toBe(true));

  test("equilateral triangles are also isosceles", () =>
    expect(is_isosceles(4, 4, 4) |> toBe(true));

  test("no sides are equal", () =>
    expect(is_isosceles(2, 3, 4) |> toBe(false));

  test("first triangle inequality violation", () =>
    expect(is_isosceles(1, 1, 3) |> toBe(false));

  test("second triangle inequality violation", () =>
    expect(is_isosceles(1, 3, 1) |> toBe(false));

  test("third triangle inequality violation", () =>
    expect(is_isosceles(3, 1, 1) |> toBe(false));

  test("no sides are equal", () =>
    expect(is_scalene(5, 4, 6) |> toBe(true));

  test("all sides are equal", () =>
    expect(is_scalene(4, 4, 4) |> toBe(false));

  test("first and second sides are equal", () =>
    expect(is_scalene(4, 4, 3) |> toBe(false));

  test("first and third sides are equal", () =>
    expect(is_scalene(3, 4, 3) |> toBe(false));

  test("second and third sides are equal", () =>
    expect(is_scalene(4, 3, 3) |> toBe(false));

  test("may not violate triangle inequality", () =>
    expect(is_scalene(7, 3, 2) |> toBe(false));
});
