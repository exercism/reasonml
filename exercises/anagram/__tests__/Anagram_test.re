open Jest;
open Expect;
open Anagram;

describe("Anagram", () => {
  test("no matches", () =>
    expect(anagrams("diaper", ["hello", "world", "zombies", "pants"])) |> toEqual([])
  );
  test("detects two anagrams", () =>
    expect(anagrams("master", ["stream", "pigeon", "maters"])) |> toEqual(["stream", "maters"])
  );
  test("does not detect anagram subsets", () =>
    expect(anagrams("good", ["dog", "goody"]))  |> toEqual([])
  );
  test("detects anagram", () =>
    expect(anagrams("listen", ["enlists", "google", "inlets", "banana"]))  |> toEqual(["inlets"])
  );
  test("detects three anagrams", () =>
    expect(anagrams("allergy", ["gallery", "ballerina", "regally", "clergy", "largely", "leading"]))  |> toEqual(["gallery", "regally", "largely"])
  );
  test("does not detect non-anagrams(with identical checksum", () =>
    expect(anagrams("mass", ["last"]))  |> toEqual([])
  );
  test("detects anagrams(case-insensitively", () =>
    expect(anagrams("Orchestra", ["cashregister", "Carthorse", "radishes"]))  |> toEqual(["Carthorse"])
  );
  test("detects anagrams(using case-insensitive subject", () =>
    expect(anagrams("Orchestra", ["cashregister", "carthorse", "radishes"])) |> toEqual(["carthorse"])
  );
  test("detects anagrams(using case-insensitive possible matches", () =>
    expect(anagrams("orchestra", ["cashregister", "Carthorse", "radishes"])) |> toEqual(["Carthorse"])
  );
  test("does not detect a anagram if the original word is repeated", () =>
    expect(anagrams("go", ["go Go GO"])) |> toEqual([])
  );
  test("anagrams(must use all letters exactly once", () =>
    expect(anagrams("tapper", ["patter"])) |> toEqual([])
  );
  test("capital word is not own anagram", () =>
    expect(anagrams("BANANA", ["Banana"])) |> toEqual([])
  );
})


