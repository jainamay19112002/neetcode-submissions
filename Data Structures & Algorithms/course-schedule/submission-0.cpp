class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adjli(numCourses);
        for(auto it:prerequisites){
            int first=it[0];
            int second=it[1];
            adjli[second].push_back(first);
        }

        vector<int>indegree(numCourses,0);
        for(int i=0;i<numCourses;i++){
        for(auto neigh:adjli[i]){
            indegree[neigh]++;
        }
        }

        queue<int>q;
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
            q.push(i);
        }

        int cntcourses=0;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            cntcourses++;

            for(auto it:adjli[node]){
                indegree[it]--;
                if(indegree[it]==0)
                q.push(it);
            }
        }
        if(cntcourses==numCourses)
        return true;
        else
        return false;
        
    }
};
