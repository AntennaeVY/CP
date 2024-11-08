#include<bits/stdc++.h>
using namespace std;

constexpr int MAXN = 1e3+5;
constexpr long double INF = 2e9;

int n, l;
vector<tuple<int,int,int>> a;
long double memo[MAXN];

long double dp(int i) {
	auto [x, m, d] = a[i];
	
	if (memo[i] != INF)
		return memo[i];
	
	if (i+1 != n)
		memo[i] = (get<0>(a[i+1]) - x) + memo[i+1];
	else
		memo[i] = (l - x);
	
	int L=i, R=n;
	while(L+1 < R) {
		int M = L + (R-L)/2;
		
		auto [xi, mi, di] = a[M];
		
		if (xi < x + m*d)
			L = M;
		else
			R = M;
	}
	
	if (R==n) {
		long double dist = l - x;
		
		if (m * d >= dist)
			memo[i] = min(memo[i], dist / m);
		else
			memo[i] = min(memo[i], d + (dist - m*d));
	} else {
		auto [xi, mi, di] = a[R];
		
		long double dist = xi - x;
		
		memo[i] = min(memo[i], d + (dist - m*d) + memo[R]);
	}
	
	return memo[i];
}

int main() {
	cin >> n >> l;
	

	for(int i=0; i < n; i++) {
		int x, m, d;
		cin >> x >> m >> d;
		
		a.emplace_back(x,m,d);
		memo[i] = INF;
	}
	
	memo[n] = INF;
	
	sort(a.begin(), a.end());
	
	long double ans = 2e9;
	
	for(int i=n-1; i >= 0; i--) {
		auto [x, m, d] = a[i];
		ans = min(ans, x + dp(i));
	}

	cout << fixed << setprecision(8) << ans << endl;
}