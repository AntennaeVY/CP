#include<bits/stdc++.h>
using namespace std;

int brute(int n, int k, vector<int> &a) {
	vector<int> p;
	
	for(int i=0; i < n; i++) {
		for(int j=0; j < n; j++) {
			p.push_back(a[i] + a[j]);		
		}
	}
	
	sort(p.begin(), p.end());
	return p[k-1];
}

int solve(int n, int k, vector<int> &a) {
	sort(a.begin(), a.end());
	
	long long c = 0, x = 0;
	for(int i=0; i < n; i++, x++) {
		long long d = 2*(n-i) - 1;
		
		if (c + d >= k)
			break;
		
		c += d;
	}
	
	int y = x;
	for(int i=x; i < n; i++, y++) {
		int d = 0;
		
		if (i == x) {
			d += 1;
		} else {
			d += 2;
		}
		
		if (c + d >= k) {
			y = i;
			break;
		}
		
		c += d;
	}
	
	return a[x] + a[y];
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	
	std::random_device rd; // obtain a random number from hardware
    std::mt19937 gen(rd()); // seed the generator
    
    std::uniform_int_distribution<> gen_n(1, 10); // define the range
    int n = gen_n(gen);
	
    std::uniform_int_distribution<> gen_k(1, n*n);
	int k = gen_k(gen);
	
	std::uniform_int_distribution<> gen_ai(1, 10);
	vector<int> a(n);
	for(int i=0; i < n; i++)
		a[i] = gen_ai(gen);
		
		
	while(true) {
		int x = solve(n, k, a);
		int y = brute(n, k, a);
		
		if (x != y) {
			
			cout << 1 << endl;
			cout << n << " " << k << endl;
			for(auto &ai : a)
				cout << ai << " ";
			cout << endl << endl;
			
			cout << x << " " << y << endl;
			break;
		}
	}
}