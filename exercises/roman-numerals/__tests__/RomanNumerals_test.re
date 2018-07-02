open Jest;
open Expect;
open RomanNumerals;

describe("RomanNumerals", () => {
  test("1 is a single I", () =>
    expect(toRoman(1)) |> toEqual("I")
  );
  test("2 is two I's", () =>
    expect(toRoman(2)) |> toEqual("II") 
  );
  test("3 is three I's", () =>
    expect(toRoman(3)) |> toEqual("III") 
  );
  test("4, being 5 - 1, is IV", () =>
    expect(toRoman(4)) |> toEqual("IV")
  );
  test("5 is a single V", () =>
    expect(toRoman(5)) |> toEqual("V") 
  );
  test("6, being 5 + 1, is VI", () =>
    expect(toRoman(6)) |> toEqual("VI") 
  );
  test("9, being 10 - 1, is IX", () =>
    expect(toRoman(9)) |> toEqual("IX") 
  );
  test("20 is two X's", () =>
    expect(toRoman(27)) |> toEqual("XXVII")
  );
  test("48 is not 50 - 2 but rather 40 + 8", () =>
    expect(toRoman(48)) |> toEqual("XLVIII") 
  );
  test("49 is not 40 + 5 + 4 but rather 50 - 10 + 10 - 1", () =>
    expect(toRoman(49)) |> toEqual("XLIX") 
  );
  test("50 is a single L", () =>
    expect(toRoman(59)) |> toEqual("LIX") 
  );
  test("90, being 100 - 10, is XC", () =>
    expect(toRoman(93)) |> toEqual("XCIII") 
  );
  test("100 is a single C", () =>
    expect(toRoman(141)) |> toEqual("CXLI") 
  );
  test("60, being 50 + 10, is LX", () =>
    expect(toRoman(163)) |> toEqual("CLXIII") 
  );
  test("400, being 500 - 100, is CD", () =>
    expect(toRoman(402)) |> toEqual("CDII") 
  );
  test("500 is a single D", () =>
    expect(toRoman(575)) |> toEqual("DLXXV") 
  );
  test("900, being 1000 - 100, is CM", () =>
    expect(toRoman(911)) |> toEqual("CMXI")
  );
  test("1000 is a single M", () =>
    expect(toRoman(1024)) |> toEqual("MXXIV")
  );
  test("3000 is three M's", () =>
    expect(toRoman(3000)) |> toEqual("MMM")
  );
});

