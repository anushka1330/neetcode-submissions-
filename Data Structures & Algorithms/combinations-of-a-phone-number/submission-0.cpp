class Solution {
public:
    vector<string> ans;
    vector<string> mp = {"", "", "abc", "def", "ghi", "jkl",
                         "mno", "pqrs", "tuv", "wxyz"};

    void solve(int idx, string &digits, string temp) {
        if (idx == digits.size()) {
            ans.push_back(temp);
            return;
        }

        string s = mp[digits[idx] - '0'];

        for (char c : s) {
            solve(idx + 1, digits, temp + c);
        }
    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};

        solve(0, digits, "");
        return ans;
    }
};