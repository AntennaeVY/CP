class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if (n==0) return tasks.size();

        map<char, int> cnt;
        int mx = 0, mx_cnt = -1;

        for(auto task : tasks) {
            cnt[task] += 1;

            mx = max(mx, cnt[task]);
        }

        for (auto i : cnt) {
            if (i.second == mx)
                mx_cnt += 1;
        }

        return max((int)tasks.size(), mx*(n+1) - n + mx_cnt);
    }
};