class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        
        for(int i = 0; i < prerequisites.size(); i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }
        std::vector<int> indegree(numCourses,0);
        for(int i = 0; i < prerequisites.size(); i++){
            indegree[prerequisites[i][1]]++;
        }

        std::queue<int> q;
        for(int i = 0; i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        
        int count=0;
        while(!q.empty()){
            int curr = q.front();
            q.pop();
            for (int elem : adj[curr]){
                indegree[elem]--;
                if(indegree[elem]==0) q.push(elem);
            }
            count++;
        }

        return count==numCourses;

        
    }
};