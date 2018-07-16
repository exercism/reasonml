open Jest;
open Expect;
open Allergies;

describe("Allergies", () =>
  describe("isAllergicTo", () => {
    describe("no Allergies means not allergic", () => {
      test("peanuts", () =>
        expect(isAllergicTo("peanuts", 0)) |> toBe(false)
      );
      test("cats", () =>
        expect(isAllergicTo("cats", 0)) |> toBe(false)
      );
      test("strawberries", () =>
        expect(isAllergicTo("strawberries", 0)) |> toBe(false)
      );
    });
    test("is allergic to eggs", () =>
      expect(isAllergicTo("eggs", 1)) |> toBe(true)
    );
    describe("has the right allergies", () => {
      test("eggs", () =>
        expect(isAllergicTo("eggs", 5)) |> toBe(true)
      );
      test("shellfish", () =>
        expect(isAllergicTo("shellfish", 5)) |> toBe(true)
      );
      test("strawberries", () =>
        expect(isAllergicTo("strawberries", 5)) |> toBe(false)
      );
    });
    describe("toList", () => {
      test("no allergies at all", () =>
        expect(toList(0)) |> toEqual([])
      );
      test("allergic to just peanuts", () =>
        expect(toList(2)) |> toEqual(["peanuts"])
      );
      test("allergic to everything", () =>
        expect(toList(255))
        |> toEqual([
             "eggs",
             "peanuts",
             "shellfish",
             "strawberries",
             "tomatoes",
             "chocolate",
             "pollen",
             "cats",
           ])
      );
      test("ignore non allergen score parts", () =>
        expect(toList(257)) |> toEqual(["eggs"])
      );
      test("ignore all non allergen score parts", () =>
        expect(toList(509))
        |> toEqual([
             "eggs",
             "shellfish",
             "strawberries",
             "tomatoes",
             "chocolate",
             "pollen",
             "cats",
           ])
      );
    });
  })
);
