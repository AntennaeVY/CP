#include <bits/stdc++.h>
using namespace std;

int main() {
  int q;
  cin >> q;

  while (q--) {
    int n;
    cin >> n;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    
    vector<bool> moved(n, false);
    
    for(int i=1; i <= n; i++) {
    	for(int j=n-1; j > 0; j--) {
    		if (a[j] == i && a[j-1] > a[j] && !moved[j-1]) {
    			swap(a[j], a[j-1]);
    			moved[j-1] = true;
    		}
    	}
    }
    
    for(auto &ai : a) cout << ai << " ";
    cout << endl;
  }
}