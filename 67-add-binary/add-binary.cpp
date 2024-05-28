class Solution {
public:
    string addBinary(string a, string b) {
        int n=a.size(),m=b.size();
        int i=n-1,j=m-1;
        string ans="";
        char carry='0';
        while(i>=0 && j>=0){       
            if(carry=='0' && a[i]=='0' && b[j]=='0')ans+="0", carry='0';
            else if(carry=='0' && a[i]=='0' && b[j]=='1')ans+="1", carry='0';
            else if(carry=='0' && a[i]=='1' && b[j]=='0')ans+="1", carry='0';
            else if(carry=='0' && a[i]=='1' && b[j]=='1')ans+="0", carry='1';
            else if(carry=='1' && a[i]=='0' && b[j]=='0')ans+="1", carry='0';
            else if(carry=='1' && a[i]=='0' && b[j]=='1')ans+="0", carry='1';
            else if(carry=='1' && a[i]=='1' && b[j]=='0')ans+="0", carry='1';
            else if(carry=='1' && a[i]=='1' && b[j]=='1')ans+="1", carry='1';

            i--;
            j--;
        }
        while(i>=0){
            if(carry=='0' && a[i]=='0')ans+="0",carry='0';
            else if(carry=='0' && a[i]=='1')ans+="1",carry='0';
            else if(carry=='1' && a[i]=='0')ans+="1",carry='0';
            else if(carry=='1' && a[i]=='1')ans+="0",carry='1';

            i--;
        }
        while(j>=0){
            if(carry=='0' && b[j]=='0')ans+="0",carry='0';
            else if(carry=='0' && b[j]=='1')ans+="1",carry='0';
            else if(carry=='1' && b[j]=='0')ans+="1",carry='0';
            else if(carry=='1' && b[j]=='1')ans+="0",carry='1';

            j--;
        }
        if(carry=='1')ans+="1";
        reverse(ans.begin(), ans.end());
        return ans;
    }
};