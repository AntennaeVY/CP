#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	cin >> n;
	
	string s;
	cin >> s;
	
	int j = 0, k = 0;
	
	long long a = 0, b = 0; 
	for(int i=0; i < 2*n; i+=2) {
		while(j < 2*n && s[j] != 'A')
			j++;
			
		while(k < 2*n && s[k] != 'B')
			k++;
			
		if (j < 2*n)
			a += abs(j - i), j++;
		
		if (k < 2*n)
			b += abs(k - i), k++;
	}
	
	cout << min(a,b);
}