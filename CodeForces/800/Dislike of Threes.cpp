#include<bits/stdc++.h>
using namespace std;

int main() {
	int t;
	cin >> t;
	
	vector<int> nums;
	for(int i=1; nums.size() < 10001; i++) {
		if (i % 3 == 0 || i % 10 == 3)
			continue;
			
		nums.push_back(i);
	}
	
	while(t--) {
		int k;
		cin >> k;
		
		cout << nums[k-1] << endl;
	}
}