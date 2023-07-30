class Solution {
public:
    bool isHappy(int n) {
        unordered_map<int, bool> m;
        int number = 0;
        
        while(m[n] == false) {
            if (n == 1) 
                return true;
            
            string number_str = to_string(n);
            m[n] = true;
            
            for (char digit : number_str) {
                number += (digit - '0') * (digit - '0');
            }
            
            n = number;
            number = 0;
        }
        
        return false;
    }
};