class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size(),s=0,e=n-1;
        int total=skill[s]+skill[e];
        long long ans=skill[s]*skill[e];
        s++;
        e--;
        while(s<e){
            int sum=skill[s]+skill[e];
            if(sum!=total)return -1;
            ans+=skill[s]*skill[e];
            s++;
            e--;
        }
        return ans;

    }
};