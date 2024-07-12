class Solution {
public:
    string stringAfterPairsRemoval(string s,char a, char b){
        string st;
        for(auto ch:s){
            if(!st.empty() && st.back()==a && ch==b)st.pop_back();
            else st.push_back(ch);
        }
        return st;
    }

    int maximumGain(string s, int x, int y) {
        char a='a',b='b';
        if(x<y){
            swap(a,b);
            swap(x,y);
        }

        string s1=stringAfterPairsRemoval(s,a,b),s2=stringAfterPairsRemoval(s1,b,a);
        int n=s.size(),n1=s1.size(),n2=s2.size();
        int score=(n-n1)/2*x + (n1-n2)/2*y;
        return score;
    }
};