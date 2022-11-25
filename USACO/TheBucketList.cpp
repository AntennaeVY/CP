#include<bits/stdc++.h>
using namespace std;

int main() {
	ifstream fin("blist.in");
	ofstream fout("blist.out");
	
	int n;
	fin >> n;
	
	map<int, int> buckets_needed, buckets_freed;
	set<int> start, end;
	int buckets = 0, total_amount = 0;
	
	for(int i=0; i < n; i++) {
		int si, ti, bi;
		fin >> si >> ti >> bi;
	
		start.insert(si);
		end.insert(ti);
			
		buckets_needed[si] = bi;
		buckets_freed[ti] = bi;
	}
	
	for(int i=1; i <= 1000; i++) {
		if (start.count(i)) {
			buckets += buckets_needed[i];
		}
		
		if (end.count(i)) {
			buckets -= buckets_freed[i];
		}
		
		total_amount = max(total_amount, buckets);
	}
	
	fout << total_amount << endl;
}