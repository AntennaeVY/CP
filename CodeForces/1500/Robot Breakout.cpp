#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int q;
	cin >> q;
	
	while(q--) {
		int n;
		cin >> n;
		
		vector<int> x(n), y(n), f1(n), f2(n), f3(n), f4(n);
		for(int i=0; i < n; i++) {
			cin >> x[i] >> y[i];
			cin >> f1[i] >> f2[i] >> f3[i] >> f4[i];
		}
		
		vector<int> zx(n), zy(n);
		iota(zx.begin(), zx.end(), 0);
		iota(zy.begin(), zy.end(), 0);
		
		sort(zx.begin(), zx.end(), [&](int i, int j) { 
			return x[i] < x[j];
		});
		
		sort(zy.begin(), zy.end(), [&](int i, int j) { 
			return y[i] < y[j];
		});
		
		int min_x = -1e5, min_y = -1e5;
		int max_x = 1e5, max_y = 1e5;
		
		for(int i=0; i < n; i++) {
			if (f1[zx[i]] == 0)
				min_x = max(min_x, x[zx[i]]);
				
			if (f3[zx[i]] == 0)
				max_x = min(max_x, x[zx[i]]);
		}
		
		for(int i=0; i < n; i++) {
			if (f2[zy[i]] == 0)
				max_y = min(max_y, y[zy[i]]);
				
			if (f4[zy[i]] == 0)
				min_y = max(min_y, y[zy[i]]);
		}
		
		if (min_y > max_y || min_x > max_x)
			cout << 0 << endl;
		else 
			cout << "1 " << min_x << " " << min_y << endl;
	}
}