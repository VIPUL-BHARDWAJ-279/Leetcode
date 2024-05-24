class Solution {
public:
    void setFreq(string &str, vector<int> &v){
        for (auto ch : str)v[ch-'a']++;     
    }

    bool isDeductable(vector<int> &wordFreq, vector<int> &freq){
        for (int i=0; i<26; i++)if (wordFreq[i]>freq[i])return false;
        return true;
    }

    int solve(vector<int>& score, vector<vector<int>> &wordFreq, vector<int> &freq, int i){
        if (i>=wordFreq.size()) return 0;
        int ans = 0;

 
        if (isDeductable(wordFreq[i],freq)){
            int temp=0;
            for (int j=0; j<26; j++){
                freq[j] -= wordFreq[i][j];
                temp+= wordFreq[i][j] * score[j];   
            }

            ans = temp + solve(score,wordFreq,freq,i+1);

            for (int j=0; j<26; j++)
                freq[j] += wordFreq[i][j];
        }

        ans = max(ans,solve(score,wordFreq,freq,i+1));

        return ans;
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        vector<vector<int>> wordFreq(words.size(),vector<int>(26));
        for (int i=0; i<words.size(); i++)setFreq(words[i],wordFreq[i]);
        vector<int> freq(26);
        for (auto ch : letters)freq[ch-'a']++;

        return solve(score,wordFreq,freq,0);
    }
};