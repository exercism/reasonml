open Jest;

describe("Protein Translation", () => {
  open Expect;

  test("Methionine RNA sequence", () =>
    expect(ProteinTranslation.proteins("AUG")) |> toEqual(["Methionine"])
  );

  test("Phenylalanine RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UUU")) |> toEqual(["Phenylalanine"])
  );

  test("Phenylalanine RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UUC")) |> toEqual(["Phenylalanine"])
  );

  test("Leucine RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UUA")) |> toEqual(["Leucine"])
  );

  test("Leucine RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UUG")) |> toEqual(["Leucine"])
  );

  test("Serine RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UCU")) |> toEqual(["Serine"])
  );

  test("Serine RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UCC")) |> toEqual(["Serine"])
  );

  test("Serine RNA sequence 3", () =>
    expect(ProteinTranslation.proteins("UCA")) |> toEqual(["Serine"])
  );

  test("Serine RNA sequence 4", () =>
    expect(ProteinTranslation.proteins("UCG")) |> toEqual(["Serine"])
  );

  test("Tyrosine RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UAU")) |> toEqual(["Tyrosine"])
  );

  test("Tyrosine RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UAC")) |> toEqual(["Tyrosine"])
  );

  test("Cysteine RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UGU")) |> toEqual(["Cysteine"])
  );

  test("Cysteine RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UGC")) |> toEqual(["Cysteine"])
  );

  test("Tryptophan RNA sequence", () =>
    expect(ProteinTranslation.proteins("UGG")) |> toEqual(["Tryptophan"])
  );

  test("STOP codon RNA sequence 1", () =>
    expect(ProteinTranslation.proteins("UAA")) |> toEqual([])
  );

  test("STOP codon RNA sequence 2", () =>
    expect(ProteinTranslation.proteins("UAG")) |> toEqual([])
  );

  test("STOP codon RNA sequence 3", () =>
    expect(ProteinTranslation.proteins("UGA")) |> toEqual([])
  );

  test("Translate RNA strand into correct protein list", () =>
    expect(ProteinTranslation.proteins("AUGUUUUGG"))
    |> toEqual(["Methionine", "Phenylalanine", "Tryptophan"])
  );

  test("Translation stops if STOP codon at beginning of sequence", () =>
    expect(ProteinTranslation.proteins("UAGUGG")) |> toEqual([])
  );

  test("Translation stops if STOP codon at end of two-codon sequence", () =>
    expect(ProteinTranslation.proteins("UGGUAG")) |> toEqual(["Tryptophan"])
  );

  test("Translation stops if STOP codon at end of three-codon sequence", () =>
    expect(ProteinTranslation.proteins("AUGUUUUAA"))
    |> toEqual(["Methionine", "Phenylalanine"])
  );

  test("Translation stops if STOP codon in middle of three-codon sequence", () =>
    expect(ProteinTranslation.proteins("UGGUAGUGG"))
    |> toEqual(["Tryptophan"])
  );

  test("Translation stops if STOP codon in middle of six-codon sequence", () =>
    expect(ProteinTranslation.proteins("UGGUGUUAUUAAUGGUUU"))
    |> toEqual(["Tryptophan", "Cysteine", "Tyrosine"])
  );
});
