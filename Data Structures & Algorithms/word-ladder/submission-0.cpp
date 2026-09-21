class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        int n=wordList.size();
        queue<pair<string,int>>q;
        unordered_set<string>st(wordList.begin(),wordList.end());
        q.push({beginWord,1});
        st.erase(beginWord);

        while(!q.empty()){
            string currword=q.front().first; 
            int steps=q.front().second;
            q.pop();

            if(currword==endWord)
            return steps;


            for(int i=0;i<currword.size();i++){
                char originalword=currword[i];
                for(char ch='a';ch<='z';ch++){
                    currword[i]=ch;

                    if(st.find(currword)!=st.end()){
                        st.erase(currword);
                        q.push({currword,steps+1});
                    }
                }
                currword[i]=originalword;

            }
                   }
                   return 0;
        
    }
};
