#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;

  while (t--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
	
	auto V = [&](int i) {
		return (i > 0 && i < n-1 && a[i-1] > a[i] && a[i] < a[i+1]);
	};
	
	auto H = [&](int i) {
		return (i > 0 && i < n-1 && a[i-1] < a[i] && a[i] > a[i+1]);
	};
    
    int cnt = 0;
	vector<bool> C(n);

    for(int i=1; i < n-1; i++) {
    	cnt += C[i] = (V(i) || H(i));
    }
    
    int ans = cnt;
    
    for(int i=1; i < n-1; i++) {
    	int tmp = a[i];
    	a[i] = a[i-1];
    	ans = min(ans, cnt - C[i-1] + V(i-1) + H(i-1) - C[i] + V(i) + H(i) - C[i+1] + V(i+1) + H(i+1));
    	a[i] = a[i+1];
    	ans = min(ans, cnt - C[i-1] + V(i-1) + H(i-1) - C[i] + V(i) + H(i) - C[i+1] + V(i+1) + H(i+1));
    	a[i] = tmp;
    }
    
    cout << ans << endl;
  }
}