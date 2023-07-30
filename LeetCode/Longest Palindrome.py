class Solution:
    def longestPalindrome(self, s: str) -> int:
        odd = sum([x&1 for x in collections.Counter(s).values()])
        return len(s) - odd + bool(odd)
        