let stringToCharArray = (s) => {
  let len = String.length(s);
  Array.init(len, n => s.[n]);
}

let isAnagram = (base, word) => {
  if(String.length(base) != String.length(word)) {
    false
  } else {
    let base = String.lowercase(base);
    let word = String.lowercase(word);
    if(base == word) {
      false
    } else {
      let base = stringToCharArray(base);
      Array.sort(Char.compare, base);
      let word = stringToCharArray(word);
      Array.sort(Char.compare, word);
      base == word;
    }
  }
};

let anagrams = (base, candidates) => {
  List.filter(isAnagram(base), candidates);
};