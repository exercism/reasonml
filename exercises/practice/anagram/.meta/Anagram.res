open Js

let toChars = (word: string): array<float> => {
  open String2
  open Array2

  word->split("")->map(x => charCodeAt(x, 0))->sortInPlace
}

let isAnagram = (base: string, word: string): bool => {
  open String2

  length(base) == length(word) && {
      let lowerBase = toLowerCase(base)
      let lowerWord = toLowerCase(word)
      lowerBase != lowerWord && toChars(lowerBase) == toChars(lowerWord)
    }
}

let anagrams = (base: string, candidates: array<string>): array<string> =>
  candidates->Array2.filter(isAnagram(base))
