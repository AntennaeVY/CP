#include<bits/stdc++.h>
using namespace std;

#define DBG(x) cout<<#x<<" = "<<(x)<<endl;
#define ALL(x) (x).begin(),(x).end()
#define RALL(x) (x).rbegin(),(x).rend()
#define SZ(x) int((x).size())
#define READARR(x) for(auto &xi : (x)) cin >> xi;
#define YES cout << "YES" << '\n';
#define NO cout << "NO" << '\n';

#define pb push_back
#define mp make_pair
#define fst first
#define snd second
#define vi vector<int>
#define vll vector<long long>
#define ll long long

template<class x> ostream & operator<<(ostream & out, vector<x> v){
    out<<"[ ";
    for(auto y : v) out<<y<<" ";
    out<<"]";
    return out;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t=1;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vi a(n);
		READARR(a);
		
		vector<vi> dp(n/2+1, vi(2));
		
		for(int i=2; i <= n/2; i++) {
			dp[i][0] = min(
				dp[i-1][0] + (a[i-1] == a[i-2]) + (a[n-i] == a[n-i+1]), 
				dp[i-1][1] + (a[i-1] == a[n-i+1]) + (a[n-i] == a[i-2])
			);
		
			// DBG(i)
			// DBG(a[i-1]); DBG(a[i-2])
			// DBG(a[n-i-1]); DBG(a[n-i])
			
			dp[i][1] = min(
				dp[i-1][0] + (a[i-1] == a[n-i+1]) + (a[n-i] == a[i-2]), 
				dp[i-1][1] + (a[i-1] == a[i-2]) + (a[n-i] == a[n-i+1])
			);
		}
		
		if (n % 2) {
			dp[n/2][0] += (a[n/2] == a[n/2-1]) + (a[n/2] == a[n/2+1]);
			dp[n/2][1] += (a[n/2] == a[n/2+1]) + (a[n/2] == a[n/2-1]);
		} else {
			dp[n/2][0] += (a[n/2-1] == a[n/2]);
			dp[n/2][1] += (a[n/2-1] == a[n/2]);
		}
		
		// DBG(dp);
		
		cout << min(dp[n/2][0], dp[n/2][1]) << endl;
	}
}