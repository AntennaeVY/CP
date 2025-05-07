#include<bits/stdc++.h>
using namespace std;

vector<int> f(2e5+2, 0);

bool check(vector<int> &a, int k, int m) {
	int cnt = 0, mex = 0;
	
	for(int i=0; i < a.size(); i++) {
		if (a[i] > a.size())
			continue;
		
		f[a[i]]++;
		while(f[mex]) mex++;
		
		if (mex >= m) {
			cnt++;
			mex = 0;
			
			for(int j=0; j <= min(m+1, (int)a.size() + 1); j++)
				f[j] = 0;
		}
	}
	
	for(int i=0; i <= a.size(); i++)
		f[i] = 0;
	
	return cnt >= k;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n, k;
		cin >> n >> k;
		
		vector<int> a(n);
		for(auto &ai : a) cin >> ai;
		
		int L=0, R=1E9;
		while(L+1 < R) {
			int M = L + (R-L)/2;
			
			if (check(a, k, M))
				L=M;
			else
				R=M;
		}
		
		cout << L << endl;
	}
}