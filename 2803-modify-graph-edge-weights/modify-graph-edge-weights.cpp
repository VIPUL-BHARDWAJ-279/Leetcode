class Solution {
public:
    vector<vector<int>> modifiedGraphEdges(int n, vector<vector<int>>& edges, int source, int destination, int target) {
        vector<vector<int> > adj(n, vector<int>(n, 0));
        for(int i = 0; i < edges.size(); i++){
            adj[edges[i][0]][edges[i][1]] = edges[i][2];
            adj[edges[i][1]][edges[i][0]] = edges[i][2];
            if(edges[i][2] == -1) edges[i][2] = target;
        }
        
        priority_queue<vector<int>, vector<vector<int> >, greater<vector<int> > > pq;
        vector<int> d(n, 1e9 + 1);
        vector<int> fixed(n, 0);
        pq.push({0,source});
        d[source] = 0;
        while(!pq.empty()){
            int c = pq.top()[1];
            pq.pop();
            if(fixed[c]) continue;
            fixed[c] = 1;
            for(int i = 0; i < n; i++){
                if(adj[c][i] > 0 && d[i] > adj[c][i] + d[c]){
                    d[i] = adj[c][i] + d[c];
                    pq.push({d[i], i});
                }
            }
        }
        if(d[destination] < target) return {};
        if(d[destination] == target) return edges;
        vector<int> dist(n, 1e9 + 1);
        fixed = vector<int>(n, 0);
        vector<int> parent(n, -1);
        pq.push({0,source});
        dist[source] = 0;
        int c;
        while(!pq.empty()){
            c = pq.top()[1];
            pq.pop();
            if(fixed[c]) continue;
            fixed[c] = 1;
            for(int i = 0; i < n; i++){
                if(adj[c][i] != 0 && dist[i] > abs(adj[c][i]) + dist[c]){
                    dist[i] = abs(adj[c][i]) + dist[c];
                    pq.push({dist[i], i});
                    parent[i] = c;
                }
            }
        }
        if(dist[destination] > target) return {};
        int x = destination;
        int y;
        int rem = target;
        int add;
        while(x != source){
            y = parent[x];
            if(adj[x][y] == -1) {
                adj[x][y] = 1;
                add = max(0, rem - d[y] - 1);
                adj[x][y] += add;
                adj[y][x] = adj[x][y];
                if(add != 0) break;
            }
            rem -= adj[x][y];
            x = y;
        }
        for(int i = 0; i < edges.size(); i++){
            if(adj[edges[i][0]][edges[i][1]] != -1) edges[i][2] =  adj[edges[i][0]][edges[i][1]];
        }
        return edges;
    }
};