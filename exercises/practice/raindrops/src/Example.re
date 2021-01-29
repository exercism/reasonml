let factor = (factor: int, input: int) : bool => input mod factor == 0;

let makeSound = (t: (int, string), input: int) => {
  let (n, sound) = t;
  factor(n, input) ? Some(sound) : None;
};

let defaultIfEmpty = (input: string, default: string) : string =>
  String.length(input) == 0 ? default : input;

let raindrops = (input: int) : string =>
  [(3, "Pling"), (5, "Plang"), (7, "Plong")]
  |> List.map(makeSound)
  |> List.map(f => f(input))
  |> List.map(Belt.Option.getWithDefault(_, ""))
  |> String.concat("")
  |> defaultIfEmpty(_, string_of_int(input));

