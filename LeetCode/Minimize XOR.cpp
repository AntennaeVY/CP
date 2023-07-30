class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int cnt = 0, cnt2 = 0;
        int cpy2 = num2, cpy1= num1;
        
        for(int i=1; cpy2; i++) {
            cnt += cpy2&1;
            cpy2 >>= 1;
        }
        
        for(int j=1; cpy1; j++) {
            cnt2 += cpy1&1;
            cpy1 >>= 1;
        }
        
        if (cnt2 == cnt)
            return num1;
        
        cpy1 = num1;
        cpy2 = num2;
        
        if (cnt2 > cnt) {
            int amount = cnt2-cnt;
            int i = 0;
            
            while(amount--) {
                while(true) {
                     if (cpy1 & 1 << i) {
                         cpy1 &= ~(1 << i);
                         i++; 
                         break;
                     }
                    
                    i++;
                }
            }
        }
        
        if (cnt > cnt2) {
            int amount = cnt-cnt2;
            int i = 0;
            
            while(amount--) {
                while(true) {
                     if (!(cpy1 & (1 << i))) {
                         cpy1 |= (1 << i);
                         i++; 
                         break;
                     }
                    
                    i++;
                }
            }
        }
        
        return cpy1;
    }
};