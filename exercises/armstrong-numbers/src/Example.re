let rec pow = (b, e) =>
  switch (b, e) {
  | (b, 1) => b
  | (b, e) => b * pow(b, e - 1)
  };

let digits = number =>
  string_of_int(number)
  |> Js.String.split("")
  |> Array.map(n => int_of_string(n));

let digits_sum = digits => {
  let len = Array.length(digits);
  Array.fold_left((acc, digit) => acc + pow(digit, len), 0, digits);
};

let validate = number => number |> digits |> digits_sum == number;
