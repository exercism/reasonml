type coins = list(int);

let intCompare = (n1: int, n2: int) =>
  if (n1 == n2) {
    0;
  } else if (n1 > n2) {
    1;
  } else {
    (-1);
  };

let findSmallestCoinsListMeetingTarget =
    (cache: array(option(coins)), coins, target: int)
    : option(list(int)) => {
  let findCoinsMeetingTargetMinusCoin = coin =>
    if (target == coin) {
      Some([coin]);
    } else {
      Belt.Option.map(cache[target - coin], cs => [coin, ...cs]);
    };
  List.filter(x => x <= target, coins)
  |> List.map(findCoinsMeetingTargetMinusCoin)
  |> Belt.List.keepMap(_, x => x)
  |> List.sort((xs, ys) => intCompare(List.length(xs), List.length(ys)))
  |> Belt.List.head;
};

let makeChange = (target: int, coins) : option(coins) =>
  switch (target) {
  | 0 => Some([])
  | _ when target < 0 => None
  | _ =>
    let cache = Array.make(target + 1, None);
    for (i in 1 to target) {
      cache[i] = findSmallestCoinsListMeetingTarget(cache, coins, i);
    };
    cache[target];
  };
