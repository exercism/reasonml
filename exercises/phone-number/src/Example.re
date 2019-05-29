let phoneNumber = (input: string) : option(string) => {
  let cleanNoDigits = (input: string) : string =>
    input |> Js.String.replaceByRe([%re "/\\D/g"], "");

  let checkFormat = (phone: string) : option(string) => {
    let re = [%re "/^1?[2-9]\\d{2}[2-9]\\d{2}\\d{4}$/"];

    Js.Re.test_(re, phone) ?
      Some(Js.String.sliceToEnd(~from=-10, phone)) : None;
  };

  input |> cleanNoDigits |> checkFormat;
};
