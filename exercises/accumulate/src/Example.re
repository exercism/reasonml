let accumulate = (fn: 'a => 'b, input: list('a)) : list('b) =>
  List.fold_right((elem, acc) => [fn(elem), ...acc], input, []);
