class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        unordered_set<string> vis,wordListSet(wordList.begin(),wordList.end());
        string alphabet="abcdefghijklmnopqrstuvwxyz";
        queue<string> q;
        int level=0;
        
        vis.insert(beginWord);
        q.push(beginWord);

        while(!q.empty()){
            int siz=q.size();

            while(siz--){
                string word=q.front();
                q.pop();

                if(word==endWord)return level+1;

                for(char & ch:alphabet){
                    for(int i=0;i<word.size();i++){
                        
                        char original=word[i];
                        word[i]=ch;

                        if(wordListSet.find(word)!=wordListSet.end() && vis.find(word)==vis.end()){
                            vis.insert(word);
                            q.push(word);
                        }

                        word[i]=original;
                    }
                }
            }

            level++;
        }
        return 0;
    }
};