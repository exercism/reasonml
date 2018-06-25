type planet =
  | Mercury
  | Venus
  | Earth
  | Mars
  | Jupiter
  | Saturn
  | Neptune
  | Uranus;

let earthYears = seconds => seconds /. 31557600.0;

let relYears =
  fun
  | Mercury => 0.2408467
  | Venus => 0.61519726
  | Earth => 1.
  | Mars => 1.8808158
  | Jupiter => 11.862615
  | Saturn => 29.447498
  | Uranus => 84.016846
  | Neptune => 164.79132;

let ageOn = (planet, seconds) => earthYears(seconds) /. relYears(planet);
