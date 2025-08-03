let squareRoot = n => {
  let radicand = float_of_int(n);
  let rec aux = guess => {
    let next = 0.5 *. (guess +. radicand /. guess);
    switch (abs_float(next -. guess)) {
    | diff when diff < 0.0001 => int_of_float(next)
    | _ => aux(next)
    };
  };
  aux(radicand /. 2.0);
};
