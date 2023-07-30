class DSU {
	private:
		vector<int> parent;
	public:
		DSU(int size) {
			parent.resize(size);
			fill(parent.begin(), parent.end(), -1);	
		}
		
		int find(int x) {
			if (parent[x] < 0)
				return x;
				
			int root = x;
			while(parent[root] >= 0)
				root = parent[root];
				
			// Path compression
			while(x != root) {
				int next = parent[x];
				parent[x] = root;
				x = next;
			}
			
			return x;
		}
			
		int join(int x, int y) {
			if (parent[(x = find(x))] > (parent[(y = find(y))]))
				swap(x,y);
				
			if (x == y)
				return x;
				
			parent[x] += parent[y];
			parent[y] = x;
			
			return x;
		}
		
		int component_size(int x) {
			return abs(parent[find(x)]);
		}
		
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        DSU dsu(isConnected.size());

        for(int i=0; i < isConnected.size(); i++) {
            for(int j=i+1; j < isConnected.size(); j++) {
                if (isConnected[i][j])
                    dsu.join(i, j);
            }
        }

        set<int> provinces;
        for(int i=0; i < isConnected.size(); i++) {
            provinces.insert(dsu.find(i));
        }

        return provinces.size();
    }
};