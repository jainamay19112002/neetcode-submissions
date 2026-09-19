class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
                vector<vector<int>>adjl(numCourses);
        for(auto it:prerequisites){
            adjl[it[1]].push_back(it[0]);
        }

        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
            for(auto j:adjl[i]){
                indegree[j]++;
            }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int>topoans;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            topoans.push_back(node);

            for(auto j:adjl[node]){
                indegree[j]--;
                if(indegree[j]==0)
                q.push(j);
            }
        }
        if(topoans.size()!=numCourses)
        return {};

        return topoans;

        
    }
};
