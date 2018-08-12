open Jest;

describe("Minesweeper", () => {
  open Expect;

  test("no rows", () =>
    expect(Minesweeper.annotate([||])) |> toEqual([||])
  );
  test("no columns", () =>
    expect(Minesweeper.annotate([|""|])) |> toEqual([|""|])
  );
  test("no mines", () => {
    let input = [|"   ", 
                  "   ", 
                  "   "|];
    expect(Minesweeper.annotate(input)) |> toEqual(input)
  });
  test("board with only mines", () => {
    let input = [|"***", 
                  "***", 
                  "***"|];
    expect(Minesweeper.annotate(input)) |> toEqual(input)
  });
  test("mine surrounded by spaces", () => {
    let input = [|"   ", 
                  " * ", 
                  "   "|];
    let annot = [|"111", 
                  "1*1", 
                  "111"|];
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
  });
  test("space surrounded by mines", () => {
    let input = [|"***", 
                  "* *", 
                  "***"|];
    let annot = [|"***", 
                  "*8*", 
                  "***"|];
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
  });
  test("horizontal line", () =>
    expect(Minesweeper.annotate([|" * * "|])) |> toEqual([|"1*2*1"|])
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
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
  });
  test("vertical line, mine at edges", () => {
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
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
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
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
  });
  test("large board", () => {
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
    expect(Minesweeper.annotate(input)) |> toEqual(annot)
  });
});
