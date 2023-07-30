// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    long long firstBadVersion(int n) {
        long long l=0, r=n;
        
        while(l + 1 < r) {
            int mid = l+(r-l)/2;
            
            if (isBadVersion(mid)) 
                r=mid;
            else
                l=mid;
        }
        
        return r;
    }
};