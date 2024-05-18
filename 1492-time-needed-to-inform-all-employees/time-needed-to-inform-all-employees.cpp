#include<bits/stdc++.h>
class Solution {
public:
    void dfs(int boss,int sum, int & maxi, vector<int> & informTime, vector<vector<int>> & adj){
        if(informTime[boss]==0){
            maxi=max(maxi,sum);
            return;
        }
        sum+=informTime[boss];

        for(auto it:adj[boss])dfs(it,sum,maxi,informTime,adj);
    }
    int numOfMinutes(int n, int boss, vector<int>& manager, vector<int>& informTime) {
        ios_base::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
        int time=0,sum=0;
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++)if(manager[i]!=-1)adj[manager[i]].push_back(i);
        dfs(boss,sum,time,informTime,adj);
        // queue<vector<int>>q;
        // q.push({boss,0});
        // while(!q.empty()){
        //     int node=q.front()[0], steps=q.front()[1];
        //     q.pop();
        //     level[node]=steps;
        //     // time+=informTime[node];    
        //     for(auto it:adj[node]){
        //         q.push({it,steps+1});
        //     }
        // }
        // int lvlcnt=1;
        // for(int i=0;i<n-1;i++)if(level[i]!=level[i+1])lvlcnt++;

        // vector<vector<int>> levelAdj(lvlcnt);
        // for(int i=0;i<n;i++)levelAdj[level[i]].push_back(i);
        // for(int i=0;i<lvlcnt;i++){
        //     int maxi=0;
        //     for(int j=0;j<levelAdj[i].size();j++)maxi=max(maxi,informTime[levelAdj[i][j]]);
        //     time+=maxi;
        // }
        return time;
    }
};