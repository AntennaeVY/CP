#include<bits/stdc++.h>
using namespace std;

void solve(stringstream &cin, stringstream &cout) {
	int q;
	cin >> q;
	
	vector<long double> t(q);
	vector<long double> s(q), a(q), b(q);
	
	a[0] = b[0] = 1;
	
	for(int i=0; i < q; i++) {
		int c;
		cin >> c;
		
		if (i > 0)
			s[i] = s[i-1], a[i] = a[i-1], b[i] = b[i-1];
		
		if (c == 1) {
			int x;
			cin >> x;
			
			t[i] = x;
		} else if (c == 2) {
			long long x;
			cin >> x;
			
			s[i] += x * b[i];
		} else if (c == 3) {
			long long pa, qb;
			cin >> pa >> qb;
			
			s[i] *= pa;
			a[i] *= pa, b[i] *= qb;
		} else if (c == 4) {
			int j;
			cin >> j;
			
			j--;
			
			long double xp = (t[j] - s[j] / b[j]) * b[j] / a[j];
			long double ans = xp * a[i] / b[i] + s[i] / b[i];
			
			cout << fixed << setprecision(0) << ans << "\n";
		}
	}
}

void brute(stringstream &cin, stringstream &cout) {
	int q;
	cin >> q;
	
	vector<long double> t(q);
	vector<long double> s(q), ma(q, 1), mb(q, 1);
	
	for(int i=0; i < q; i++) {
		int c;
		cin >> c;
		
		if (c == 1) {
			int x;
			cin >> x;
			
			t[i] = x;
		} else if (c == 2) {
			int x;
			cin >> x;
			
			s[i] += x;
		} else if (c == 3) {
			int a, b;
			cin >> a >> b;
			
			ma[i] = a;
			mb[i] = b;
		} else if (c == 4) {
			int j;
			cin >> j;
			
			j--;
			
			long double ans = t[j];
			for(int k=j; k < i; k++)
				ans += s[k], ans *= ma[k], ans /= mb[k];
		
			cout << fixed << setprecision(0) << ans << "\n";
		}
	}

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	while(true) {
		// string input(
			// istreambuf_iterator<char>(cin), 
			// istreambuf_iterator<char>()
		// );
		
		random_device rd;
		mt19937 gen(rd());
		
		uniform_int_distribution<> gen_q(1, 10);
		uniform_int_distribution<> gen_c(1, 4);
		uniform_int_distribution<> gen_x(1, 100000000);
		uniform_int_distribution<> gen_a(-100000000, 100000000), gen_b(-100000000, 100000000);
		uniform_int_distribution<> gen_s(-100000000, 100000000);
		
		string input;
		
		int q = gen_q(gen);
		input += to_string(q) + '\n';
		
		vector<int> v;
		
		for(int i=1; i <= q; i++) {
			int c;
			
			do {	
			 	c = gen_c(gen);
			} while(c == 4 && v.empty());
			
			input += to_string(c) + ' ';
			
			if (c == 1) {
				int x = gen_x(gen);
				
				input += to_string(x);
				
				v.push_back(i);
			} else if (c == 2) {
				int s = gen_s(gen);
				
				input += to_string(s);
			} else if (c == 3) {
				int a = gen_a(gen);
				int b = gen_b(gen);
				
				input += to_string(a) + ' ' + to_string(b);
			} else {
				uniform_int_distribution<> gen_j(0, v.size() - 1);
				int j = gen_j(gen);
				
				input += to_string(v[j]);
			}
			
			
			input += '\n';
		}
		
		stringstream cin_brute(input), cin_solve(input);
		stringstream cout_brute, cout_solve;
		
		brute(cin_brute, cout_brute);
		solve(cin_solve, cout_solve);
		
		string output_brute = cout_brute.str();
		string output_solve = cout_solve.str();
		
		if (
			output_brute
			!= output_solve
		) {
			cout << "EXPECTED ===== " << endl;
			// cout << output_brute.substr(0, output_brute.size() - 2) << endl;
			cout << output_brute << endl;
			cout << endl;
			cout << "GOT ======= " << endl;
			// cout << output_solve.substr(0, output_solve.size() - 2) << endl;
			cout << output_solve << endl;
			cout << endl;
			
			cout << input;
			break;
		}
	}
}