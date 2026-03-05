let eggCount = (number) => {
  let rec count = (n, acc) =>
    if (n == 0) {
      acc;
    } else {
      count(n land (n - 1), acc + 1);
    };
  count(number, 0);
};
