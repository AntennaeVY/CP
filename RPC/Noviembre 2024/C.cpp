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
	
	map<char, int> m = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};
	
	while(t--) {
		string s;
		cin >> s;
		
		int n = s.size();
		int mx = 0, ans = 0;
		
		for(int i=n-1; i >= 0; i--) {
			if (m[s[i]] >= mx)
				ans += m[s[i]], mx = m[s[i]];
			else
				ans -= m[s[i]];
		}
		
		cout << ans << endl;
	}
}