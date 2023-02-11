class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        //store redEdges and blueEdges in a data structure
        //node neighbour color

        vector<vector<pair<int, int>>> adj(n);
        for(auto redEdge : redEdges){
            adj[redEdge[0]].push_back({redEdge[1], 0});
        }
        for(auto blueEdge : blueEdges){
            adj[blueEdge[0]].push_back({blueEdge[1], 1});
        }

        vector<int> answer(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2));  //neighbour color
        queue<vector<int>> q;

        q.push({0, 0, -1});                   //initial node steps color
        visited[0][1] = visited[0][0] = true;
        answer[0] = 0;

        while(!q.empty()){
            auto front = q.front();
            int node = front[0], steps = front[1], prevColor = front[2];
            q.pop();

            for(auto [neighbour, color] : adj[node]){
                if(!visited[neighbour][color] and color != prevColor){
                    visited[neighbour][color] = true;
                    q.push({neighbour, 1 + steps, color});
                    if(answer[neighbour] == -1) answer[neighbour] = 1 + steps;
                }
            }
        }
        return answer;
    }
};