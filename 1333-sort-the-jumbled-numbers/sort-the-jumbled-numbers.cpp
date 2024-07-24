class Solution {
public:
    int convert(vector<int> &v, int n) {
        int ans = 0, i = 1;
        // Special case when n is 0 
        if (n == 0) return v[0];
        while (n) {
            int rem = n % 10;
            ans = ans + i * v[rem];
            n /= 10;
            i *= 10;
        }
        return ans;
    }
    
    vector<int> sortJumbled(vector<int>& m, vector<int>& num) {
        map<int, vector<int>> mp;
        int n = num.size();
        
        for (int i = 0; i < n; i++) {
            mp[convert(m, num[i])].push_back(num[i]);
        }
        n = 0;
        for (auto x : mp) {
            for (int i = 0; i < x.second.size(); i++) {
                num[n++] = x.second[i];
            }
        }
        return num;
    }
};