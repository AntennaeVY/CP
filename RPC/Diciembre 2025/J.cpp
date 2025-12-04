#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	string s;
	cin >> s;
	
	vector<string> v(5);
	for(auto &vi : v) cin >> vi;
	
	sort(v.begin(), v.end());
	
	bool ok = false;

	do {
		string t = "";
		for(auto &vi : v)
			t += vi;
		
		ok |= s.find(t) != string::npos;
	} while(next_permutation(v.begin(), v.end()));
	
		
	cout << (ok ? "Nooo, la polizzia" : "Sargento Camelas, Gracias!") << endl;
}