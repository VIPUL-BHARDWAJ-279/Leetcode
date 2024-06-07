class Solution {
public:
    string findRoot(string & s, unordered_map<string,int> & mp){
        string word="";
        for(int i=0;i<s.size();i++){
            word+=s[i];
            if(mp[word]>0)return word;
        }
        return s;
    }
    string replaceWords(vector<string>& dictionary, string sentence) {
        unordered_map<string,int> mp;
        for(auto s:dictionary)mp[s]++;

        vector<string> temp;
        string word="";

        for(int i=0;i<sentence.size();i++){
            if(sentence[i]!=' ')word+=sentence[i];
            else temp.push_back(word),word="";
        }
        temp.push_back(word);

        for(int i=0;i<temp.size();i++){
            string newWord=findRoot(temp[i],mp);
            temp[i]=newWord;
        }

        string ans="";
        for(int i=0;i<temp.size()-1;i++){
            ans+=temp[i];
            ans+=' ';
        }
        ans+=temp[temp.size()-1];

        return ans;



    }
};