#include <bits/stdc++.h>
using namespace std;

constexpr int N = 1e7 + 5;
vector<int> primes;
vector<bool> is_prime(N + 1, true);

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  is_prime[0] = is_prime[1] = false;

  for (int i = 2; i * i <= N; i++) {
    if (is_prime[i]) {
      for (int j = i * i; j <= N; j += i) {
        is_prime[j] = false;
      }
    }
  }

  

  int t;
  cin >> t;

  while (t--) {
    long long n;
    cin >> n;

    long long ans = 0;

	for (int i = 2; i <= n; i++) {
		if (is_prime[i])
			ans += n / i;
	}
      

    cout << ans << endl;
  }
}