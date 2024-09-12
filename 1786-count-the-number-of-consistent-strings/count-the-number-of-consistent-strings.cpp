class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        unordered_set<char>seti;
        int ans=0;
        for(int i=0;i<allowed.size();i++)seti.insert(allowed[i]);
        for(auto &word:words){
            for(int i=0;i<word.size();i++){
                if(seti.find(word[i])==seti.end())break;
                if(i==word.size()-1)ans++;
            }
        }
        return ans;
    }
};