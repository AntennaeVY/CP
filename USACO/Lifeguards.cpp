#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("lifeguards.in");
	ofstream fout("lifeguards.out");
	
	int n;
	fin >> n;
	
 	vector<array<int, 3>> p;
 	
 	for(int i=0; i < n; i++) {
 		int l, r;
 		fin >> l >> r;
 		
 		p.push_back({l, i, 1});
 		p.push_back({r, i, 0});
 	}
 	
 	sort(p.begin(), p.end());
 	
 	set<int> s;
 	long long total = 0;
 	int mn = 1e9+5, prev = 0;
 	
 	vector<int> single(n);
 	
 	for(int i=0; i < 2*n; i++) {
 		if (s.size() == 1)
 			single[*s.begin()] += p[i][0] - prev;
 		
 		if (!s.empty())
 			total += p[i][0] - prev;
 		
 		if (p[i][2])
 			s.insert(p[i][1]);
 		else
 			s.erase(p[i][1]);
 		
 		prev = p[i][0];
 	}
 	
 	mn = *min_element(single.begin(), single.end());
 	
	fout << total - mn << endl;
}