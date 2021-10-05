open Js

type score = {
  item: string,
  value: int
}

let scores = [
  { item: "cats", value: 128 },
  { item: "pollen", value: 64 },
  { item: "chocolate", value: 32 },
  { item: "tomatoes", value: 16 },
  { item: "strawberries", value: 8 },
  { item: "shellfish", value: 4 },
  { item: "peanuts", value: 2 },
  { item: "eggs", value: 1 }
]

let toList = (code: int): array<string> => {
  let rec toListRec = (acc: array<string>, code: int) => {
    switch code {
      | 0 => acc
      | x => {
        switch Array.find(score => score.value <= x, scores) {
            | None => acc
            | Some({ item: item, value: value }) => toListRec(Array.concat([item], acc), code - value)
        }
      }
    }
  }

  toListRec([], mod(code, 256)) -> Array2.reverseInPlace
}

let isAllergicTo = (item: string, code: int): bool => {
  toList(code) -> Array2.includes(item)
}
