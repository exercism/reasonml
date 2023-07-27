let letterScores = (letter : char) => {
  switch letter {
    | 'A' | 'E' | 'I' | 'O' | 'U' | 'L' | 'N' | 'R' | 'S' | 'T' => 1
    | 'D' | 'G' => 2
    | 'B' | 'C' | 'M' | 'P' => 3
    | 'F' | 'H' | 'V' | 'W' | 'Y' => 4
    | 'K' => 5
    | 'J' | 'X' => 8
    | 'Q' | 'Z' => 10
    | _ => 0
  }
}

let getScore = (letters : list(char)) => {
  List.fold_left((acc, letter) => acc + letterScores(letter), 0, letters)
}

let score = (word : string) => {
  String.lowercase_ascii(word)
  |> Js.String.split("")
  |> Array.map(w => Char.uppercase(w.[0]))
  |> Array.to_list
  |> getScore
}
