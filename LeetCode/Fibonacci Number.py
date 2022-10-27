class Solution:
    def fib(self, n: int) -> int:
        sequence = [0, 1]
            
        for i in range(2, n+1):
            sequence.append(sequence[i-1] + sequence[i-2])
        
        return sequence[n]