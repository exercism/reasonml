type dna =
  | A
  | C
  | G
  | T;

type rna =
  | A
  | C
  | G
  | U;

let convertOne = (d: dna) =>
  switch (d) {
  | A => U
  | C => G
  | G => C
  | T => A
  };

let toRna = (ds: list(dna)) => List.map(convertOne, ds);
