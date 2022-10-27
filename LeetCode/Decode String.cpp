class Solution {
public:
    string decodeString(string s) {
        stack<int> times;
        stack<string> processed;
        
        string current = "";
        int num = 0;
    
        for(int i=0; i < s.size(); i++) {
            if (isdigit(s[i])) {
                num = num*10 + (s[i] - '0');
            }
            
            if (s[i] == '[') {
                processed.push(current);
                times.push(num);
                num = 0;
                current = "";
            }
            
            if (s[i] == ']') {
                string last = processed.top();
                int count = times.top();
                
                string accum = "";
                
                for(int j=0; j < count; j++) {
                    accum += current;
                };
                
                current = last + accum;
                
                processed.pop();
                times.pop();
            }
            
            if (isalpha(s[i])) {
                current += s[i];
            }
        }
        
        return current;
    }
};

// 3[ab2[cd3[ef4[gh]]]]