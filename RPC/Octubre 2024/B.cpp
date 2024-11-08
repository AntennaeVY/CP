#include<bits/stdc++.h>
using namespace std;

int main() {
	string s;
	cin >> s;
	
	set<char> st;
	
	for(auto &c : s) {
		if (c != '-')
			st.insert(c);
	}
	
	cout << st.size() << endl;
}