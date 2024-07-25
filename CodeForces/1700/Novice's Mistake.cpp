#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int t;
	cin >> t;
	
	while(t--) {
		int n;
		cin >> n;
		
		vector<int> a, b;
		
		string s = to_string(n);
		int m = s.size();
		
		set<int> d;
		for(auto ch : s)
			d.insert(ch - 48);
		
		for(int i=1; i <= 1e4; i++) {
			for(int j=m*i-1; j >= 1; j--) {
				
				bool good = true;
				int k = n*i - j;
				
				if (m * i - j > to_string(k).size())
					break;
				
				if (m * i - j <= 0)
					continue;
					
				
				while(k) {
					if (d.count(k % 10) == 0) {
						good = false;
						break;
					}
					
					k /= 10;
				}
			
				if (!good)
					continue;
					
				k = n*i - j;
				
				if (to_string(k).size() != m*i - j)
					continue;
					
				string p = "";
				
				while(p.size() + m <= m*i - j) 
					p += s;
					
				p += s.substr(0, m*i - j - p.size());
				
				if (stoi(p) == k) {
					a.push_back(i);
					b.push_back(j);
				}
			}
		}
		
		cout << a.size() << endl;
		
		for(int i=0; i < a.size(); i++) {
			cout << a[i] << " " << b[i] << "\n";
		}
	}
}