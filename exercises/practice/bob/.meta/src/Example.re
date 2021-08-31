type speechType =
  | Question
  | Shouting
  | ShoutingQuestion
  | Nothing
  | Other;

let shouting = (input: string) : bool => input == String.uppercase_ascii(input);

let alphaChars = (input: string) : bool =>
  input |> Js.Re.test_([%bs.re "/[a-zA-Z-]/"]);

let question = (input: string) : bool =>
  String.contains_from(input, String.length(input) - 1, '?');

let analyseSpeech = (speech: string) : speechType => {
  let trimmed = String.trim(speech);
  if (String.length(trimmed) == 0) {
    Nothing;
  } else if (alphaChars(trimmed) && shouting(trimmed) && question(trimmed)) {
    ShoutingQuestion;
  } else if (alphaChars(trimmed) && shouting(trimmed)) {
    Shouting;
  } else if (question(trimmed)) {
    Question;
  } else {
    Other;
  };
};

let hey = (speech: string) : string => {
  let speechType: speechType = analyseSpeech(speech);

  switch (speechType) {
  | ShoutingQuestion => "Calm down, I know what I'm doing!"
  | Question => "Sure."
  | Shouting => "Whoa, chill out!"
  | Nothing => "Fine. Be that way!"
  | Other => "Whatever."
  };
};
