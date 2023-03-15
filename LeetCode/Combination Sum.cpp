class Solution {
private:
    vector<vector<int>> ans;

    void makeCombinations(vector<int> &a, vector<int> &c, int target, int i=0) {
        if (target == 0)
            ans.push_back(c);

        if (target <= 0 || i >= a.size())
            return;

        makeCombinations(a, c, target, i+1);
        c.push_back(a[i]);
        makeCombinations(a, c, target - a[i], i);
        c.pop_back();
    } 

public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> temp;
        makeCombinations(candidates, temp, target);
        return ans;
    }
};