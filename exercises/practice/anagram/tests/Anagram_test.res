open Test
open Anagram

let arrayEqual = (~message=?, a: array<'a>, b: array<'a>) =>
  assertion(~message?, ~operator="arrayEqual", (a, b) => a == b, a, b)

test("no matches", () => arrayEqual(anagrams("diaper", ["hello", "world", "zombies", "pants"]), []))

test("detects two anagrams", () =>
  arrayEqual(anagrams("master", ["stream", "pigeon", "maters"]), ["stream", "maters"])
)

test("does not detect anagram subsets", () => arrayEqual(anagrams("good", ["dog", "goody"]), []))

test("detects anagram", () =>
  arrayEqual(anagrams("listen", ["enlists", "google", "inlets", "banana"]), ["inlets"])
)

test("detects three anagrams", () =>
  arrayEqual(
    anagrams("allergy", ["gallery", "ballerina", "regally", "clergy", "largely", "leading"]),
    ["gallery", "regally", "largely"],
  )
)

test("detects multiple anagrams with different case", () =>
  arrayEqual(anagrams("nose", ["Eons", "ONES"]), ["Eons", "ONES"])
)

test("does not detect non-anagrams with identical checksum", () =>
  arrayEqual(anagrams("mass", ["last"]), [])
)

test("detects anagrams case-insensitively", () =>
  arrayEqual(anagrams("Orchestra", ["cashregister", "Carthorse", "radishes"]), ["Carthorse"])
)

test("detects anagrams using case-insensitive subject", () =>
  arrayEqual(anagrams("Orchestra", ["cashregister", "carthorse", "radishes"]), ["carthorse"])
)

test("detects anagrams using case-insensitive possible matches", () =>
  arrayEqual(anagrams("orchestra", ["cashregister", "Carthorse", "radishes"]), ["Carthorse"])
)

test("does not detect a anagram if the original word is repeated", () =>
  arrayEqual(anagrams("go", ["go Go GO"]), [])
)

test("anagrams must use all letters exactly once", () =>
  arrayEqual(anagrams("tapper", ["patter"]), [])
)

test("words are not anagrams of themselves (case-insensitive)", () =>
  arrayEqual(anagrams("BANANA", ["BANANA", "Banana", "banana"]), [])
)

test("words other than themselves can be anagrams", () =>
  arrayEqual(anagrams("LISTEN", ["Listen", "Silent", "LISTEN"]), ["Silent"])
)
