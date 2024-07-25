#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		string b;
		cin >> b;
		
		set<char> st;
		
		for(auto ch : b)
			st.insert(ch);
	
		string R = "";
		
		while(!st.empty()) {
			R += *st.begin();
			st.erase(st.begin());
		}
		
		int m = R.size();
		
		string S = "";
		
		for (int i = 0; i < n; i++) {
			int l = 0, r = m;
			
			while(r - l > 1) {
				int x = l + (r - l) / 2;
			
				if (R[x] <= b[i])
					l = x;
				else
					r = x;
			}

			S += R[m - 1 - l];
		}
		
		cout << S << endl;
	}
}