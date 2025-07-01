class Solution:
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        mp = Counter(nums)
        
        pq = []

        for num,count in mp.items():
            if len(pq) < k:
                heapq.heappush(pq,(count,num))
            else:
                if count > pq[0][0]:
                    heapq.heappop(pq)
                    heapq.heappush(pq,(count,num))
        
        return [num for count,num in pq]

        