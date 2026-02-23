#include<bits/stdc++.h>
using namespace std;

int ceil(int numerator, int denominator) {
	return (numerator + denominator - 1) / denominator;
}

int get_word_height(int cnt, int max_cnt) {
	int numerator = 40 * (cnt - 4);
	int denominator = max_cnt - 4;
	
	return 8 + ceil(numerator, denominator);
}

int get_word_width(int chars, int height) {
	int numerator = 9 * chars * height;
	int denominator = 16;
	
	return ceil(numerator, denominator);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	for(int c=1; c < 1000; c++) {
		int w, n;
		cin >> w >> n;	
		
		if (w == 0 && n == 0)
			break;
			
		int max_cnt = 0;
			
		vector<pair<string, int>> v;
		for(int i=0; i < n; i++) {
			string s;
			int t;
			
			cin >> s >> t;
			
			v.push_back({s, t});
			
			max_cnt = max(max_cnt, t);
		}
		
		int ans = 0, current_row = 0, max_height = 0;
		for(int i=0; i < n; i++) {
			int size = v[i].first.size();
			
			int height = get_word_height(v[i].second, max_cnt);
			int width = get_word_width(size, height);
			
			if (current_row + width > w) {
				ans += max_height;
				
				current_row = width + 10;
				max_height = height;
				
			} else {
				current_row += width + 10;
				max_height = max(max_height, height);
			}
			
		}
		
		ans += max_height;
		
		cout << "CLOUD " << c << ": " << ans << '\n';
	}
}