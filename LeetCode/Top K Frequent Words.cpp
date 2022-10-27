struct myComp {
    constexpr bool operator()(
        pair<int, string> const& a,
        pair<int, string> const& b)
        const noexcept
    {
        if (a.first == b.first) 
            return a.second > b.second;
        else
            return a.first < b.first;
    }
};

class Solution {
public:  
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> m;
        priority_queue<pair<int, string>, vector<pair<int,string>>, myComp> q;
        
        for(int i=0; i < words.size(); i++) {
            m[words[i]]++;
        }
        
        for(auto x : m) {
            q.push({x.second, x.first});
        }
        
        vector<string> ans;
        
        for(int i=0; i < k; i++) {
            if (!q.empty()) {
                ans.push_back(q.top().second);
                q.pop();
            }
        }
        
        
        
        return ans;
    }
};