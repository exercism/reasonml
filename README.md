# Exercism ReasonML Track

![build status](https://travis-ci.org/exercism/reasonml.svg?branch=master)

## Setup

First install npm (Node Package Manager) - you can do that from this site: https://www.npmjs.com/get-npm
Follow the instructions under https://reasonml.github.io/docs/en/quickstart-javascript.html to install ReasonML.

## Contributing

Thank you so much for contributing! :tada:

Please read about how to [get involved in a track](https://github.com/exercism/docs/tree/master/contributing-to-language-tracks). Be sure to read the Exercism [Code of Conduct](https://github.com/exercism/exercism.io/blob/master/CODE_OF_CONDUCT.md).

We welcome pull requests of all kinds. No contribution is too small.

We encourage contributions that provide fixes and improvements to existing exercises. Please note that this track's exercises must conform to the Exercism-wide standards described in the [documentation](https://github.com/exercism/docs/tree/master/language-tracks/exercises). If you're unsure about how to make a change, then go ahead and open a GitHub issue, and we'll discuss it.

## Exercise Tests

At the most basic level, Exercism is all about the tests. You can read more about how we think about test suites in [the Exercism documentation](https://github.com/exercism/docs/blob/master/language-tracks/exercises/anatomy/test-suites.md).

Test files should use the following format:

```
open Jest;
open Expect;

describe("Leap", () => {
  test("year not divisible by 4: common year", () =>
    expect(Leap.is_leap_year(2015)) |> toBe(false)
  );
  test("year divisible by 4, not divisible by 100: leap year", () =>
    expect(Leap.is_leap_year(1996)) |> toBe(true)
  );
})```

## Opening an Issue

If you plan to make significant or breaking changes, please open an issue so we can discuss it first. If this is a discussion that is relevant to more than just the ReasonML track, please open an issue in [exercism/discussions](https://github.com/exercism/discussions/issues).

## Submitting a Pull Request

Pull requests should be focused on a single exercise, issue, or conceptually cohesive change. Please refer to Exercism's [pull request guidelines](https://github.com/exercism/docs/blob/master/contributing/pull-request-guidelines.md).

Please follow the coding standards for ReasonML. (If there is a formatter for the track's language, add instructions for using it here.)

### Verifying Your Change

Before submitting your pull request, you'll want to verify the changes in two ways:

* Run all the tests for the ReasonML exercises
* Run an Exercism-specific linter to verify the track

All the tests for ReasonML exercises can be run from the top level of the repo with

```
# add this command
```

For the Exercism-specific linting, please see [the documentation](https://github.com/exercism/docs/blob/master/language-tracks/configuration/linting.md).

## Contributing a New Exercise

Please see the documentation about [adding new exercises](https://github.com/exercism/docs/blob/master/you-can-help/make-up-new-exercises.md).

Note that:

- Each exercise must stand on its own. Do not reference files outside the exercise directory. They will not be included when the user fetches the exercise.
- Exercises may use any library subject to licensing restrictions, make sure dependencies are updated in the package.json file for the exercise.
- Exercises must conform to the Exercism-wide standards described in [the documentation](https://github.com/exercism/docs/tree/master/language-tracks/exercises).
- Each exercise should have a test suite, an example solution, and build configuration files for node and Bucklescript. The CI build expects ReasonML files to be named ending in .re
- Be sure to add it to the appropriate place in the `config.json` file.
