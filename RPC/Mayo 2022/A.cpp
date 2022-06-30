#include <iostream>
using namespace std;

int main() {
  int y, m, years = 0, months = 0;
  cin >> y >> m;

  if (y > 0)
    years += 15;
  else {
    months += m * 15;
  }

  if (y > 1)
    years += 9;
  else if (y == 1) {
    months += m * 9;
  }

  if (y > 2) {
    years += (y - 2) * 4;
    months += m * 4;
  }

  years += months / 12;
  months %= 12;

  cout << years << " " << months << endl;
}