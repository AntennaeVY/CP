/*
  You are given an array of n integers. You want to modify the array so that it
  is increasing, i.e., every element is at least as large as the previous
  element.

  On each move, you may increase the value of any element by one. What is the
  minimum number of moves required?

  Input

  The first input line contains an integer n: the size of the array.

  Then, the second line contains n integers x1,x2,…,xn: the contents of the
  array.

  Output

  Print the minimum number of moves.
*/

#include <iostream>

int main() {
  int n{};
  long previous{};
  long current{};
  long moves{};

  std::cin >> n;

  // Read first element from the stdin
  std::cin >> previous;

  for (int i{}; i < n - 1; i++) {
    // Read the current element from the stdin
    std::cin >> current;

    // If the current element is less than the previous, then the number of
    // moves it would need to be at least as large as the current element is
    // equal to (previous - current) and we keep the previous element because
    // we're actually modyfing the array so current element would become equal
    // to previous element in (previous - current) moves.

    // If it's not less than the previous then we've got a new pivot so we
    // change it to be our next value for comparisons

    if (current < previous) {
      moves += previous - current;
    } else {
      previous = current;
    }
  }

  std::cout << moves;

  return 0;
}