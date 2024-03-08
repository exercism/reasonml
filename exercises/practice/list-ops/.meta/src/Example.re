let rec append = (list1: list('item), list2: list('item)): list('item) => {
  switch (list2) {
  | [] => list1
  | [next, ...rest] => append(list1 @ [next], rest)
  };
};

let rec foldl =
        (list: list('item), initial: 'acc, func: ('acc, 'item) => 'acc): 'acc => {
  switch (list) {
  | [] => initial
  | [next, ...rest] => foldl(rest, func(initial, next), func)
  };
};

let reverse = (list: list('item)): list('item) => {
  foldl(list, [], (acc, elem) => {[elem, ...acc]});
};

let concat = (list: list(list('item))): list('item) => {
  foldl(list, [], (acc, elem) => {append(acc, elem)});
};

let filter = (list: list('item), filter: 'item => bool): list('item) => {
  foldl(list, [], (acc, elem) =>
    if (filter(elem)) {
      [elem, ...acc];
    } else {
      acc;
    }
  )
  ->reverse;
};

let length = (list: list('item)): int => {
  foldl(list, 0, (acc, _elem) => acc + 1);
};

let map = (list: list('item), func: 'item => 'mapped): list('mapped) => {
  foldl(list, [], (acc, elem) => acc @ [func(elem)]);
};

let foldr = (list: list('item), initial: 'acc, func: ('acc, 'item) => 'acc) => {
  list->reverse->foldl(initial, func);
};
