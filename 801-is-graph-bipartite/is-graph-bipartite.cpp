class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        std::queue<int> q;
        std::vector<int> bp(graph.size(),-1);
        int c = 0;

        for (int i = 0; i < graph.size(); i++ ){
            if(bp[i] ==-1){
                c = 0;
                q.push(i);
                bp[i] = c;
                while(!q.empty()){
                    int curr = q.front();
                    q.pop();
                    for(int elem : graph[curr]){
                        if(bp[elem]==-1){
                            q.push(elem);
                            bp[elem] = 1 - bp[curr];
                        }
                        else if (bp[elem]!= -1 && bp[elem]==bp[curr]) return false;
                    }
                }
            }
        }

        return true;
        
    }
};