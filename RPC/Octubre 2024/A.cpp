#include<bits/stdc++.h>
using namespace std;

int main() {
	int a;
	cin >> a;
	
	int w, v;
	cin >> w >> v;
	
	cout << ((w+v-1)/v >= a) << endl;
}