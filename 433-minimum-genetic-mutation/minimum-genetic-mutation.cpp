class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);
        
        unordered_set<string> vis,bankSet(bank.begin(),bank.end());
        string geneChars="ACGT";
        queue<pair<string,int>> q;
        int level=0;
        
        vis.insert(startGene);
        q.push({startGene,0});

        while(!q.empty()){
            string gene=q.front().first;
            level=q.front().second;
            q.pop();
            for(char & ch:geneChars){
                for(int i=0;i<8;i++){
                    char original=gene[i];
                    gene[i]=ch;
                    if(bankSet.find(gene)!=bankSet.end() && vis.find(gene)==vis.end()){
                        if(gene==endGene)return level+1;
                        vis.insert(gene);
                        q.push({gene,level+1});
                    }
                    gene[i]=original;
                }
            }
        }
        return -1;
    }
};