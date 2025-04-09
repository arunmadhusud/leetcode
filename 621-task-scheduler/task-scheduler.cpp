class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        std::unordered_map<char,int> freq;
        for (char elem : tasks) freq[elem]++;

        std::priority_queue<std::pair<int,char>> pq;
        for (const auto& [elem,count] : freq) pq.push({count,elem});

        std::queue<std::pair<int,std::pair<int,char>>> q;
        int time = 0;

        while (!pq.empty() || !q.empty()) {
            time++;

            // FIXED: Bring back all tasks ready at this time
            while (!q.empty() && q.front().first == time) {
                pq.push(q.front().second);
                q.pop();
            }

            if (!pq.empty()) {
                auto [count, elem] = pq.top();
                pq.pop();
                if (count - 1 > 0) {
                    q.push({time + n + 1, {count - 1, elem}});
                }
            }
        }

        return time;
    }
};
