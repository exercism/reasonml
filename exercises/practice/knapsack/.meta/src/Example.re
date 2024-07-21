open Item;

let rec last = (items: list('a)): 'a => {
  switch (items) {
  | [x] => x
  | [_next, ...rest] => last(rest)
  | _ => Js.Exn.raiseError("List can not be empty", "EmptyListError")
  };
};

let find_item_max_value = (item: item, last_values: list(int), capacity: int): int => {
  let value_without = List.nth(last_values, capacity);
  if (capacity >= item.weight) {
    let value_with = List.nth(last_values, (capacity - item.weight)) + item.value;
    max(value_with, value_without);
  } else {
    value_without
  }
};

let rec calculate_max_values = (item: item, last_values: list(int), capacity: int, acc: list(int)) : list(int) => {
  switch (capacity) {
  | n when n < 0 => acc
  | _n => {
      let item_max_value = find_item_max_value(item, last_values, capacity)
      calculate_max_values(item, last_values, capacity - 1, [item_max_value, ...acc])
    }
  };
};

let rec find_max_value = (items: list(item), last_values: list(int), capacity: int) : int => {
  switch (items) {
  | [] => last(last_values)
  | [next, ...rest] => {
      let next_values = calculate_max_values(next, last_values, capacity, []);
      find_max_value(rest, next_values, capacity)
    }
  };
};

let maximum_value = (items: list(item), capacity: int) : int => {
  let initial_values = List.init(capacity + 1, _ => 0);
  switch (items) {
  | [] => 0
  | _  => find_max_value(items, initial_values, capacity)
  };
};
