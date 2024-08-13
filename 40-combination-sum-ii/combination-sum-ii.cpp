class Solution {
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> result;
        sort(candidates.begin(), candidates.end());
        vector<int> tempList;
        backtrack(result, tempList, candidates, target, 0);
        return result;
    }

private:
    void backtrack(vector<vector<int>>& result, vector<int>& tempList, vector<int>& candidates, int remain, int start) {
        if (remain < 0) return;
        else if (remain == 0) result.push_back(tempList);
        else {
            for (int i = start; i < candidates.size(); i++) {
                if (i > start && candidates[i] == candidates[i - 1]) continue; // Here we skip duplicates
                tempList.push_back(candidates[i]);
                backtrack(result, tempList, candidates, remain - candidates[i], i + 1);
                tempList.pop_back();
            }
        }
    }
};
