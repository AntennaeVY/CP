#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	map<int, int> m;
	
	int n = 0;
	
	while(t--) {
		string s;
		cin >> s;
		
		int x;
		cin >> x;
		
		if(s == "insert")
			m[x]++, n++;
		
		if (s == "delete" && m[x] > 0)
			m[x]--, n--;
		
		if (!m[x])
			m.erase(x);
			
		bool homo = m.size() < n;
		bool hetero = m.size() >= 2;
		bool both = homo & hetero;
		
		if (both)
			cout << "both" << endl;
		else if (homo)
			cout << "homo" << endl;
		else if (hetero)
			cout << "hetero" << endl;
		else
			cout << "neither" << endl;
	}
}