class Solution {
public:
    int minMutation(string startGene, string endGene, vector<string>& bank) {
        ios_base::sync_with_stdio(false),cin.tie(NULL),cout.tie(NULL);

        unordered_set<string> vis,bankSet(bank.begin(),bank.end());
        string geneChars="ACGT";
        queue<string> q;
        int level=0;
        
        vis.insert(startGene);
        q.push(startGene);

        while(!q.empty()){
            int siz=q.size();
            while(siz--){
                string gene=q.front();
                q.pop();
                if(gene==endGene)return level;
                for(char & ch:geneChars){
                    for(int i=0;i<8;i++){
                        char original=gene[i];
                        gene[i]=ch;
                        if(bankSet.find(gene)!=bankSet.end() && vis.find(gene)==vis.end()){
                            vis.insert(gene);
                            q.push(gene);
                        }
                        gene[i]=original;
                    }
                }
            }
            level++;
        }
        return -1;
    }
};