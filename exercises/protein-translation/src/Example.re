let rec codons = strand =>
  switch (strand) {
  | [x, y, z, ...xs] => [String.concat("", [x, y, z]), ...codons(xs)]
  | _ => []
  };

let lookupTable =
  Js.Dict.fromList([
    ("AUG", "Methionine"),
    ("UUU", "Phenylalanine"),
    ("UUC", "Phenylalanine"),
    ("UUA", "Leucine"),
    ("UUG", "Leucine"),
    ("UCU", "Serine"),
    ("UCC", "Serine"),
    ("UCA", "Serine"),
    ("UCG", "Serine"),
    ("UAU", "Tyrosine"),
    ("UAC", "Tyrosine"),
    ("UGU", "Cysteine"),
    ("UGC", "Cysteine"),
    ("UGG", "Tryptophan"),
    ("UAA", "STOP"),
    ("UAG", "STOP"),
    ("UGA", "STOP"),
  ]);

let rec convert = codons =>
  switch (codons) {
  | [] => []
  | [x, ...xs] =>
    switch (Js.Dict.get(lookupTable, x)) {
    | Some("STOP") => []
    | Some(protein) => [protein, ...convert(xs)]
    | None => []
    }
  };

let proteins = strand =>
  strand |> Js.String.split("") |> Array.to_list |> codons |> convert;
