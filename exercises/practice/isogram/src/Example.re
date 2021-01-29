let charlist = Array.map(w => w.[0]);

let rec check_repeats = word_list =>
  switch (word_list) {
  | [] => true
  | [x, ...xs] => ! List.mem(x, xs) && check_repeats(xs)
  };

let clean = List.filter(x => ! (x == '-' || x == ' '));

let is_isogram = word =>
  String.lowercase_ascii(word)
  |> Js.String.split("")
  |> charlist
  |> Array.to_list
  |> clean
  |> check_repeats;
