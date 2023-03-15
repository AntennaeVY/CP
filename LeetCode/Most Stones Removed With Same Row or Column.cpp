class DSU {
    private:
        map<pair<int,int>, pair<int,int>> m;
        map<pair<int,int>, int> size;
    public:
        DSU() {
        }

        pair<int,int> find(pair<int,int> x) {
            if (m.find(x) == m.end()) {
                m[x] = x;
                size[x] = 1;
            }

            if (m[x] == x)
                return x;

            auto root = x;
            while(m[root] != root) {
                root = m[root];
            }

            while(m[x] != root) {
                auto next = m[x];
                m[x] = root;
                x = next;
            }

            return root;
        }

        pair<int, int> join(pair<int, int> x, pair<int,int> y) {
            if ((x = find(x)) == (y = find(y)))
                return x;

            if (size[x] < size[y])
                swap(x, y);

            size[x] += size[y];
            m[y] = x;

            return find(y);
        }

        int component_size(pair<int,int> x) {
            return size[find(x)];
        }
};

class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        DSU dsu;
        set<pair<int, int>> roots;

        for(int i=0; i < stones.size(); i++) {
            auto x = make_pair(stones[i][0], stones[i][1]);
            for(int j=i+1; j < stones.size(); j++) {
                auto y = make_pair(stones[j][0], stones[j][1]);
                
                if (x.first == y.first || x.second == y.second) {
                    dsu.join(x, y);
                }
            }
        }

        for(int i=0; i < stones.size(); i++) {
            auto x = make_pair(stones[i][0], stones[i][1]);
            roots.insert(dsu.find(x));
        }

        int ans = 0;
        for(auto x : roots) {
            ans += dsu.component_size(x) - 1;
        }

        return ans;
    }
};