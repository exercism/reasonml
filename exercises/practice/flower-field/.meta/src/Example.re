let hasFlower(b: array(string), width: int, x: int, y: int): bool = {
  if(x < 0 || x >= width || y < 0 || y >= Array.length(b)) {
    false
  } else {
    b[y].[x] == '*'
  }
};

let countFlowersAroundCell(hasFlower: (int, int) => bool, x: int, y: int): int = {
  let count = ref(0);
  for(dx in -1 to 1) {
    for(dy in -1 to 1) {
      if(dx != 0 || dy != 0) {
        if(hasFlower(x + dx, y + dy)) {
          count := count^ + 1;
        }
      }
    }
  };
  count^
};

let annotate = (b) => {
  let height = Array.length(b);
  if (height == 0) {
      [||];
  } else {
    let width = String.length(b[0]);
    let makeRow = (y) => {
      let makeCell = (x) => {
        let hasFlower = hasFlower(b, width);
        if(hasFlower(x, y)) {
          '*';
        } else {
          let flowers = countFlowersAroundCell(hasFlower, x, y);
          if(flowers == 0) {
            ' '
          } else {
            string_of_int(flowers).[0];
          }
        }
      };
      String.init(width, makeCell);
    };
    Array.init(height, makeRow);
  };
};
