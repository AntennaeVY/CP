#include<bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while(t--) {
    long long n;
    cin >> n;

    long long first = 0, second = 0;

    for (int i = 0; n != 0; i++) {
      long long* current;

      if (i % 2 == 0)
        current = &first;
      else 
        current = &second;

      if (n % 4 != 2 && n != 4) {
        *current += 1;
        n--;
      } else {
        *current += n/2;
        n /= 2;
      }
    }

    cout << first << endl;
  }
}
