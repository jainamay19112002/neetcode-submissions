class Solution {
public:
    string foreignDictionary(vector<string>& words) {
        int n=words.size();

        vector<int>presentingraph(26,0);
        vector<int>indegree(26,0);
        vector<vector<int>>graph(26);

        for(auto it:words){
            for(auto ch:it){
                presentingraph[ch-'a']=1;
            }
        }

        for(int i=0;i<n-1;i++){
            string s1=words[i];
            string s2=words[i+1];
            int len=min(s1.size(),s2.size());
            bool found=false;


            for(int j=0;j<len;j++){
                if(s1[j]!=s2[j]){
                    int u=s1[j]-'a';
                    int v=s2[j]-'a';
                    graph[u].push_back(v);
                    indegree[v]++;
                    found=true;
                    break;
                }
            }

            if(!found && s1.size()>s2.size())
            return "";
        }

        queue<int>q;
        for(int i=0;i<26;i++){
            if(presentingraph[i] && indegree[i]==0){
                q.push(i);
            }
        }
        string ans="";

        while(!q.empty()){
            int node=q.front();
            q.pop();
            ans+=char(node+'a');

            for(int next:graph[node]){
                indegree[next]--;
                if(indegree[next]==0){
                    q.push(next);
                }
            }
        }

        int total=0;
        for(int i=0;i<26;i++){
            if(presentingraph[i])
            total++;
        }

        if(ans.size()!=total)
        return "";

        return ans;
        
    }
};
