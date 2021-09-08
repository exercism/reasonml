open Test;
open AllYourBase;

let optionEqual = (~message=?, a: option<'a>, b: option<'a>) =>
  assertion(~message?, ~operator="optionEqual", (a, b) => a == b, a, b)

test("single bit one to decimal", () =>
  optionEqual(rebase(2, list{1}, 100), Some(list{1}))
)

test("binary to single decimal", () =>
  optionEqual(rebase(2, list{1, 0, 1}, 10), Some(list{5}))
)

test("single decimal to binary", () =>
  optionEqual(rebase(10, list{5}, 2), Some(list{1, 0, 1}))
)

test("binary to multiple decimal", () =>
  optionEqual(rebase(2, list{1, 0, 1, 0, 1, 0}, 10), Some(list{4, 2}))
)

test("decimal to binary", () =>
  optionEqual(rebase(10, list{4, 2}, 2), Some(list{1, 0, 1, 0, 1, 0}))
)

test("trinary to hexadecimal", () =>
  optionEqual(rebase(3, list{1, 1, 2, 0}, 16), Some(list{2, 10}))
)

test("hexadecimal to trinary", () =>
  optionEqual(rebase(16, list{2, 10}, 3), Some(list{1, 1, 2, 0}))
)

test("15-bit integer", () =>
  optionEqual(rebase(97, list{3, 46, 60}, 73), Some(list{6, 10, 45}))
)

test("empty list", () =>
  optionEqual(rebase(2, list{}, 10), None)
)

test("single zero", () =>
  optionEqual(rebase(10, list{0}, 2), None)
)

test("multiple zeros", () =>
  optionEqual(rebase(10, list{0, 0, 0}, 2), None)
)

test("leading zeros", () =>
  optionEqual(rebase(7, list{0, 6, 0}, 10), Some(list{4, 2}))
)

test("first base is zero", () =>
  optionEqual(rebase(0, list{}, 10), None)
)

test("first base is negative", () =>
  optionEqual(rebase(-1, list{}, 10), None)
)

test("negative digit", () =>
  optionEqual(rebase(2, list{1, (-1), 1, 0, 1, 0}, 10), None)
)

test("invalid positive digit", () =>
  optionEqual(rebase(2, list{1, 2, 1, 0, 1, 0}, 10), None)
)

test("second base is one", () =>
  optionEqual(rebase(10, list{}, 1), None)
)

test("second base is zero", () =>
  optionEqual(rebase(10, list{1}, 0), None)
)

test("second base is negative", () =>
  optionEqual(rebase(10, list{1}, -1), None)
)

test("both bases are negative", () =>
  optionEqual(rebase(-1, list{1}, -1), None)
)
