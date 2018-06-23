let find = (array, value) => {
  let rec go = (lo, hi) =>
    if (lo > hi) {
      None;
    } else {
      let mid = lo + (hi - lo) / 2;
      let mid_val = array[mid];
      if (mid_val < value) {
        go(mid + 1, hi);
      } else if (mid_val > value) {
        go(lo, mid - 1);
      } else {
        Some(mid);
      };
    };
  go(0, Array.length(array) - 1);
};
