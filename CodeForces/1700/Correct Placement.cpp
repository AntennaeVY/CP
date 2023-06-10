#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> h(n), w(n);
		for(int i=0; i < n; i++) {
			cin >> h[i] >> w[i];
			
			if (w[i] > h[i])
				swap(w[i], h[i]);
		}
		
		vector<int> I(n);
		for(int i=0; i < n; i++) {
			I[i] = i;
		}
		
		sort(I.begin(), I.end(), [&](int i, int j){
			if (h[i] == h[j])
				return w[i] < w[j];
		
			return h[i] < h[j];
		});
		
		vector<int> ans(n, -1);
		int mn = -1;
		
		for(int i=0, j=0; i < n; i = j) {
			while(j < n && h[I[j]] == h[I[i]])
				j++;
				
			for(int k=i; k < j; k++) {
				if (mn != -1 && w[I[mn]] < w[I[k]])
					ans[I[k]] = I[mn]+1;
			}
			
			for(int k=i; k < j; k++) {
				if (mn == -1 || w[I[k]] < w[I[mn]])
					mn = k;
			}
		}
		
		for(auto &ansi : ans)
			cout << ansi << " ";
			
		cout << endl;
	}
}