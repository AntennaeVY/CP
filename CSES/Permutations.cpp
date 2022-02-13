/*
  A permutation of integers 1,2,…,n is called beautiful if there are no adjacent
  elements whose difference is 1.

  Given n, construct a beautiful permutation if such a permutation exists.

  Input

  The only input line contains an integer n.

  Output

  Print a beautiful permutation of integers 1,2,…,n. If there are several
  solutions, you may print any of them. If there are no solutions, print "NO
  SOLUTION".
*/

#include <iostream>

int main() {
  int n{};
  std::cin >> n;

  // From 1 to n (inclusive) there are (n+1)/2 odd and even numbers
  // and if n is odd then there is one even number less
  int oddCount = (n + 1) / 2;
  int evenCount = (n % 2 == 0) ? oddCount : oddCount - 1;

  // Only permutations from 1 ... 3 got no solution (exception for n == 1)
  if (n < 4 && n != 1) {
    std::cout << "NO SOLUTION";
    return 0;
  }

  // Print out even numbers first

  for (int i{1}; i <= evenCount; i++) {
    std::cout << 2 * i << " ";
  }

  // Print out odd numbers second

  for (int i{1}; i <= oddCount; i++) {
    std::cout << 2 * i - 1 << " ";
  }

  return 0;
}