/*
  A number spiral is an infinite grid whose upper-left square has number 1. Here
  are the first five layers of the spiral:

  1   2  9 10 25
  4   3  8 11 24
  5   6  7 12 23
  16 15 14 13 22
  17 18 19 20 21

  Your task is to find out the number in row y and column x.

  Input

  The first input line contains an longeger t: the number of tests.

  After this, there are t lines, each containing longegers y and x.

  Output

  For each test, prlong the number in row y and column x.

  Constralongs
  1≤t≤105
  1≤y,x≤109
  Example

  Input:
  3
  2 3
  1 1
  4 2

  Output:
  8
  1
  15
*/

#include <iostream>

int main() {
  long T{};
  std::cin >> T;

  while (T--) {
    long col{};
    long row{};
    long knownCol{};
    long knownRow{};
    long knownValue{};
    long horizontalMoves{};
    long verticalMoves{};
    long result{};

    std::cin >> row >> col;

    long pivot{};

    if (row > col) {
      pivot = row;
    } else {
      pivot = col;
    }

    if (pivot % 2 == 1) {
      knownRow = 1;
      knownCol = pivot;
      knownValue = pivot * pivot;

      verticalMoves = row - knownRow;
      horizontalMoves = knownCol - col;
      result = knownValue - verticalMoves - horizontalMoves;

    } else if (pivot % 2 == 0) {
      knownRow = pivot;
      knownCol = 1;
      knownValue = pivot * pivot;

      horizontalMoves = col - knownCol;
      verticalMoves = knownRow - row;

      result = knownValue - horizontalMoves - verticalMoves;
    }

    std::cout << result << std::endl;
  }

  return 0;
}