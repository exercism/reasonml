let accumulate = (fn: 'a => 'b, input: array<'a>) : array<'b> => {
  let result: array<'b> = []
  Js.Array2.forEach(input, x => {
    Js.Array2.push(result, fn(x)) -> ignore
  })
  result
}
