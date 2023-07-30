#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> h(n);
	for(int i=0; i < n; i++) {
		cin >> h[i];
	}

	vector<int> t;
	
	for(int i=0; i < n; i++) {
		auto it = upper_bound(t.begin(), t.end(), h[i]);
		
		if (it == t.end())
			t.push_back(h[i]);
		else
			*it = h[i];
	}
	
	cout << t.size() << endl;
}