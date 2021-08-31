open Test

let stringEqual = (~message=?, a: string, b: string) =>
    assertion(~message?, ~operator="stringEqual", (a, b) => a == b, a, b)

test("Hello World", () => {
  stringEqual(~message="Returns hello world", HelloWorld.hello(), "Hello, World!")
})
