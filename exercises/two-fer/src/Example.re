let twoFer = (name) => {
  switch (name) {
  | None => "One for you, one for me."
  | Some(nameString) => "One for " ++ nameString ++ ", one for me."
  }
};
