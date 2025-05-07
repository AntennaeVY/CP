#include <bits/stdc++.h>
using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t;
  cin >> t;

  while (t--) {
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for (auto &ai : a) cin >> ai;
    
    if (k == 1) {
    	int left = *max_element(a.begin(), a.end()-1) + a[n-1];
    	int right = *max_element(a.begin()+1, a.end()) + a[0];
    	
    	cout << max(left, right) << endl;
    	continue;
    }

	long long ans = 0;
	

    for(int i=1; i < n-1; i++) {
    	priority_queue<int, vector<int>, greater<int>> pq;
    	long long sum = 0;
    	
    	for(int j=i; j < n-1; j++) {
    		if (pq.size() < k-1) {	
    			pq.push(a[j]);
    			sum += a[j];
    		} else if (pq.top() < a[j]) {
    			sum -= pq.top();
    			
    			pq.pop();
    			pq.push(a[j]);
    			
    			sum += a[j];
    		}
    		ans = max(ans, sum + a[i-1] + a[j+1]);
    	}
    }
    
    cout << ans << endl;
  }
}