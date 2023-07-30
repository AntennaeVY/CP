#include<bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	freopen("rental.in", "r", stdin);
	freopen("rental.out", "w", stdout);
	
	int N, M, R;
	cin >> N >> M >> R;
	
	vector<int> c(N), p(M), q(M), r(R);
	for(auto &ci : c) cin >> ci;
	for(int i=0; i < M; i++) cin >> q[i] >> p[i];
	for(auto &ri : r) cin >> ri;

	vector<int> z(M);
	vector<ll> milk(N+1), rent(R+1, 0), gallons(M+1, 0), profit(M+1, 0);
	
	iota(z.begin(), z.end(), 0);
	
	sort(c.begin(), c.end());
	sort(r.rbegin(), r.rend());
	sort(z.begin(), z.end(), [&](const int &i, const int &j){
		return p[i] > p[j];
	});
	
	for(int i=0; i < N; i++) {
		milk[i+1] = milk[i] + c[i];
	}
	
	for(int i=0; i < R; i++) {
		rent[i+1] = rent[i] + r[i];
	}
	
	for(int i=0; i < M; i++) {
		gallons[i+1] = gallons[i] + q[z[i]];
		profit[i+1] = profit[i] + 1LL*q[z[i]]*p[z[i]];
	}
	
	// cout << "-------------" << endl;
	// cout << "cows: " << endl;
// 	
	// for(int i=0; i < N; i++) {
		// cout << c[i] << " ";
	// }
// 	
	// cout << endl;
// 	
	// for(int i=0; i <= N; i++) {
		// cout << milk[i] << " ";
	// }
// 	
	// cout << "\n\nrent: " << endl;
// 	
	// for(int i=0; i < R; i++) {
		// cout << r[i] << " ";
	// }
// 	
	// cout << endl;
// 	
	// for(int i=0; i <= R; i++) {
		// cout << rent[i] << " ";
	// }
// 	
	// cout << "\n\ngallons: " << endl;
// 	
	// for(int i=0; i < M; i++) {
		// cout << q[z[i]] << " ";
	// }
// 	
	// cout << endl;
// 	
	// for(int i=0; i <= M; i++) {
		// cout << gallons[i] << " ";
	// }
// 	
	// cout << "\n\nprofits: " << endl;
// 	
	// for(int i=0; i < M; i++) {
		// cout << p[z[i]] << " ";
	// }
// 	
	// cout << endl;
// 
	// for(int i=0; i <= M; i++) {
		// cout << profit[i] << " ";
	// }
// 	
	// cout << endl;
	// cout << "--------------" << endl;
	
	ll ans = 0;
	
	for(int i=0; i <= min(N, R); i++) {
		ll cents = rent[i];
		
		ll remaining_milk = milk[N] - milk[i];
		ll last_store = distance(gallons.begin(), lower_bound(gallons.begin(), gallons.end(), remaining_milk));
		
		if (last_store != M+1)
			cents += profit[last_store-1];
		else
			cents += profit[M];
		
		if (last_store != M+1)
			cents += p[z[last_store-1]]*(remaining_milk - gallons[last_store-1]);
		
		ans = max(ans, cents);
	}
	
	cout << ans << endl;
}