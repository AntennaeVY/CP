#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	set<char> st(s.begin(), s.end());
	
	cout << s.size() - st.size() << endl;
}