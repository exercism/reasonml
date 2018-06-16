open Jest;
open Expect;
open RunLengthEncoding;

describe("encode function", () => {
  test("empty string", () =>
    expect(encode("")) |> toBe("")
  );
  test("single characters only are encoded without count", () =>
    expect(encode("XYZ")) |> toBe("XYZ")
  );
  test("string with no single characters", () =>
    expect(encode("AABBBCCCC")) |> toBe("2A3B4C")
  );
  test("single characters mixed with repeated characters", () =>
    expect(encode("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB")) |> toBe("12WB12W3B24WB")
  );
  test("multiple whitespace mixed in string", () =>
    expect(encode("  hsqq qww  ")) |> toBe("2 hs2q q2w2 ")
  );
  test("lowercase characters", () =>
    expect(encode("aabbbcccc")) |> toBe("2a3b4c")
  );
});

describe("decode function", () => {
  test("empty string", () =>
    expect(decode("")) |> toBe("")
  );
  test("single characters only", () =>
    expect(decode("XYZ")) |> toBe("XYZ")
  );
  test("string with no single characters", () =>
    expect(decode("2A3B4C")) |> toBe("AABBBCCCC")
  );
  test("single characters with repeated characters", () =>
    expect(decode("12WB12W3B24WB")) |> toBe("WWWWWWWWWWWWBWWWWWWWWWWWWBBBWWWWWWWWWWWWWWWWWWWWWWWWB")
  );
  test("multiple whitespace mixed in string", () =>
    expect(decode("2 hs2q q2w2 ")) |> toBe("  hsqq qww  ")
  );
  test("lower case string", () =>
    expect(decode("2a3b4c")) |> toBe("aabbbcccc")
  );
});

describe("Encode/decode are inverse operations", () => {
  test("encode(followed by decode gives original string", () =>
    expect(encode("zzz ZZ  zZ") |> decode) |> toBe("zzz ZZ  zZ")
  );
});