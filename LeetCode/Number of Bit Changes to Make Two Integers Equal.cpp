class Solution {
public:
    int minChanges(int n, int k) {
        int ans = 0;
        bool can = true;
        
        for(int i=0; i < 32; i++) {
            int nb = (n >> i) & 1;
            int kb = (k >> i) & 1;

            if (kb == nb)
                continue;

            if ((kb ^ nb) == kb)
                can = false;
            else
                ans++;
        }

        return (can ? ans : -1);
    }
};