class Solution {
private:
    map<int, bool> chosen;
    vector<vector<int>> ans;

    void generate_permutations(vector<int> &arr, vector<int> &p, int i=0) {
        if (i == arr.size()) {
            ans.push_back(p);
            return;
        }

        for(int j=0; j < arr.size(); j++) {
            if (chosen[j])
                continue;

            p.push_back(arr[j]);
            chosen[j] = true;
            generate_permutations(arr, p, i+1);
            chosen[j] = false;
            p.pop_back();
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> permutation;
        generate_permutations(nums, permutation);
        return ans;
    }
};