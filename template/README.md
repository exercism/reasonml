How to setup the project locally:

- Ensure you have [Node.js](https://nodejs.org/) installed

- Setup a local opam switch to isolate the dependencies for this project
```
opam switch create . 5.3.0
```

- Install the required packages along with testing dependencies

```bash
make install
```

- Build the project - produces JS files in the `_build` folder
```bash
make build
```

- Run the built JS script
```bash
make run
```

- Run the tests
```bash
make test
```

You can take a look at the `Makefile` to see the complete commands being run under the hood
