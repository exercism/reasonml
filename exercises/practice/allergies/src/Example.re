open Int32;

let allergies = [|
  "eggs",
  "peanuts",
  "shellfish",
  "strawberries",
  "tomatoes",
  "chocolate",
  "pollen",
  "cats",
|];

type score = {
  s: int32,
  allergy: string,
};

let toList = (score: int) : list(string) => {
  let inputScore = of_int(score);

  allergies
  |> Array.mapi((index, allergy) => {s: shift_left(one, index), allergy})
  |> Array.to_list
  |> List.filter(({s, _}) => logand(s, inputScore) != zero)
  |> List.map(({allergy, _}) => allergy);
};

let isAllergicTo = (allergy: string, code: int) : bool =>
  List.mem(allergy, toList(code));
