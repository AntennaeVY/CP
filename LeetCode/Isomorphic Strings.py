class Solution:

    def isIsomorphic(self, s: str, t: str) -> bool:
        mapS_T, mapT_S = {}, {}

        for i in range(len(s)):
            if (
        			s[i] in mapS_T.keys() and mapS_T[s[i]] != t[i]
            		or t[i] in mapT_S.keys() and mapT_S[t[i]] != s[i]
                ):
                return False
            else:
                mapS_T[s[i]] = t[i]
                mapT_S[t[i]] = s[i]

        return True
