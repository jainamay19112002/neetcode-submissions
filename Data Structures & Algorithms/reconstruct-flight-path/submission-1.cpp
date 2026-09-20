class Solution {
public:
     map<string,multiset<string>>graph;
      vector<string>finalans;

      void dfs(string currairport) {
          while(!graph[currairport].empty()) {
              string next = *graph[currairport].begin();
              graph[currairport].erase(graph[currairport].begin());
              dfs(next);
          }
          finalans.push_back(currairport);
      }

      vector<string> findItinerary(vector<vector<string>>& tickets) {
          for(auto it:tickets) {
              graph[it[0]].insert(it[1]);
          }
          dfs("JFK");
          reverse(finalans.begin(),finalans.end());
          return finalans;
      }
};
