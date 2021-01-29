type color =
  | Black
  | Brown
  | Red
  | Orange
  | Yellow
  | Green
  | Blue
  | Violet
  | Grey
  | White;

let colorCode = (color) => {
  switch (color) {
  | Black => 0
  | Brown => 1
  | Red => 2
  | Orange => 3
  | Yellow => 4
  | Green => 5
  | Blue => 6
  | Violet => 7
  | Grey => 8
  | White => 9
  }
};
