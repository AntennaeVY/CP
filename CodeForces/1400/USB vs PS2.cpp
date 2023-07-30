#include<bits/stdc++.h>
using namespace std;

int main() {
	int a, b, c;
	cin >> a >> b >> c;
	
	int m;
	cin >> m;
	
	vector<pair<int, string>> p;
	for(int i=0; i < m; i++) {
		int cost;
		string type;
		
		cin >> cost >> type;
		
		p.emplace_back(cost, type);
	}
	
	sort(p.begin(), p.end());
	
	int total = a + b + c;
	long long ans = 0;
	
	for(int i=0; i < m; i++) {
		auto [cost, type] = p[i];
		
		if (type == "USB" && a != 0)
			ans += cost, a--;
		else if (type == "USB" && c != 0)
			ans += cost, c--;
		
		if (type == "PS/2" && b != 0)
			ans += cost, b--;
		else if (type == "PS/2" && c != 0) 
			ans += cost, c--;
	}

	total -= (a + b + c);
	
	cout << total << " " << ans << endl;
}