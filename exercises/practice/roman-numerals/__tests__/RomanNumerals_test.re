open Jest;
open Expect;
open RomanNumerals;

describe("RomanNumerals", () => {
  test("1 is I", () =>
    expect(toRoman(1)) |> toEqual("I")
  );
  test("2 is II", () =>
    expect(toRoman(2)) |> toEqual("II") 
  );
  test("3 is III", () =>
    expect(toRoman(3)) |> toEqual("III") 
  );
  test("4 is IV", () =>
    expect(toRoman(4)) |> toEqual("IV")
  );
  test("5 is V", () =>
    expect(toRoman(5)) |> toEqual("V") 
  );
  test("6 is VI", () =>
    expect(toRoman(6)) |> toEqual("VI") 
  );
  test("9 is IX", () =>
    expect(toRoman(9)) |> toEqual("IX") 
  );
  test("16 is XVI", () =>
    expect(toRoman(16)) |> toEqual("XVI") 
  );
  test("27 is XXVII", () =>
    expect(toRoman(27)) |> toEqual("XXVII")
  );
  test("48 is XLVIII", () =>
    expect(toRoman(48)) |> toEqual("XLVIII") 
  );
  test("49 is XLIX", () =>
    expect(toRoman(49)) |> toEqual("XLIX") 
  );
  test("59 is LIX", () =>
    expect(toRoman(59)) |> toEqual("LIX") 
  );
  test("66 is LXVI", () =>
    expect(toRoman(66)) |> toEqual("LXVI") 
  );
  test("93 is XCIII", () =>
    expect(toRoman(93)) |> toEqual("XCIII") 
  );
  test("141 is CXLI", () =>
    expect(toRoman(141)) |> toEqual("CXLI") 
  );
  test("163 is CLXIII", () =>
    expect(toRoman(163)) |> toEqual("CLXIII") 
  );
  test("166 is CLXVI", () =>
    expect(toRoman(166)) |> toEqual("CLXVI") 
  );
  test("402 is CDII", () =>
    expect(toRoman(402)) |> toEqual("CDII") 
  );
  test("575 is DLXXV", () =>
    expect(toRoman(575)) |> toEqual("DLXXV") 
  );
  test("666 is DCLXVI", () =>
    expect(toRoman(666)) |> toEqual("DCLXVI") 
  );
  test("911 is CMXI", () =>
    expect(toRoman(911)) |> toEqual("CMXI")
  );
  test("1024 is MXXIV", () =>
    expect(toRoman(1024)) |> toEqual("MXXIV")
  );
  test("1666 is MDCLXVI", () =>
    expect(toRoman(1666)) |> toEqual("MDCLXVI")
  );
  test("3000 is MMM", () =>
    expect(toRoman(3000)) |> toEqual("MMM")
  );
  test("3001 is MMMI", () =>
    expect(toRoman(3001)) |> toEqual("MMMI")
  );
  test("3888 is MMMDCCCLXXXVIII", () =>
    expect(toRoman(3888)) |> toEqual("MMMDCCCLXXXVIII")
  );
  test("3999 is MMMCMXCIX", () =>
    expect(toRoman(3999)) |> toEqual("MMMCMXCIX")
  );
});

