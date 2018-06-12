open Jest;

open Expect;

let () =
  describe("Raindrops", () => {
    test("the sound for 1 is 1", () =>
      expect(Raindrops.raindrops(1)) |> toEqual("1")
    );
    test("the sound for 3 is Pling", () =>
      expect(Raindrops.raindrops(3)) |> toEqual("Pling")
    );
    test("the sound for 5 is Plang", () =>
      expect(Raindrops.raindrops(5)) |> toEqual("Plang")
    );
    test("the sound for 7 is Plong", () =>
      expect(Raindrops.raindrops(7)) |> toEqual("Plong")
    );
    test("the sound for 6 is Pling as it has a factor 3", () =>
      expect(Raindrops.raindrops(6)) |> toEqual("Pling")
    );
    test(
      "2 to the power 3 does not make a raindrop sound as 3 is the exponent not the base",
      () =>
      expect(Raindrops.raindrops(8)) |> toEqual("8")
    );
    test("the sound for 9 is Pling as it has a factor 3", () =>
      expect(Raindrops.raindrops(9)) |> toEqual("Pling")
    );
    test("the sound for 10 is Plang as it has a factor 5", () =>
      expect(Raindrops.raindrops(10)) |> toEqual("Plang")
    );
    test("the sound for 14 is Plong as it has a factor 7", () =>
      expect(Raindrops.raindrops(14)) |> toEqual("Plong")
    );
    test("the sound for 15 is PlingPlang as it has a factor 3 and 5", () =>
      expect(Raindrops.raindrops(15)) |> toEqual("PlingPlang")
    );
    test("the sound for 21 is PlingPlong as it has a factor 3 and 7", () =>
      expect(Raindrops.raindrops(21)) |> toEqual("PlingPlong")
    );
    test("the sound for 25 is Plang as it has a factor 5", () =>
      expect(Raindrops.raindrops(25)) |> toEqual("Plang")
    );
    test("the sound for 27 is Pling as it has a factor 3", () =>
      expect(Raindrops.raindrops(27)) |> toEqual("Pling")
    );
    test("the sound for 35 is PlangPlong as it has a factor 5 and 7", () =>
      expect(Raindrops.raindrops(35)) |> toEqual("PlangPlong")
    );
    test("the sound for 49 is Plong as it has a factor 7", () =>
      expect(Raindrops.raindrops(49)) |> toEqual("Plong")
    );
    test("the sound for 52 is 52", () =>
      expect(Raindrops.raindrops(52)) |> toEqual("52")
    );
    test("the sound for 105 is PlingPlangPlong", () =>
      expect(Raindrops.raindrops(105)) |> toEqual("PlingPlangPlong")
    );
    test("the sound for 3125 is Plang", () =>
      expect(Raindrops.raindrops(3125)) |> toEqual("Plang")
    );
  });
