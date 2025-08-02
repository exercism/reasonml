let collatzConjecture = n =>
  if (n < 1) {
    Error("Only positive integers are allowed");
  } else {
    let rec aux = (n, count) => {
      switch (n) {
      | 1 => Ok(count)
      | _ =>
        switch (n mod 2) {
        | 0 => aux(n / 2, count + 1)
        | _ => aux(n * 3 + 1, count + 1)
        }
      };
    };
    aux(n, 0);
  };
