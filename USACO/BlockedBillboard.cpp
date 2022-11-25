#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("billboard.in");
	ofstream fout("billboard.out");
	
	vector<vector<pair<int,int>>> b(3);
	
	for(int i=0; i < 3; i++) {
		for(int j=0; j < 2; j++) {
			int x, y;
			fin >> x >> y;
			
			b[i].push_back({x,y});
		}
	}
	
	long long ans = 0;
	
	for(int i=0; i < 2; i++) {
		int width = b[i][1].first - b[i][0].first;
		int height = b[i][1].second - b[i][0].second;
		
		ans += 1LL*width*height;
		
		int intersectionWidth = min(b[i][1].first, b[2][1].first) - max(b[i][0].first, b[2][0].first);
		int intersectionHeight = min(b[i][1].second, b[2][1].second) - max(b[i][0].second, b[2][0].second);
		
		if (intersectionWidth < 0 || intersectionHeight < 0) 
			continue;
			
		ans -= intersectionWidth * intersectionHeight;
	}
	
	fout << ans << endl;
}