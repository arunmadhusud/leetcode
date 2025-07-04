class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        pq = []
        for task,count in freq.items():
            heapq.heappush(pq,-count)
        time = 0
        queue = []
        while pq or queue:
            time+=1
            if pq:
                count = pq[0]
                heapq.heappop(pq)
                if count+1 != 0:
                    queue.append([time+n,count+1])
            while queue and queue[0][0]==time:
                heapq.heappush(pq, queue[0][1])
                queue.pop(0)

        
        return time



        