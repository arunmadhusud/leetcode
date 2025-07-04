class Solution:
    def leastInterval(self, tasks: List[str], n: int) -> int:
        freq = Counter(tasks)
        pq = [-val for val in freq.values()]
        heapq.heapify(pq)
        time = 0
        queue = deque()
        while pq or queue:
            time+=1
            if pq:
                count = heapq.heappop(pq)                
                if count+1 != 0:
                    queue.append([time+n,count+1])
            if queue and queue[0][0]==time:
                heapq.heappush(pq, queue.popleft()[1])            

        
        return time



        