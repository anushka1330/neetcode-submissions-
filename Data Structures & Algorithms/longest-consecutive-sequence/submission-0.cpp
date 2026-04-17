class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int ans = 0;

        for (int x : s) {
            if (!s.count(x - 1)) {   // start
                int y = x;
                while (s.count(y)) y++;
                ans = max(ans, y - x);
            }
        }
        return ans;
    }
};
