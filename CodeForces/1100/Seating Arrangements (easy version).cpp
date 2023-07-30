#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n, m;
    cin >> n >> m;

    vector<int> a(m), inconveniences(m, 0);
    for (auto &ai : a) cin >> ai;

    vector<bool> occupied(m, false);
    vector<int> a_sorted(a);
    sort(a_sorted.begin(), a_sorted.end());

    int ans = 0;

    for (int i = 0; i < m; i++) {
		int index = 0;
		
		while(index < m && a_sorted[index] <= a[i]) index++;
		index--;
		
		while(a_sorted[index] == a[i] && occupied[index]) index--;
		
		ans += inconveniences[index];
		occupied[index];
		
		for(int j=index+1; j < m; j++) {
			inconveniences[j] += 1;
		}
    }

    cout << ans << endl;
  }
}