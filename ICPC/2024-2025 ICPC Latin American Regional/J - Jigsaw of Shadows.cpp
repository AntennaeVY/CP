#include<bits/stdc++.h>
using namespace std;

constexpr double PI = acos(-1);

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int tetha, n;
	cin >> tetha >> n;
	
	vector<pair<double,double>> v(n);
	
	double tn = tan(tetha * PI / 180.0);
	
	for(int i=0; i < n; i++) {
		int x, h;
		cin >> x >> h;
		
		v[i] = {x, x + h / tn};
	}
	
	sort(v.begin(), v.end());
	
	double ans = 0;
	double last = v[0].first;
	
	for(int i=0; i < n; i++) {
		last = max(v[i].first, last);
		
		if (last < v[i].second)
			ans += v[i].second - last;
			
		last = max(v[i].second, last);
	}
	
	cout << fixed << setprecision(6) << ans << '\n';
}