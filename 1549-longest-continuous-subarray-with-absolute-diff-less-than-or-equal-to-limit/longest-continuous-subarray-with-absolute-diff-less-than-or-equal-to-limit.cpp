class Solution {
public:
    int longestSubarray(vector<int>& a, int limit) {
        int i=0,j;
        multiset<int>m;
        for (j=0;j<a.size();j++) {
            m.insert(a[j]);
            if (*m.rbegin()-*m.begin()>limit)m.erase(m.find(a[i++]));        
        }
        return j-i;
    }
};