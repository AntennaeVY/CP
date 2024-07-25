class Solution {
public:
    int maxOperations(string s) {
        int n = s.size();
       
       int ans = 0;
       
       int i=0;
       while(i < n && s[i] == '0')
        i++;

        if (i == n)
            return 0;

        int cnt = 1;

        for(int j=i+1; j < n; j++) {
            if (s[j] == '0')
                continue;

            if (j-1 != i)
                ans += cnt;
        
            i = j;
            cnt++;
        }

        if (s.back() == '0')
            ans += cnt;

        return ans;
    }
};