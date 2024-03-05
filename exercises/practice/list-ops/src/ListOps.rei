let append: (list('item), list('item)) => list('item);

let concat: list(list('item)) => list('item);

let filter: (list('item), 'item => bool) => list('item);

let length: list('item) => int;

let map: (list('item), 'item => 'mapped) => list('mapped);

let foldl: (list('item), 'acc, ('acc, 'item) => 'acc) => 'acc;

let foldr: (list('item), 'acc, ('acc, 'item) => 'acc) => 'acc;

let reverse: list('item) => list('item);
