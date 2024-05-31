class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n=numCourses;
        vector<vector<int>> adj(n,vector<int>(0));
        vector<int> indegrees(n);

        for(auto course:prerequisites){
            int pre_course=course[1], curr_course=course[0];
            adj[pre_course].push_back(curr_course);
            indegrees[curr_course]++;
        }
        
        queue<int> q;
        vector<int> topo;
        for(int i=0;i<n;i++){
            if(indegrees[i]==0)q.push(i);
        }

        while(!q.empty()){
            int node=q.front();q.pop();
            topo.push_back(node);

            for(auto it: adj[node]){
                indegrees[it]--;
                if(indegrees[it]==0)q.push(it);
            }
        }

        if(topo.size()==numCourses)return topo;
        else return {};
    }
};