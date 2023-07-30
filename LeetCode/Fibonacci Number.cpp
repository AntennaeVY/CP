class Solution {
public:
    int fib(int n) {
        vector<int> sequence = {0, 1};
        
        for(int i=2; i <= n; i++) {
            sequence.push_back(sequence[i-1] + sequence[i-2]);
        }
        
        return sequence[n];
    }
};