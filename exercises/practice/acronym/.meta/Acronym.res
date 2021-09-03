let abbreviate = (input: string) : string => {
  let firstLetter = (word: string) : string =>
    word -> Js.String2.charAt(0) -> Js.String2.toUpperCase

  input
    -> Js.String2.splitByRe(%re("/[\\s-]/"))
    -> Js.Array2.map(Belt.Option.getExn)
    -> Js.Array2.map(firstLetter)
    -> Js.Array2.joinWith("")
}
