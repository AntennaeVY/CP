#include<bits/stdc++.h>
using namespace std;

int floor(int x, int y) {
	if (y < 0) x *= -1, y *= -1;
	if (x >= 0) return x/y;
	
	return - (-x + y-1) / y;
}

int ceil(int x, int y) {
	if (y < 0) x *= -1, y *= -1;
	if (x >= 0) return (x + y-1) / y;
	
	return - (-x / y);
}

bool can(int L, vector<int> &v) {
	int n = v.size();
	vector<bool> dp(n + 1);
	dp[0] = true;
	
	int mx = -1;
	
	for(int i=1; i <= n; i++) {
		int j = i-L;
		
		if (j >= 0 && dp[j])
			mx = max(mx, v[j] + 1);
				
		dp[i] = (i <= mx);
	}
	
	return dp[n];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, l, h;
	cin >> n >> l >> h;
	
	vector<int> a(n);
	for(auto &ai : a) cin >> ai;
	
	vector<int> low(n), high(n);

	// ceil((l - x), 12)<= k <= floor((h - x), 12)
	for(int i=0; i < n; i++) {
		low[i] = ceil((l - a[i]), 12);
		high[i] = floor((h - a[i]), 12);
	}
	
	vector<int> longest(n, 0);
	deque<int> dqML, dqMH;
	
	int j=-1;
	for (int i = 0; i < n; i++) {
	    while (j + 1 < n) {
	        int t = j + 1;
	
	        while (!dqML.empty() && low[t] >= low[dqML.back()]) dqML.pop_back();
	        dqML.push_back(t);
	
	        while (!dqMH.empty() && high[t] <= high[dqMH.back()]) dqMH.pop_back();
	        dqMH.push_back(t);
	
	        if (low[dqML.front()] <= high[dqMH.front()]) {
	            j = t;
	        } else {
	            if (dqML.back() == t) dqML.pop_back();
	            if (dqMH.back() == t) dqMH.pop_back();
	            break;
	        }
	    }
	
	    longest[i] = j; 
	    
	    if (!dqML.empty() && dqML.front() == i) dqML.pop_front();
	    if (!dqMH.empty() && dqMH.front() == i) dqMH.pop_front();
	}
	
	int L=0, R=n+1;
	while(L + 1 < R) {
		int M = L + (R-L)/2;
		
		if (can(M, longest))
			L = M;
		else
			R = M;
	}
	
	cout << L << '\n';
}