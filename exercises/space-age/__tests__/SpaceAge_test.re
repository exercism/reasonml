open Jest;
open Expect;

describe("Space Age", () => {
  test("age on Earth", () =>
    expect(SpaceAge.ageOn(Earth, 1000000000.0))
    |> toBeSoCloseTo(31.69, ~digits=2)
  );
  test("age on Mercury", () =>
    expect(SpaceAge.ageOn(Mercury, 2134835688.0))
    |> toBeSoCloseTo(280.88, ~digits=2)
  );
  test("age on Venus", () =>
    expect(SpaceAge.ageOn(Venus, 189839836.0))
    |> toBeSoCloseTo(9.78, ~digits=2)
  );
  test("age on Mars", () =>
    expect(SpaceAge.ageOn(Mars, 2329871239.0))
    |> toBeSoCloseTo(39.25, ~digits=2)
  );
  test("age on Jupiter", () =>
    expect(SpaceAge.ageOn(Jupiter, 901876382.0))
    |> toBeSoCloseTo(2.41, ~digits=2)
  );
  test("age on Saturn", () =>
    expect(SpaceAge.ageOn(Saturn, 3000000000.0))
    |> toBeSoCloseTo(3.23, ~digits=2)
  );
  test("age on Uranus", () =>
    expect(SpaceAge.ageOn(Uranus, 3210123456.0))
    |> toBeSoCloseTo(1.21, ~digits=2)
  );
  test("age on Neptune", () =>
    expect(SpaceAge.ageOn(Neptune, 8210123456.0))
    |> toBeSoCloseTo(1.58, ~digits=2)
  );
});
