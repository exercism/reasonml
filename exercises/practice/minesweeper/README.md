# Minesweeper

Add the numbers to a minesweeper board.

Minesweeper is a popular game where the user has to find the mines using
numeric hints that indicate how many mines are directly adjacent
(horizontally, vertically, diagonally) to a square.

In this exercise you have to create some code that counts the number of
mines adjacent to a square and transforms boards like this (where `*`
indicates a mine):

    +-----+
    | * * |
    |  *  |
    |  *  |
    |     |
    +-----+

into this:

    +-----+
    |1*3*1|
    |13*31|
    | 2*2 |
    | 111 |
    +-----+

## Building and testing
You will need the node package manager (npm) installed - download from [here](https://www.npmjs.com/get-npm)
There is one time setup for each exercise, which may take a few minutes:
```
npm install
```

Open two shells, and in the first, start the build process.
```
npm start
```

In the second, start the tests running.
```
npm test
```

As you edit the code, the two processes will continually rebuild and rerun the tests.