class Solution {
public:
    void fillFreq(string & s, int freq[26]){
        for(char & ch:s)freq[ch-'a']++;
    }
    vector<string> commonChars(vector<string>& words) {
        int freq[26]={0};
        vector<string> ans;
        fillFreq(words[0],freq);

        for(int i=1;i<words.size();i++){
            int temp[26]={0};
            fillFreq(words[i],temp);
            for(int j=0;j<26;j++)freq[j]=min(freq[j],temp[j]);
        }
        for(int i=0;i<26;i++){
            int num=freq[i];
            while(num--)ans.push_back(string(1,i+'a')); // Char to string method --> string(1,ch) <-- 1==lenght of char, ch =char
        }
        return ans;
    }
};