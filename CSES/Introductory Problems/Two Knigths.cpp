/*
  Your task is to count for k=1,2,…,n the number of ways two knights can be
  placed on a k×k chessboard so that they do not attack each other.

  Input

  The only input line contains an integer n.

  Output

  Print n integers: the results.

  Constraints
  1≤n≤10000
  Example

  Input:
  8

  Output:
  0
  6
  28
  96
  252
  550
  1056
  1848

*/

#include <iostream>

int main() {
  int n{};
  std::cin >> n;

  /*
    General formula to place knights, there are n^2 places for first piece
    and there are n^2 - 1 places, both pieces are the same so
    every position is counted twice, we divide by 2

    (n^2) * (n^2 - 1) / 2
  */

  for (long i{1}; i <= n; i++) {
    // 1x1 impossible
    if (i == 1) {
      std::cout << 0 << std::endl;
    }

    // 2x2 can't check
    if (i == 2) {
      std::cout << (2 * 2 * (2 * 2 - 1)) / 2 << std::endl;
    }

    // 3x3 special case
    /*
      - Corners can check only 2 ways (4 corners)
        2*4 = 8

      - Middle elements can only check 2 ways ( (n-2)* 4 ) squares
        (n-2)*4*2 = 8n - 16

      - Center can't check

      - Every position is counted twice so total places they attack each other
      is (2*4 + (8*3 - 16))/2
    */
    if (i == 3) {
      std::cout << (3 * 3 * (3 * 3 - 1)) / 2 - (2 * 4 + (8 * 3 - 16)) / 2
                << std::endl;
    }

    // 4x4 and on...
    /*
    - Corners can check only 2 ways, there are 4 corners
      2*4 = 8

    - The adjacent squares of each corner can check only 3 ways, there are 8
    squares (2 for each corner) 3*8 = 24

    - The remaining squares of the outer border, which are (n-4) squares * 4
    outer borders can check 4 ways (n-4)*4*4 = 16n - 64

    - Corners of the inner border can only check 4 ways, there are 4 corners
      4*4 = 16

    - Squares of the inner border can check 6 ways, and there are (n-4) squares
    and 4 sides of the inner border, so: (n-4)*4*6 = 24n - 96

    - All the remaining elements produce a (n-4) * (n-4) matrix and each element
    of that matrix can check 8 ways (n-4)(n-4)*8 = 8n^2 - 64n + 128

    - The total position that two knights can check each other is the sum of the
    above 8 + 24 + (16n - 64) + 16 + (24n - 96) + (8n^2 - 64n + 128)

    - Because every position is counted twice, it would be half of that ammount
      (8 + 24 + (16n - 64) + 16 + (24n - 96) + (8n^2 - 64n + 128))/2
    */

    if (i >= 4) {
      std::cout << ((i * i) * (i * i - 1)) / 2 -
                       ((8 + 24 + (16 * i - 64) + 16 + (24 * i - 96) +
                         (8 * i * i - 64 * i + 128)) /
                        2)
                << std::endl;
    }
  }

  return 0;
}