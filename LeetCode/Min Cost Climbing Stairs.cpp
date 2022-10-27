class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> mincost(cost.size()+1, 0);
        mincost[0] = cost[0];
        mincost[1] = min(cost[0]+cost[1], cost[1]);
        
        cost.push_back(0);
        
        for(int i=2; i < cost.size(); i++) {
            mincost[i] = min(mincost[i-1] + cost[i], mincost[i-2] + cost[i]);
        }
        
        return mincost[cost.size()-1];
    }
};