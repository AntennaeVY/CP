class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        bool found = false;
        
        for(int i=0; i < matrix.size(); i++) {
            int l=0, r=matrix[0].size()-1;

            while(l <= r) {
                int mid = (l+r)/2;

                if (matrix[i][mid] == target) {
                    found = true;
                    break; 
                } else if (matrix[i][mid] > target) {
                    r = mid-1;
                } else {
                    l = mid+1;
                }
            }
        }

        return found;
    }
};