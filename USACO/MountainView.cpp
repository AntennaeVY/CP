#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("mountains.in", "r", stdin);
	freopen("mountains.out", "w", stdout);
	
	int n;
	cin >> n;
	
	vector<int> x(n), y(n), z(n);
	for(int i=0; i < n; i++) {
		cin >> x[i] >> y[i];
		
		z[i] = i;
	}

	sort(z.begin(), z.end(), [&](int i, int j){
		if (x[i] - y[i] == x[j] - y[j])
			return y[i] > y[j];
			
		return x[i] - y[i] < x[j] - y[j];
	});
	
	int ans = 1;
	int last_end = x[z[0]] + y[z[0]];
	 
	for(int i=1; i < n; i++) {
		int end = x[z[i]] + y[z[i]];
		
		if (end > last_end)
			ans++, last_end = end;
	}
	
	cout << ans << endl;
}