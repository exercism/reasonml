open Jest;
open Expect;
open PhoneNumber;

describe("PhoneNumber", () => {
  test("cleans the number", () =>
    expect(phoneNumber("(223) 456-7890")) |> toEqual(Some("2234567890"))
  );
  test("cleans numbers with dots", () =>
    expect(phoneNumber("223.456.7890")) |> toEqual(Some("2234567890"))
  );
  test("cleans numbers with multiple spaces", () =>
    expect(phoneNumber("223 456   7890   ")) |> toEqual(Some("2234567890"))
  );
  test("invalid when 9 digits", () =>
    expect(phoneNumber("123456789")) |> toEqual(None)
  );
  test("invalid when 11 digits does not start with a 1", () =>
    expect(phoneNumber("22234567890")) |> toEqual(None)
  );
  test("valid when 11 digits and starting with 1", () =>
    expect(phoneNumber("12234567890")) |> toEqual(Some("2234567890"))
  );
  test("valid when 11 digits and starting with 1 even with punctuation", () =>
    expect(phoneNumber("+1 (223) 456-7890")) |> toEqual(Some("2234567890"))
  );
  test("invalid when more than 11 digits", () =>
    expect(phoneNumber("321234567890")) |> toEqual(None)
  );
  test("invalid with letters", () =>
    expect(phoneNumber("123-abc-7890")) |> toEqual(None)
  );
  test("invalid with punctuations", () =>
    expect(phoneNumber("123-@:!-7890")) |> toEqual(None)
  );
  test("invalid if area code starts with 0", () =>
    expect(phoneNumber("(023) 456-7890")) |> toEqual(None)
  );
  test("invalid if area code starts with 1", () =>
    expect(phoneNumber("(123) 456-7890")) |> toEqual(None)
  );
  test("invalid if exchange code starts with 0", () =>
    expect(phoneNumber("(123) 056-7890")) |> toEqual(None)
  );
  test("invalid if exchange code starts with 1", () =>
    expect(phoneNumber("(123) 156-7890")) |> toEqual(None)
  );
});
