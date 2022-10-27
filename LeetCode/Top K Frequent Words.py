class Element:
    def __init__(self, key, value):
        self.key = key
        self.value = value
        
    def __lt__(self, other):
        if self.key == other.key:
            return self.value < other.value
        else:
            return self.key < other.key

class Solution:
    def topKFrequent(self, words: List[str], k: int) -> List[str]:
        frequency_map = {}
        tuples_heap = []
        ans = []
        
        for word in words:
            frequency_map[word] = frequency_map.get(word, 0) + 1
        
        for key, value in frequency_map.items():
            tuples_heap.append(Element(-value, key))
        
        heapq.heapify(tuples_heap)
        
        for i in range(k):
            ans.append(heapq.heappop(tuples_heap).value)
        
        return ans
        
        