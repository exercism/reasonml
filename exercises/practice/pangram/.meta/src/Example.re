exception Finished(int);

let rec stringFold = (s: string, init: 'a, step: ('a, char) => 'a): 'a => {
  switch(String.length(s)) {
    | 0 => init;
    | _ => {
      let tail = String.sub(s, 1, String.length(s) - 1);
      let next = step(init, s.[0]);
      stringFold(tail, next, step);
    }
  }
};

let isUppercaseAlpha = (ch) => Char.code(ch) >= 65 && Char.code(ch) <= 90;

let isPangram = (s: string) => {
  let alphabetBits = 1 lsl 26 - 1;
  let updateBits = (b, ch) => {
    let updated = {
      let ch = Char.uppercase_ascii(ch);
      if (isUppercaseAlpha(ch)) {
        b lor 1 lsl (Char.code(ch) - Char.code('A'));
      } else {
        b;
      };
    };
    if (updated == alphabetBits) {
      raise(Finished(alphabetBits));
    } else {
      updated;
    };
  };
  try (stringFold(s, 0, updateBits) == alphabetBits) {
  | Finished(bitSet) => bitSet == alphabetBits
  };
};
