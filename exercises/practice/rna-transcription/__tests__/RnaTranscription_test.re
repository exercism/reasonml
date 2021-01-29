open Jest;
open Expect;
open RnaTranscription;

describe("Rna-transcription", () => {
  test("transcribes empty list", () =>
    expect(RnaTranscription.toRna([])) |> toEqual([])
  );
  test("transcribes cytidine", () =>
    expect(RnaTranscription.toRna([C])) |> toEqual([G])
  );
  test("transcribes guanosine", () =>
    expect(RnaTranscription.toRna([G])) |> toEqual([C])
  );
  test("transcribes adenosie", () =>
    expect(RnaTranscription.toRna([A])) |> toEqual([U])
  );
  test("transcribes thymidine", () =>
    expect(RnaTranscription.toRna([T])) |> toEqual([A])
  );
  test("transcribes multiple", () =>
    expect(RnaTranscription.toRna([A, C, G, T, G, G, T, C, T, T, A, A])) |> toEqual([U, G, C, A, C, C, A, G, A, A, U, U])
  );
})