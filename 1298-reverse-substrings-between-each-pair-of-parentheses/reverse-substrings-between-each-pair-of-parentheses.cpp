class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> opened;
        string ans;
        for(int i=0;i<s.size();i++){
            if(s[i]=='(')opened.push(ans.size());
            else if(s[i]==')'){
                int siz=opened.top();
                opened.pop();
                reverse(ans.begin()+siz,ans.end());
            }
            else ans+=s[i];
        }
        return ans;
    }
};