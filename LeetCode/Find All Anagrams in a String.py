class Solution:
    def findAnagrams(self, s: str, p: str) -> List[int]:
        if (len(p) > len(s)):
            return []
        
        sm, pm = {}, {}
        ans = []
        
        for letter in p:
            pm[letter] = pm.get(letter, 0) + 1
        
        l = 0
        
        for r in range(len(s)):
            sm[s[r]] = sm.get(s[r], 0) + 1
            
            while r-l+1 > len(p):
                sm[s[l]] = sm.get(s[l], 1) - 1
                
                if (sm[s[l]] == 0):
                    sm.pop(s[l], -1)
                    
                l += 1
            
            if (sm == pm):
                ans.append(l)
        
        return ans
            