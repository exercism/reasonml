let isDigit = (ch: char) => {
  let ord = Char.code(ch);
  ord >= 48 && ord <= 57;
};

let rec toInt = (s: string, ptr: int, acc: int) => {
  if(ptr == String.length(s)) {
    (ptr, acc)
  } else {
    if(!isDigit(s.[ptr])) {
      (ptr, acc)
    } else {
      toInt(s, ptr + 1, 10 * acc + Char.code(s.[ptr]) - 48)
    }
  }
};

let rec unfoldString = (startPtr: int, acc: string, consume, s: string): string => {
  if(s == "" || startPtr == String.length(s)) {
    acc;
  } else {
    let (nextPtr, nextChunk) = consume(s, startPtr);
    unfoldString(nextPtr, acc ++ nextChunk, consume, s);
  }
};

let rec skipWhileUnchanged = (s: string, startPtr: int, ptr: int): int => {
  if(ptr < String.length(s) && s.[ptr] == s.[startPtr]) {
    skipWhileUnchanged(s, startPtr, ptr + 1)
  } else {
    ptr  
  }
};

let chunk = (plainText: string, startPtr: int) => {
  let nextPtr = skipWhileUnchanged(plainText, startPtr, startPtr + 1);
  let chunkLength = nextPtr - startPtr;
  let chunkChar = plainText.[startPtr];
  let chunked = if(chunkLength == 1) {
    String.make(1, chunkChar)
  } else {
    string_of_int(chunkLength) ++ String.make(1, chunkChar)
  };
  (nextPtr, chunked);
};

let expand = (rleText: string, startPtr: int) => {
  let firstChar = rleText.[startPtr];
  let (nextPtr, size) = if(isDigit(firstChar)) {
    toInt(rleText, startPtr, 0)
  } else {
    (startPtr, 1)
  };
  let expansionChar = rleText.[nextPtr];
  (nextPtr + 1, String.make(size, expansionChar))
};

let encode = unfoldString(0, "", chunk);

let decode = unfoldString(0, "", expand);
