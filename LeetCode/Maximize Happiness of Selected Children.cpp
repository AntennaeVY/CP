class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        priority_queue<int> pq;
        
        for(auto h : happiness)
            pq.push(h);
        
        long long ans = 0, rem = 0;
        
        while(!pq.empty()) {
            int x = max(0LL, pq.top() - rem);
            pq.pop();
        
            ans += x, rem++;
            
            if (rem == k)
                break;
        }
        
        return ans;
    }
};