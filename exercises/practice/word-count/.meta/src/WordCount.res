let wordCount = (input: string) =>
  input
  ->Js.String2.toLowerCase
  ->Js.String2.replaceByRe(%re("/[^'a-zA-Z0-9]+/g"), " ")
  ->Js.String2.trim
  ->Js.String2.splitByRe(%re("/'?\\s+'?/"))
  ->Js.Array2.map(Belt.Option.getExn)
  ->Js.Array2.reduce((dict, word) => {
    let count = Js.Dict.get(dict, word)

    switch count {
    | Some(value) => Js.Dict.set(dict, word, value + 1)
    | None => Js.Dict.set(dict, word, 1)
    }

    dict
  }, Js.Dict.empty())
