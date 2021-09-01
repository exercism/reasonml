# Exercism ReScript Track

![build status](https://travis-ci.org/exercism/rescript.svg?branch=master)

## Setup

First install npm (Node Package Manager) - you can do that from this site: https://www.npmjs.com/get-npm
Follow the instructions under https://rescript.github.io/docs/en/installation to install ReScript.

## Contributing

We welcome all contributions, both large and small.

Please read about how to [get involved in a track](https://github.com/exercism/docs/tree/main/contributing-to-language-tracks). Be sure to read the Exercism [Code of Conduct](https://exercism.io/code-of-conduct).

Fixes and improvements to existing exercises are welcome. Please note that this track's exercises must conform to the Exercism-wide standards described in the [documentation](https://github.com/exercism/docs/tree/main/language-tracks/exercises). If you're unsure about how to make a change, then go ahead and open a GitHub issue, and we'll discuss it.

## Exercise Tests

All Exercism exercises contain a test suite, which help to guide the user's implementation. You can read more about how we think about test suites in [the Exercism documentation](https://github.com/exercism/docs/blob/main/language-tracks/exercises/anatomy/test-suites.md).

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
Use [refmt](https://github.com/rescript/reason-cli) on your code before pushing.

## Opening an Issue

If you plan to make significant or breaking changes, please open an issue so we can discuss it first. If this is a discussion that is relevant to more than just the ReScript track, please open an issue in [exercism/discussions](https://github.com/exercism/discussions/issues).

## Submitting a Pull Request

Pull requests should be focused on a single exercise, issue, or conceptually cohesive change. Please refer to Exercism's [pull request guidelines](https://github.com/exercism/docs/blob/main/contributing/pull-request-guidelines.md).

Please use [refmt](https://rescript.github.io/docs/en/extra-goodies.html) to ensure a consistent coding style.

```sh
refmt --in-place Example.re
```

### Verifying Your Change

Before submitting your pull request, you'll want to verify the changes in two ways:

- Run all the tests for the ReScript exercises. There is a top level Makefile, run: `make`.
- Run checks on the repo using [configlet](https://github.com/exercism/docs/blob/main/language-tracks/configuration/configlet.md). From the top level, run:

```sh
./bin/configlet lint --track-id rescript .
```

## Contributing a New Exercise

Please see the documentation about [adding new exercises](https://github.com/exercism/docs/blob/main/you-can-help/make-up-new-exercises.md).

Note that:

- Each exercise must stand on its own. Do not reference files outside the exercise directory. They will not be included when the user fetches the exercise.
- Exercises may use any library subject to licensing restrictions, make sure dependencies are updated in the package.json file for the exercise.
- Exercises must conform to the Exercism-wide standards described in [the documentation](https://github.com/exercism/docs/tree/main/language-tracks/exercises).
- Each exercise should have a test suite, an example solution, and build configuration files for node and Bucklescript. The CI build expects ReScript files to be named ending in .re
- Be sure to add it to the appropriate place in the `config.json` file.
