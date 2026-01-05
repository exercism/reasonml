# Exercism ReasonML Track

[![Configlet](https://github.com/exercism/reasonml/actions/workflows/configlet.yml/badge.svg)](https://github.com/exercism/reasonml/actions/workflows/configlet.yml) [![CI](https://github.com/exercism/reasonml/actions/workflows/main.yml/badge.svg)](https://github.com/exercism/reasonml/actions/workflows/main.yml)

## Setup

First install npm (Node Package Manager) - you can do that from this site: https://www.npmjs.com/get-npm
Follow the instructions under https://reasonml.github.io/docs/en/installation to install ReasonML.

## Contributing

We welcome all contributions, both large and small.

Please read about how to [get involved in a track](https://github.com/exercism/docs/tree/main/building/tracks). Be sure to read the Exercism [Code of Conduct](https://exercism.io/code-of-conduct).

Fixes and improvements to existing exercises are welcome. Please note that this track's exercises must conform to the Exercism-wide standards described in the [documentation](https://github.com/exercism/docs/tree/main). If you're unsure about how to make a change, then go ahead and open a GitHub issue, and we'll discuss it.

## Exercise Tests

All Exercism exercises contain a test suite, which help to guide the user's implementation.

Tests should be written using [bs-jest](https://github.com/glennsl/bs-jest).

```re
open Jest;
open Expect;

describe("Leap", () => {
  test("year not divisible by 4: common year", () =>
    expect(Leap.is_leap_year(2015)) |> toBe(false)
  );
  test("year divisible by 4, not divisible by 100: leap year", () =>
    expect(Leap.is_leap_year(1996)) |> toBe(true)
  );
})
```

## Coding Style

Use `PascalCase.re` for Reason implementation file names.
A Reason interface file (`.rei`) should be included with every exercise to help the user get started.
Use [refmt](https://github.com/reasonml/reason-cli) on your code before pushing.

## Opening an Issue

If you plan to make significant or breaking changes, please open an issue so we can discuss it first. If this is a discussion that is relevant to more than just the ReasonML track, please open an issue in [exercism/discussions](https://github.com/exercism/discussions/issues).

## Submitting a Pull Request

Pull requests should be focused on a single exercise, issue, or conceptually cohesive change. Please refer to Exercism's [pull request guidelines](https://github.com/exercism/docs/blob/main/building/github/contributors-pull-request-guide.md).

Please use [refmt](https://reasonml.github.io/docs/en/extra-goodies.html) to ensure a consistent coding style.

```sh
refmt --in-place Example.re
```

### Verifying Your Change

Before submitting your pull request, you'll want to verify the changes in two ways:

- Run all the tests for the ReasonML exercises. There is a top level Makefile, run: `make`.
- Run checks on the repo using [configlet](https://github.com/exercism/docs/tree/main/building/configlet). From the top level, run:

```sh
./bin/configlet lint --track-id reasonml .
```

## Contributing a New Exercise

Please see the documentation about [adding new exercises](https://github.com/exercism/docs/tree/main/building/tracks/practice-exercises).

Note that:

- Each exercise must stand on its own. Do not reference files outside the exercise directory. They will not be included when the user fetches the exercise.
- Exercises may use any library subject to licensing restrictions, make sure dependencies are updated in the package.json file for the exercise.
- Exercises must conform to the Exercism-wide standards described in [the documentation](https://github.com/exercism/docs/tree/master/language-tracks/exercises).
- Each exercise should have a test suite, an example solution, and build configuration files for node and Bucklescript. The CI build expects ReasonML files to be named ending in .re
- Be sure to add it to the appropriate place in the `config.json` file.
