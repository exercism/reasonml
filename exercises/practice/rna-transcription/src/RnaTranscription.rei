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

let toRna: list(dna) => list(rna);
