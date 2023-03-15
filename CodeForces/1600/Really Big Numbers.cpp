#include<bits/stdc++.h>
using namespace std;

bool can(long long mid, long long x) {
	string s = to_string(mid);
	long long cnt = 0;
	
	for(int i=0; i < s.size(); i++) {
		cnt += s[i] - 48;
	}
	
	return (mid - cnt >= x);
}

int main() {
	long long n, s;
	cin >> n >> s;
	
	long long l=1, r=n+1;
	while(l+1 < r) {
		long long mid = l + (r-l)/2;
		
		if (can(mid, s)) 
			r=mid;
		else
			l=mid;
	}
	
	cout << n+1-r << endl;
}