class Solution {
public:
    vector<vector<string>> ans;

    bool isPal(string s, int l, int r) {
        while (l < r) {
            if (s[l++] != s[r--]) return false;
        }
        return true;
    }

    void solve(int idx, string& s, vector<string>& temp) {
        if (idx == s.size()) {
            ans.push_back(temp);
            return;
        }

        for (int i = idx; i < s.size(); i++) {
            if (isPal(s, idx, i)) {
                temp.push_back(s.substr(idx, i - idx + 1));
                solve(i + 1, s, temp);
                temp.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        vector<string> temp;
        solve(0, s, temp);
        return ans;
    }
};