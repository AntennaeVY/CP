class Solution {
public:
    int minimumLength(string s) {
        int l=0, r=s.size()-1;
        int start = 0, end = s.size()-1;

        while(l < r) {
            if (s[l] != s[r])
                break;

            while (l+1 < r && s[l+1] == s[start])
                l++;

            while (l+1 < r && s[r-1] == s[end])
                r--;

            l++, r--;
            
            start = l;
            end = r;
        }

        if (l > r)
            return 0;
        else
            return r-l+1;
    }
};