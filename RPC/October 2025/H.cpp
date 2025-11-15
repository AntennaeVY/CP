#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s1, s2, s3;
	cin >> s1 >> s2 >>  s3;
	
	string ans = "";

	int x = 0, y = 0, z = 0;
	int p = s1.size(), q = s2.size(), r = s3.size();
	while(x < p || y < q || z < r) {
		if (x < p && y < q) {
			if (s1[x] == s2[y])
				ans += s1[x], x++, y++;
		}
		
		if (x < p && z < r) {
			if (s1[x] == s3[z])
				ans += s1[x], x++, z++;
		}
		
		if (y < q && z < r) {
			if (s2[y] == s3[z])
				ans += s2[y], y++, z++;
		}
	}
	
	cout << ans << "\n";
}