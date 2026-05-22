#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n, x, m;
	cin >> n >> x >> m;
	
	vector<double> hallway;
	for(int i=1; i <= n; i++) {
		hallway.push_back(i);
	}
	
	for(int i=0; i < m; i++) {
		int r;
		cin >> r;
		
		hallway.push_back(r + 0.5);
	}
	
	sort(hallway.begin(), hallway.end());
	
	int pos = 0;
	for(int i=0; i < hallway.size(); i++) {
		if (hallway[i] == x) {
			pos = i;
			break;
		}
	}
	
	int ans1 = 0, ans2 = 0;
	for(int i=pos; true; i=(i+1) % hallway.size()) {
		if (hallway[i] == 1)
			break;
			
		if (hallway[i] - (int)hallway[i])
			ans1++;
	}
	
	for(int i=pos; true; i=(i-1+hallway.size()) % hallway.size()) {
		if (hallway[i] == 1)
			break;
			
		if (hallway[i] - (int)hallway[i])
			ans2++;
	}
	
	cout << min(ans1, ans2) << "\n";
}