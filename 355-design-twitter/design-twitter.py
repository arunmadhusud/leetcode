class Twitter:

    def __init__(self):
        self.followMap = defaultdict(set)
        self.tweetMap  = defaultdict(list) 
        self.time = 0
        

    def postTweet(self, userId: int, tweetId: int) -> None:
        self.tweetMap[userId].append([self.time,tweetId])
        self.time+=1
        

    def getNewsFeed(self, userId: int) -> List[int]:
        pq = []
        tweets = []
        for tweet in self.tweetMap[userId]:
            heapq.heappush(pq,tweet)
            if len(pq)>10: heapq.heappop(pq)
        for followee in self.followMap[userId]:
            for tweet in self.tweetMap[followee]:
                heapq.heappush(pq,tweet)
                if len(pq)>10: heapq.heappop(pq)
        while pq and len(tweets) < 10:
            tweets.append(heapq.heappop(pq)[1])
        
        tweets.reverse()
        return tweets             

    def follow(self, followerId: int, followeeId: int) -> None:
        self.followMap[followerId].add(followeeId)
        

    def unfollow(self, followerId: int, followeeId: int) -> None:
        if followeeId in self.followMap[followerId]:
            self.followMap[followerId].remove(followeeId)
        


# Your Twitter object will be instantiated and called as such:
# obj = Twitter()
# obj.postTweet(userId,tweetId)
# param_2 = obj.getNewsFeed(userId)
# obj.follow(followerId,followeeId)
# obj.unfollow(followerId,followeeId)