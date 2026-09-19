class Solution {
public:
    void bfs(int start, vector<vector<int>>& graph,
             vector<int>& vis) {

        queue<int> q;

        q.push(start);
        vis[start] = 1;

        while(!q.empty()) {

            int node = q.front();
            q.pop();

            for(int next : graph[node]) {

                if(!vis[next]) {
                    vis[next] = 1;
                    q.push(next);
                }
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {
         vector<vector<int>> graph(n);

        // Build graph
        for(auto edge : edges) {

            int u = edge[0];
            int v = edge[1];

            graph[u].push_back(v);
            graph[v].push_back(u);
        }

        vector<int> vis(n, 0);

        int cnt = 0;

        for(int i = 0; i < n; i++) {

            if(!vis[i]) {

                cnt++;

                bfs(i, graph, vis);
            }
        }

        return cnt;

    }
};
