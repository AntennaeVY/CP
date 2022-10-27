class Solution {
public:
    int climbStairs(int n) {
        vector<long long> climb(n+2, 1);
        climb[2] = 2;
        
        for(int i=3; i <= n; i++) {
            climb[i] = climb[i-1] + climb[i-2];
        }
        
        return climb[n];
    }
};