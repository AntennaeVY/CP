class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> s;

        for(int x : asteroids) {
            if (s.empty()) {
                s.push_back(x);
                continue;
            }

            if (x > 0) {
                s.push_back(x);
                continue;
            }

            bool destroyed = false;

            while(!s.empty() && s.back() > 0 && x < 0) {
                if (abs(x) == abs(s.back())) {
                    destroyed = true;
                    s.pop_back();
                    break;
                }

                if (abs(x) > abs(s.back())) {
                    s.pop_back();
                } else {
                    destroyed = true;
                    break;
                }
            }

            if (!destroyed) 
                s.push_back(x);
        } 

        return s;
    }
};