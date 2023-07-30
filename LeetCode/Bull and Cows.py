class Solution:
    def getHint(self, secret: str, guess: str) -> str:
        bulls, cows = 0, 0
        hashmap = {}
        
        for i in range(len(guess)):
            if secret[i] == guess[i]:
                bulls += 1
            else:
                hashmap[secret[i]] = hashmap.get(secret[i], 0) + 1
        
        for i in range(len(guess)):
            if secret[i] == guess[i]:
                continue
            elif hashmap.get(guess[i], 0) != 0:
                cows += 1
                hashmap[guess[i]] -= 1
            
        return f'{bulls}A{cows}B'