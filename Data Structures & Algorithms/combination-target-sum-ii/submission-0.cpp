class Solution {
public:
    vector<vector<int>> ans;

    void solve(int idx, vector<int>& a, int target, vector<int>& temp) {
        if (target == 0) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < a.size(); i++) {
            if (i > idx && a[i] == a[i - 1]) continue;
            if (a[i] > target) break;

            temp.push_back(a[i]);
            solve(i + 1, a, target - a[i], temp);
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<int> temp;
        solve(0, candidates, target, temp);
        return ans;
    }
};