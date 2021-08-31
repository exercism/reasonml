let abbreviate = (input: string) : string => {
  let firstLetter = (word: string) : string =>
    word |> Js.String.charAt(0) |> Js.String.toUpperCase;

  input
  |> Js.String.splitByRe([%re "/[\\s-]/"])
  |> Js.Array.map(Belt.Option.getExn)
  |> Js.Array.map(firstLetter)
  |> Js.Array.joinWith("");
};
