#include<bits/stdc++.h>
using namespace std;

int main() {
	int n, k;
	cin >> n >> k;
	
	map<int, bool> present;
	queue<int> display;
	
	for(int i=0; i < n; i++) {
		int id;
		cin >> id;
		
		if (present[id] == false) {
			display.push(id);
			present[id] = true;
		}
		
		if (display.size() > k) {
			present[display.front()] = false;
			display.pop();
		}
	}
	
	vector<int> ans;
	
	while(!display.empty()) {
		ans.push_back(display.front());
		display.pop();
	}
	
	cout << ans.size() << endl;
	
	for(int i=ans.size()-1; i >= 0; i--) {
		cout << ans[i] << " ";
	}
}