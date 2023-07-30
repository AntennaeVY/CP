#include<bits/stdc++.h>
using namespace std;

int main() {
	int n;
	cin >> n;
	
	vector<int> start(n), end(n);

	for(int i=0; i < n; i++) {
		cin >> start[i] >> end[i];
	}
	
	sort(start.begin(), start.end());
	sort(end.begin(), end.end());

	int ans = 0, cnt = 0, j = 0;
	
	for(int i=0; i < n; i++) {
		while(j < n && end[j] <= start[i])
			cnt--, j++;

		cnt++;
		ans = max(ans, cnt);
	}	
	
	cout << ans << endl;
}