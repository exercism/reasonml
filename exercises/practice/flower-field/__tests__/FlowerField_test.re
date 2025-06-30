open Jest;

describe("Flower Field", () => {
  open Expect;

  test("no rows", () =>
    expect(FlowerField.annotate([||])) |> toEqual([||])
  );
  test("no columns", () =>
    expect(FlowerField.annotate([|""|])) |> toEqual([|""|])
  );
  test("no flowers", () => {
    let input = [|"   ", 
                  "   ", 
                  "   "|];
    expect(FlowerField.annotate(input)) |> toEqual(input)
  });
  test("garden full of flowers", () => {
    let input = [|"***", 
                  "***", 
                  "***"|];
    expect(FlowerField.annotate(input)) |> toEqual(input)
  });
  test("flower surrounded by spaces", () => {
    let input = [|"   ", 
                  " * ", 
                  "   "|];
    let annot = [|"111", 
                  "1*1", 
                  "111"|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
  test("space surrounded by flowers", () => {
    let input = [|"***", 
                  "* *", 
                  "***"|];
    let annot = [|"***", 
                  "*8*", 
                  "***"|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
  test("horizontal line", () =>
    expect(FlowerField.annotate([|" * * "|])) |> toEqual([|"1*2*1"|])
  );
  test("horizontal line, flowers at edges", () =>
    expect(FlowerField.annotate([|"*   *"|])) |> toEqual([|"*1 1*"|])
  );
  test("vertical line", () => {
    let input = [|" ", 
                  "*", 
                  " ",
                  "*", 
                  " "|];
    let annot = [|"1", 
                  "*", 
                  "2",
                  "*", 
                  "1"|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
  test("vertical line, flowers at edges", () => {
    let input = [|"*", 
                  " ", 
                  " ",
                  " ", 
                  "*"|];
    let annot = [|"*", 
                  "1", 
                  " ",
                  "1", 
                  "*"|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
  test("cross", () => {
    let input = [|"  *  ",
                  "  *  ",
                  "*****",
                  "  *  ",
                  "  *  "|] 
    let annot = [|" 2*2 ",
                  "25*52",
                  "*****",
                  "25*52",
                  " 2*2 "|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
  test("large garden", () => {
    let input = [|" *  * ",
                  "  *   ",
                  "    * ",
                  "   * *",
                  " *  * ",
                  "      "|] 
    let annot = [|"1*22*1",
                  "12*322",
                  " 123*2",
                  "112*4*",
                  "1*22*2",
                  "111111"|];
    expect(FlowerField.annotate(input)) |> toEqual(annot)
  });
});
