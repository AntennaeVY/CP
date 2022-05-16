#include <bits/stdc++.h>
using namespace std;

int main() {
  while (true) {
    int A, D;
    cin >> A >> D;

    if (A == 0 && D == 0) break;

    vector<int> B(A), C(D);

    for (int i{}; i < A; i++) {
      cin >> B[i];
    }

    for (int i{}; i < D; i++) {
      cin >> C[i];
    }

    sort(B.begin(), B.end());
    sort(C.begin(), C.end());

    if (B[0] < C[0] || B[0] < C[1])
      cout << "Y" << endl;
    else
      cout << "N" << endl;
  }
}